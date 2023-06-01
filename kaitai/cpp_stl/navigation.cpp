// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "navigation.h"

navigation_t::navigation_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::_read() {
}

navigation_t::~navigation_t() {
    _clean_up();
}

void navigation_t::_clean_up() {
}

navigation_t::msg_pos_llh_dep_a_t::msg_pos_llh_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_pos_llh_dep_a_t::_read() {
    m_tow = m__io->read_u4le();
    m_lat = m__io->read_f8le();
    m_lon = m__io->read_f8le();
    m_height = m__io->read_f8le();
    m_h_accuracy = m__io->read_u2le();
    m_v_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_pos_llh_dep_a_t::~msg_pos_llh_dep_a_t() {
    _clean_up();
}

void navigation_t::msg_pos_llh_dep_a_t::_clean_up() {
}

navigation_t::msg_protection_level_dep_a_t::msg_protection_level_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_protection_level_dep_a_t::_read() {
    m_tow = m__io->read_u4le();
    m_vpl = m__io->read_u2le();
    m_hpl = m__io->read_u2le();
    m_lat = m__io->read_f8le();
    m_lon = m__io->read_f8le();
    m_height = m__io->read_f8le();
    m_flags = m__io->read_u1();
}

navigation_t::msg_protection_level_dep_a_t::~msg_protection_level_dep_a_t() {
    _clean_up();
}

void navigation_t::msg_protection_level_dep_a_t::_clean_up() {
}

navigation_t::msg_pos_llh_cov_t::msg_pos_llh_cov_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_pos_llh_cov_t::_read() {
    m_tow = m__io->read_u4le();
    m_lat = m__io->read_f8le();
    m_lon = m__io->read_f8le();
    m_height = m__io->read_f8le();
    m_cov_n_n = m__io->read_f4le();
    m_cov_n_e = m__io->read_f4le();
    m_cov_n_d = m__io->read_f4le();
    m_cov_e_e = m__io->read_f4le();
    m_cov_e_d = m__io->read_f4le();
    m_cov_d_d = m__io->read_f4le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_pos_llh_cov_t::~msg_pos_llh_cov_t() {
    _clean_up();
}

void navigation_t::msg_pos_llh_cov_t::_clean_up() {
}

navigation_t::msg_vel_ned_dep_a_t::msg_vel_ned_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_vel_ned_dep_a_t::_read() {
    m_tow = m__io->read_u4le();
    m_n = m__io->read_s4le();
    m_e = m__io->read_s4le();
    m_d = m__io->read_s4le();
    m_h_accuracy = m__io->read_u2le();
    m_v_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_vel_ned_dep_a_t::~msg_vel_ned_dep_a_t() {
    _clean_up();
}

void navigation_t::msg_vel_ned_dep_a_t::_clean_up() {
}

navigation_t::msg_vel_ned_cov_t::msg_vel_ned_cov_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_vel_ned_cov_t::_read() {
    m_tow = m__io->read_u4le();
    m_n = m__io->read_s4le();
    m_e = m__io->read_s4le();
    m_d = m__io->read_s4le();
    m_cov_n_n = m__io->read_f4le();
    m_cov_n_e = m__io->read_f4le();
    m_cov_n_d = m__io->read_f4le();
    m_cov_e_e = m__io->read_f4le();
    m_cov_e_d = m__io->read_f4le();
    m_cov_d_d = m__io->read_f4le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_vel_ned_cov_t::~msg_vel_ned_cov_t() {
    _clean_up();
}

void navigation_t::msg_vel_ned_cov_t::_clean_up() {
}

navigation_t::msg_utc_time_t::msg_utc_time_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_utc_time_t::_read() {
    m_flags = m__io->read_u1();
    m_tow = m__io->read_u4le();
    m_year = m__io->read_u2le();
    m_month = m__io->read_u1();
    m_day = m__io->read_u1();
    m_hours = m__io->read_u1();
    m_minutes = m__io->read_u1();
    m_seconds = m__io->read_u1();
    m_ns = m__io->read_u4le();
}

navigation_t::msg_utc_time_t::~msg_utc_time_t() {
    _clean_up();
}

void navigation_t::msg_utc_time_t::_clean_up() {
}

navigation_t::msg_pos_ecef_cov_gnss_t::msg_pos_ecef_cov_gnss_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_pos_ecef_cov_gnss_t::_read() {
    m_tow = m__io->read_u4le();
    m_x = m__io->read_f8le();
    m_y = m__io->read_f8le();
    m_z = m__io->read_f8le();
    m_cov_x_x = m__io->read_f4le();
    m_cov_x_y = m__io->read_f4le();
    m_cov_x_z = m__io->read_f4le();
    m_cov_y_y = m__io->read_f4le();
    m_cov_y_z = m__io->read_f4le();
    m_cov_z_z = m__io->read_f4le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_pos_ecef_cov_gnss_t::~msg_pos_ecef_cov_gnss_t() {
    _clean_up();
}

void navigation_t::msg_pos_ecef_cov_gnss_t::_clean_up() {
}

navigation_t::msg_vel_ned_gnss_t::msg_vel_ned_gnss_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_vel_ned_gnss_t::_read() {
    m_tow = m__io->read_u4le();
    m_n = m__io->read_s4le();
    m_e = m__io->read_s4le();
    m_d = m__io->read_s4le();
    m_h_accuracy = m__io->read_u2le();
    m_v_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_vel_ned_gnss_t::~msg_vel_ned_gnss_t() {
    _clean_up();
}

void navigation_t::msg_vel_ned_gnss_t::_clean_up() {
}

navigation_t::msg_vel_ned_cov_gnss_t::msg_vel_ned_cov_gnss_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_vel_ned_cov_gnss_t::_read() {
    m_tow = m__io->read_u4le();
    m_n = m__io->read_s4le();
    m_e = m__io->read_s4le();
    m_d = m__io->read_s4le();
    m_cov_n_n = m__io->read_f4le();
    m_cov_n_e = m__io->read_f4le();
    m_cov_n_d = m__io->read_f4le();
    m_cov_e_e = m__io->read_f4le();
    m_cov_e_d = m__io->read_f4le();
    m_cov_d_d = m__io->read_f4le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_vel_ned_cov_gnss_t::~msg_vel_ned_cov_gnss_t() {
    _clean_up();
}

void navigation_t::msg_vel_ned_cov_gnss_t::_clean_up() {
}

navigation_t::msg_baseline_ned_dep_a_t::msg_baseline_ned_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_baseline_ned_dep_a_t::_read() {
    m_tow = m__io->read_u4le();
    m_n = m__io->read_s4le();
    m_e = m__io->read_s4le();
    m_d = m__io->read_s4le();
    m_h_accuracy = m__io->read_u2le();
    m_v_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_baseline_ned_dep_a_t::~msg_baseline_ned_dep_a_t() {
    _clean_up();
}

void navigation_t::msg_baseline_ned_dep_a_t::_clean_up() {
}

navigation_t::msg_vel_ecef_dep_a_t::msg_vel_ecef_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_vel_ecef_dep_a_t::_read() {
    m_tow = m__io->read_u4le();
    m_x = m__io->read_s4le();
    m_y = m__io->read_s4le();
    m_z = m__io->read_s4le();
    m_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_vel_ecef_dep_a_t::~msg_vel_ecef_dep_a_t() {
    _clean_up();
}

void navigation_t::msg_vel_ecef_dep_a_t::_clean_up() {
}

navigation_t::msg_reference_frame_param_t::msg_reference_frame_param_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_reference_frame_param_t::_read() {
    m_ssr_iod = m__io->read_u1();
    m_sn = kaitai::kstream::bytes_to_str(m__io->read_bytes(32), std::string("ascii"));
    m_tn = kaitai::kstream::bytes_to_str(m__io->read_bytes(32), std::string("ascii"));
    m_sin = m__io->read_u1();
    m_utn = m__io->read_u2le();
    m_re_t0 = m__io->read_u2le();
    m_delta_x0 = m__io->read_s4le();
    m_delta_y0 = m__io->read_s4le();
    m_delta_z0 = m__io->read_s4le();
    m_theta_01 = m__io->read_s4le();
    m_theta_02 = m__io->read_s4le();
    m_theta_03 = m__io->read_s4le();
    m_scale = m__io->read_s4le();
    m_dot_delta_x0 = m__io->read_s4le();
    m_dot_delta_y0 = m__io->read_s4le();
    m_dot_delta_z0 = m__io->read_s4le();
    m_dot_theta_01 = m__io->read_s4le();
    m_dot_theta_02 = m__io->read_s4le();
    m_dot_theta_03 = m__io->read_s4le();
    m_dot_scale = m__io->read_s2le();
}

navigation_t::msg_reference_frame_param_t::~msg_reference_frame_param_t() {
    _clean_up();
}

void navigation_t::msg_reference_frame_param_t::_clean_up() {
}

navigation_t::msg_pose_relative_t::msg_pose_relative_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_trans = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_pose_relative_t::_read() {
    m_tow = m__io->read_u4le();
    m_sensor_id = m__io->read_u1();
    m_timestamp_1 = m__io->read_u4le();
    m_timestamp_2 = m__io->read_u4le();
    m_trans = new std::vector<int32_t>();
    const int l_trans = 3;
    for (int i = 0; i < l_trans; i++) {
        m_trans->push_back(m__io->read_s4le());
    }
    m_w = m__io->read_s4le();
    m_x = m__io->read_s4le();
    m_y = m__io->read_s4le();
    m_z = m__io->read_s4le();
    m_cov_r_x_x = m__io->read_f4le();
    m_cov_r_x_y = m__io->read_f4le();
    m_cov_r_x_z = m__io->read_f4le();
    m_cov_r_y_y = m__io->read_f4le();
    m_cov_r_y_z = m__io->read_f4le();
    m_cov_r_z_z = m__io->read_f4le();
    m_cov_c_x_x = m__io->read_f4le();
    m_cov_c_x_y = m__io->read_f4le();
    m_cov_c_x_z = m__io->read_f4le();
    m_cov_c_y_y = m__io->read_f4le();
    m_cov_c_y_z = m__io->read_f4le();
    m_cov_c_z_z = m__io->read_f4le();
    m_flags = m__io->read_u1();
}

navigation_t::msg_pose_relative_t::~msg_pose_relative_t() {
    _clean_up();
}

void navigation_t::msg_pose_relative_t::_clean_up() {
    if (m_trans) {
        delete m_trans; m_trans = 0;
    }
}

navigation_t::msg_vel_ecef_cov_t::msg_vel_ecef_cov_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_vel_ecef_cov_t::_read() {
    m_tow = m__io->read_u4le();
    m_x = m__io->read_s4le();
    m_y = m__io->read_s4le();
    m_z = m__io->read_s4le();
    m_cov_x_x = m__io->read_f4le();
    m_cov_x_y = m__io->read_f4le();
    m_cov_x_z = m__io->read_f4le();
    m_cov_y_y = m__io->read_f4le();
    m_cov_y_z = m__io->read_f4le();
    m_cov_z_z = m__io->read_f4le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_vel_ecef_cov_t::~msg_vel_ecef_cov_t() {
    _clean_up();
}

void navigation_t::msg_vel_ecef_cov_t::_clean_up() {
}

navigation_t::msg_vel_body_t::msg_vel_body_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_vel_body_t::_read() {
    m_tow = m__io->read_u4le();
    m_x = m__io->read_s4le();
    m_y = m__io->read_s4le();
    m_z = m__io->read_s4le();
    m_cov_x_x = m__io->read_f4le();
    m_cov_x_y = m__io->read_f4le();
    m_cov_x_z = m__io->read_f4le();
    m_cov_y_y = m__io->read_f4le();
    m_cov_y_z = m__io->read_f4le();
    m_cov_z_z = m__io->read_f4le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_vel_body_t::~msg_vel_body_t() {
    _clean_up();
}

void navigation_t::msg_vel_body_t::_clean_up() {
}

navigation_t::msg_vel_ecef_gnss_t::msg_vel_ecef_gnss_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_vel_ecef_gnss_t::_read() {
    m_tow = m__io->read_u4le();
    m_x = m__io->read_s4le();
    m_y = m__io->read_s4le();
    m_z = m__io->read_s4le();
    m_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_vel_ecef_gnss_t::~msg_vel_ecef_gnss_t() {
    _clean_up();
}

void navigation_t::msg_vel_ecef_gnss_t::_clean_up() {
}

navigation_t::msg_vel_ecef_t::msg_vel_ecef_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_vel_ecef_t::_read() {
    m_tow = m__io->read_u4le();
    m_x = m__io->read_s4le();
    m_y = m__io->read_s4le();
    m_z = m__io->read_s4le();
    m_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_vel_ecef_t::~msg_vel_ecef_t() {
    _clean_up();
}

void navigation_t::msg_vel_ecef_t::_clean_up() {
}

navigation_t::msg_pos_llh_cov_gnss_t::msg_pos_llh_cov_gnss_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_pos_llh_cov_gnss_t::_read() {
    m_tow = m__io->read_u4le();
    m_lat = m__io->read_f8le();
    m_lon = m__io->read_f8le();
    m_height = m__io->read_f8le();
    m_cov_n_n = m__io->read_f4le();
    m_cov_n_e = m__io->read_f4le();
    m_cov_n_d = m__io->read_f4le();
    m_cov_e_e = m__io->read_f4le();
    m_cov_e_d = m__io->read_f4le();
    m_cov_d_d = m__io->read_f4le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_pos_llh_cov_gnss_t::~msg_pos_llh_cov_gnss_t() {
    _clean_up();
}

void navigation_t::msg_pos_llh_cov_gnss_t::_clean_up() {
}

navigation_t::msg_baseline_ecef_t::msg_baseline_ecef_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_baseline_ecef_t::_read() {
    m_tow = m__io->read_u4le();
    m_x = m__io->read_s4le();
    m_y = m__io->read_s4le();
    m_z = m__io->read_s4le();
    m_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_baseline_ecef_t::~msg_baseline_ecef_t() {
    _clean_up();
}

void navigation_t::msg_baseline_ecef_t::_clean_up() {
}

navigation_t::msg_dops_dep_a_t::msg_dops_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_dops_dep_a_t::_read() {
    m_tow = m__io->read_u4le();
    m_gdop = m__io->read_u2le();
    m_pdop = m__io->read_u2le();
    m_tdop = m__io->read_u2le();
    m_hdop = m__io->read_u2le();
    m_vdop = m__io->read_u2le();
}

navigation_t::msg_dops_dep_a_t::~msg_dops_dep_a_t() {
    _clean_up();
}

void navigation_t::msg_dops_dep_a_t::_clean_up() {
}

navigation_t::msg_pos_ecef_t::msg_pos_ecef_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_pos_ecef_t::_read() {
    m_tow = m__io->read_u4le();
    m_x = m__io->read_f8le();
    m_y = m__io->read_f8le();
    m_z = m__io->read_f8le();
    m_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_pos_ecef_t::~msg_pos_ecef_t() {
    _clean_up();
}

void navigation_t::msg_pos_ecef_t::_clean_up() {
}

navigation_t::msg_age_corrections_t::msg_age_corrections_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_age_corrections_t::_read() {
    m_tow = m__io->read_u4le();
    m_age = m__io->read_u2le();
}

navigation_t::msg_age_corrections_t::~msg_age_corrections_t() {
    _clean_up();
}

void navigation_t::msg_age_corrections_t::_clean_up() {
}

navigation_t::msg_vel_ecef_cov_gnss_t::msg_vel_ecef_cov_gnss_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_vel_ecef_cov_gnss_t::_read() {
    m_tow = m__io->read_u4le();
    m_x = m__io->read_s4le();
    m_y = m__io->read_s4le();
    m_z = m__io->read_s4le();
    m_cov_x_x = m__io->read_f4le();
    m_cov_x_y = m__io->read_f4le();
    m_cov_x_z = m__io->read_f4le();
    m_cov_y_y = m__io->read_f4le();
    m_cov_y_z = m__io->read_f4le();
    m_cov_z_z = m__io->read_f4le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_vel_ecef_cov_gnss_t::~msg_vel_ecef_cov_gnss_t() {
    _clean_up();
}

void navigation_t::msg_vel_ecef_cov_gnss_t::_clean_up() {
}

navigation_t::msg_protection_level_t::msg_protection_level_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_protection_level_t::_read() {
    m_tow = m__io->read_u4le();
    m_wn = m__io->read_s2le();
    m_hpl = m__io->read_u2le();
    m_vpl = m__io->read_u2le();
    m_atpl = m__io->read_u2le();
    m_ctpl = m__io->read_u2le();
    m_hvpl = m__io->read_u2le();
    m_vvpl = m__io->read_u2le();
    m_hopl = m__io->read_u2le();
    m_popl = m__io->read_u2le();
    m_ropl = m__io->read_u2le();
    m_lat = m__io->read_f8le();
    m_lon = m__io->read_f8le();
    m_height = m__io->read_f8le();
    m_v_x = m__io->read_s4le();
    m_v_y = m__io->read_s4le();
    m_v_z = m__io->read_s4le();
    m_roll = m__io->read_s4le();
    m_pitch = m__io->read_s4le();
    m_heading = m__io->read_s4le();
    m_flags = m__io->read_u4le();
}

navigation_t::msg_protection_level_t::~msg_protection_level_t() {
    _clean_up();
}

void navigation_t::msg_protection_level_t::_clean_up() {
}

navigation_t::msg_pos_ecef_cov_t::msg_pos_ecef_cov_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_pos_ecef_cov_t::_read() {
    m_tow = m__io->read_u4le();
    m_x = m__io->read_f8le();
    m_y = m__io->read_f8le();
    m_z = m__io->read_f8le();
    m_cov_x_x = m__io->read_f4le();
    m_cov_x_y = m__io->read_f4le();
    m_cov_x_z = m__io->read_f4le();
    m_cov_y_y = m__io->read_f4le();
    m_cov_y_z = m__io->read_f4le();
    m_cov_z_z = m__io->read_f4le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_pos_ecef_cov_t::~msg_pos_ecef_cov_t() {
    _clean_up();
}

void navigation_t::msg_pos_ecef_cov_t::_clean_up() {
}

navigation_t::msg_pos_ecef_gnss_t::msg_pos_ecef_gnss_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_pos_ecef_gnss_t::_read() {
    m_tow = m__io->read_u4le();
    m_x = m__io->read_f8le();
    m_y = m__io->read_f8le();
    m_z = m__io->read_f8le();
    m_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_pos_ecef_gnss_t::~msg_pos_ecef_gnss_t() {
    _clean_up();
}

void navigation_t::msg_pos_ecef_gnss_t::_clean_up() {
}

navigation_t::msg_vel_ned_t::msg_vel_ned_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_vel_ned_t::_read() {
    m_tow = m__io->read_u4le();
    m_n = m__io->read_s4le();
    m_e = m__io->read_s4le();
    m_d = m__io->read_s4le();
    m_h_accuracy = m__io->read_u2le();
    m_v_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_vel_ned_t::~msg_vel_ned_t() {
    _clean_up();
}

void navigation_t::msg_vel_ned_t::_clean_up() {
}

navigation_t::msg_utc_leap_second_t::msg_utc_leap_second_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_utc_leap_second_t::_read() {
    m_reserved_0 = m__io->read_s2le();
    m_reserved_1 = m__io->read_s2le();
    m_reserved_2 = m__io->read_s1();
    m_count_before = m__io->read_s1();
    m_reserved_3 = m__io->read_u2le();
    m_reserved_4 = m__io->read_u2le();
    m_ref_wn = m__io->read_u2le();
    m_ref_dn = m__io->read_u1();
    m_count_after = m__io->read_s1();
}

navigation_t::msg_utc_leap_second_t::~msg_utc_leap_second_t() {
    _clean_up();
}

void navigation_t::msg_utc_leap_second_t::_clean_up() {
}

navigation_t::msg_gps_time_dep_a_t::msg_gps_time_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_gps_time_dep_a_t::_read() {
    m_wn = m__io->read_u2le();
    m_tow = m__io->read_u4le();
    m_ns_residual = m__io->read_s4le();
    m_flags = m__io->read_u1();
}

navigation_t::msg_gps_time_dep_a_t::~msg_gps_time_dep_a_t() {
    _clean_up();
}

void navigation_t::msg_gps_time_dep_a_t::_clean_up() {
}

navigation_t::msg_pos_llh_gnss_t::msg_pos_llh_gnss_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_pos_llh_gnss_t::_read() {
    m_tow = m__io->read_u4le();
    m_lat = m__io->read_f8le();
    m_lon = m__io->read_f8le();
    m_height = m__io->read_f8le();
    m_h_accuracy = m__io->read_u2le();
    m_v_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_pos_llh_gnss_t::~msg_pos_llh_gnss_t() {
    _clean_up();
}

void navigation_t::msg_pos_llh_gnss_t::_clean_up() {
}

navigation_t::msg_utc_time_gnss_t::msg_utc_time_gnss_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_utc_time_gnss_t::_read() {
    m_flags = m__io->read_u1();
    m_tow = m__io->read_u4le();
    m_year = m__io->read_u2le();
    m_month = m__io->read_u1();
    m_day = m__io->read_u1();
    m_hours = m__io->read_u1();
    m_minutes = m__io->read_u1();
    m_seconds = m__io->read_u1();
    m_ns = m__io->read_u4le();
}

navigation_t::msg_utc_time_gnss_t::~msg_utc_time_gnss_t() {
    _clean_up();
}

void navigation_t::msg_utc_time_gnss_t::_clean_up() {
}

navigation_t::msg_vel_cog_t::msg_vel_cog_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_vel_cog_t::_read() {
    m_tow = m__io->read_u4le();
    m_cog = m__io->read_u4le();
    m_sog = m__io->read_u4le();
    m_v_up = m__io->read_s4le();
    m_cog_accuracy = m__io->read_u4le();
    m_sog_accuracy = m__io->read_u4le();
    m_v_up_accuracy = m__io->read_u4le();
    m_flags = m__io->read_u2le();
}

navigation_t::msg_vel_cog_t::~msg_vel_cog_t() {
    _clean_up();
}

void navigation_t::msg_vel_cog_t::_clean_up() {
}

navigation_t::msg_baseline_ned_t::msg_baseline_ned_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_baseline_ned_t::_read() {
    m_tow = m__io->read_u4le();
    m_n = m__io->read_s4le();
    m_e = m__io->read_s4le();
    m_d = m__io->read_s4le();
    m_h_accuracy = m__io->read_u2le();
    m_v_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_baseline_ned_t::~msg_baseline_ned_t() {
    _clean_up();
}

void navigation_t::msg_baseline_ned_t::_clean_up() {
}

navigation_t::msg_pos_llh_t::msg_pos_llh_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_pos_llh_t::_read() {
    m_tow = m__io->read_u4le();
    m_lat = m__io->read_f8le();
    m_lon = m__io->read_f8le();
    m_height = m__io->read_f8le();
    m_h_accuracy = m__io->read_u2le();
    m_v_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_pos_llh_t::~msg_pos_llh_t() {
    _clean_up();
}

void navigation_t::msg_pos_llh_t::_clean_up() {
}

navigation_t::msg_baseline_heading_dep_a_t::msg_baseline_heading_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_baseline_heading_dep_a_t::_read() {
    m_tow = m__io->read_u4le();
    m_heading = m__io->read_u4le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_baseline_heading_dep_a_t::~msg_baseline_heading_dep_a_t() {
    _clean_up();
}

void navigation_t::msg_baseline_heading_dep_a_t::_clean_up() {
}

navigation_t::msg_gps_time_gnss_t::msg_gps_time_gnss_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_gps_time_gnss_t::_read() {
    m_wn = m__io->read_u2le();
    m_tow = m__io->read_u4le();
    m_ns_residual = m__io->read_s4le();
    m_flags = m__io->read_u1();
}

navigation_t::msg_gps_time_gnss_t::~msg_gps_time_gnss_t() {
    _clean_up();
}

void navigation_t::msg_gps_time_gnss_t::_clean_up() {
}

navigation_t::msg_baseline_ecef_dep_a_t::msg_baseline_ecef_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_baseline_ecef_dep_a_t::_read() {
    m_tow = m__io->read_u4le();
    m_x = m__io->read_s4le();
    m_y = m__io->read_s4le();
    m_z = m__io->read_s4le();
    m_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_baseline_ecef_dep_a_t::~msg_baseline_ecef_dep_a_t() {
    _clean_up();
}

void navigation_t::msg_baseline_ecef_dep_a_t::_clean_up() {
}

navigation_t::msg_gps_time_t::msg_gps_time_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_gps_time_t::_read() {
    m_wn = m__io->read_u2le();
    m_tow = m__io->read_u4le();
    m_ns_residual = m__io->read_s4le();
    m_flags = m__io->read_u1();
}

navigation_t::msg_gps_time_t::~msg_gps_time_t() {
    _clean_up();
}

void navigation_t::msg_gps_time_t::_clean_up() {
}

navigation_t::msg_dops_t::msg_dops_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_dops_t::_read() {
    m_tow = m__io->read_u4le();
    m_gdop = m__io->read_u2le();
    m_pdop = m__io->read_u2le();
    m_tdop = m__io->read_u2le();
    m_hdop = m__io->read_u2le();
    m_vdop = m__io->read_u2le();
    m_flags = m__io->read_u1();
}

navigation_t::msg_dops_t::~msg_dops_t() {
    _clean_up();
}

void navigation_t::msg_dops_t::_clean_up() {
}

navigation_t::msg_pos_ecef_dep_a_t::msg_pos_ecef_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_pos_ecef_dep_a_t::_read() {
    m_tow = m__io->read_u4le();
    m_x = m__io->read_f8le();
    m_y = m__io->read_f8le();
    m_z = m__io->read_f8le();
    m_accuracy = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_pos_ecef_dep_a_t::~msg_pos_ecef_dep_a_t() {
    _clean_up();
}

void navigation_t::msg_pos_ecef_dep_a_t::_clean_up() {
}

navigation_t::estimated_horizontal_error_ellipse_t::estimated_horizontal_error_ellipse_t(kaitai::kstream* p__io, navigation_t::msg_pos_llh_acc_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::estimated_horizontal_error_ellipse_t::_read() {
    m_semi_major = m__io->read_f4le();
    m_semi_minor = m__io->read_f4le();
    m_orientation = m__io->read_f4le();
}

navigation_t::estimated_horizontal_error_ellipse_t::~estimated_horizontal_error_ellipse_t() {
    _clean_up();
}

void navigation_t::estimated_horizontal_error_ellipse_t::_clean_up() {
}

navigation_t::msg_pos_llh_acc_t::msg_pos_llh_acc_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, navigation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_h_ellipse = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void navigation_t::msg_pos_llh_acc_t::_read() {
    m_tow = m__io->read_u4le();
    m_lat = m__io->read_f8le();
    m_lon = m__io->read_f8le();
    m_height = m__io->read_f8le();
    m_orthometric_height = m__io->read_f8le();
    m_h_accuracy = m__io->read_f4le();
    m_v_accuracy = m__io->read_f4le();
    m_ct_accuracy = m__io->read_f4le();
    m_at_accuracy = m__io->read_f4le();
    m_h_ellipse = new estimated_horizontal_error_ellipse_t(m__io, this, m__root);
    m_confidence_and_geoid = m__io->read_u1();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

navigation_t::msg_pos_llh_acc_t::~msg_pos_llh_acc_t() {
    _clean_up();
}

void navigation_t::msg_pos_llh_acc_t::_clean_up() {
    if (m_h_ellipse) {
        delete m_h_ellipse; m_h_ellipse = 0;
    }
}
