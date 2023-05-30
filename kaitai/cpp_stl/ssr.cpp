// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "ssr.h"

ssr_t::ssr_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::_read() {
}

ssr_t::~ssr_t() {
    _clean_up();
}

void ssr_t::_clean_up() {
}

ssr_t::grid_definition_header_dep_a_t::grid_definition_header_dep_a_t(kaitai::kstream* p__io, ssr_t::msg_ssr_grid_definition_dep_a_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::grid_definition_header_dep_a_t::_read() {
    m_region_size_inverse = m__io->read_u1();
    m_area_width = m__io->read_u2le();
    m_lat_nw_corner_enc = m__io->read_u2le();
    m_lon_nw_corner_enc = m__io->read_u2le();
    m_num_msgs = m__io->read_u1();
    m_seq_num = m__io->read_u1();
}

ssr_t::grid_definition_header_dep_a_t::~grid_definition_header_dep_a_t() {
    _clean_up();
}

void ssr_t::grid_definition_header_dep_a_t::_clean_up() {
}

ssr_t::stec_residual_no_std_t::stec_residual_no_std_t(kaitai::kstream* p__io, ssr_t::msg_ssr_gridded_correction_no_std_dep_a_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sv_id = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::stec_residual_no_std_t::_read() {
    m_sv_id = new gnss_t::sv_id_t(m__io, this, m__root);
    m_residual = m__io->read_s2le();
}

ssr_t::stec_residual_no_std_t::~stec_residual_no_std_t() {
    _clean_up();
}

void ssr_t::stec_residual_no_std_t::_clean_up() {
    if (m_sv_id) {
        delete m_sv_id; m_sv_id = 0;
    }
}

ssr_t::tropospheric_delay_correction_no_std_t::tropospheric_delay_correction_no_std_t(kaitai::kstream* p__io, ssr_t::msg_ssr_gridded_correction_no_std_dep_a_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::tropospheric_delay_correction_no_std_t::_read() {
    m_hydro = m__io->read_s2le();
    m_wet = m__io->read_s1();
}

ssr_t::tropospheric_delay_correction_no_std_t::~tropospheric_delay_correction_no_std_t() {
    _clean_up();
}

void ssr_t::tropospheric_delay_correction_no_std_t::_clean_up() {
}

ssr_t::msg_ssr_stec_correction_dep_t::msg_ssr_stec_correction_dep_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_stec_sat_list = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_stec_correction_dep_t::_read() {
    m_header = new stec_header_t(m__io, this, m__root);
    m_stec_sat_list = new std::vector<stec_sat_element_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_stec_sat_list->push_back(new stec_sat_element_t(m__io, this, m__root));
            i++;
        }
    }
}

ssr_t::msg_ssr_stec_correction_dep_t::~msg_ssr_stec_correction_dep_t() {
    _clean_up();
}

void ssr_t::msg_ssr_stec_correction_dep_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_stec_sat_list) {
        for (std::vector<stec_sat_element_t*>::iterator it = m_stec_sat_list->begin(); it != m_stec_sat_list->end(); ++it) {
            delete *it;
        }
        delete m_stec_sat_list; m_stec_sat_list = 0;
    }
}

ssr_t::stec_sat_element_integrity_t::stec_sat_element_integrity_t(kaitai::kstream* p__io, ssr_t::msg_ssr_gridded_correction_bounds_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_stec_residual = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::stec_sat_element_integrity_t::_read() {
    m_stec_residual = new stec_residual_t(m__io, this, m__root);
    m_stec_bound_mu = m__io->read_u1();
    m_stec_bound_sig = m__io->read_u1();
    m_stec_bound_mu_dot = m__io->read_u1();
    m_stec_bound_sig_dot = m__io->read_u1();
}

ssr_t::stec_sat_element_integrity_t::~stec_sat_element_integrity_t() {
    _clean_up();
}

void ssr_t::stec_sat_element_integrity_t::_clean_up() {
    if (m_stec_residual) {
        delete m_stec_residual; m_stec_residual = 0;
    }
}

ssr_t::msg_ssr_orbit_clock_dep_a_t::msg_ssr_orbit_clock_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_time = 0;
    m_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_orbit_clock_dep_a_t::_read() {
    m_time = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_update_interval = m__io->read_u1();
    m_iod_ssr = m__io->read_u1();
    m_iod = m__io->read_u1();
    m_radial = m__io->read_s4le();
    m_along = m__io->read_s4le();
    m_cross = m__io->read_s4le();
    m_dot_radial = m__io->read_s4le();
    m_dot_along = m__io->read_s4le();
    m_dot_cross = m__io->read_s4le();
    m_c0 = m__io->read_s4le();
    m_c1 = m__io->read_s4le();
    m_c2 = m__io->read_s4le();
}

ssr_t::msg_ssr_orbit_clock_dep_a_t::~msg_ssr_orbit_clock_dep_a_t() {
    _clean_up();
}

void ssr_t::msg_ssr_orbit_clock_dep_a_t::_clean_up() {
    if (m_time) {
        delete m_time; m_time = 0;
    }
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

ssr_t::msg_ssr_stec_correction_t::msg_ssr_stec_correction_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_stec_sat_list = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_stec_correction_t::_read() {
    m_header = new bounds_header_t(m__io, this, m__root);
    m_ssr_iod_atmo = m__io->read_u1();
    m_tile_set_id = m__io->read_u2le();
    m_tile_id = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_stec_sat_list = new std::vector<stec_sat_element_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_stec_sat_list->push_back(new stec_sat_element_t(m__io, this, m__root));
            i++;
        }
    }
}

ssr_t::msg_ssr_stec_correction_t::~msg_ssr_stec_correction_t() {
    _clean_up();
}

void ssr_t::msg_ssr_stec_correction_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_stec_sat_list) {
        for (std::vector<stec_sat_element_t*>::iterator it = m_stec_sat_list->begin(); it != m_stec_sat_list->end(); ++it) {
            delete *it;
        }
        delete m_stec_sat_list; m_stec_sat_list = 0;
    }
}

ssr_t::msg_ssr_orbit_clock_t::msg_ssr_orbit_clock_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_time = 0;
    m_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_orbit_clock_t::_read() {
    m_time = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_update_interval = m__io->read_u1();
    m_iod_ssr = m__io->read_u1();
    m_iod = m__io->read_u4le();
    m_radial = m__io->read_s4le();
    m_along = m__io->read_s4le();
    m_cross = m__io->read_s4le();
    m_dot_radial = m__io->read_s4le();
    m_dot_along = m__io->read_s4le();
    m_dot_cross = m__io->read_s4le();
    m_c0 = m__io->read_s4le();
    m_c1 = m__io->read_s4le();
    m_c2 = m__io->read_s4le();
}

ssr_t::msg_ssr_orbit_clock_t::~msg_ssr_orbit_clock_t() {
    _clean_up();
}

void ssr_t::msg_ssr_orbit_clock_t::_clean_up() {
    if (m_time) {
        delete m_time; m_time = 0;
    }
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

ssr_t::bounds_header_t::bounds_header_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_time = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::bounds_header_t::_read() {
    m_time = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_num_msgs = m__io->read_u1();
    m_seq_num = m__io->read_u1();
    m_update_interval = m__io->read_u1();
    m_sol_id = m__io->read_u1();
}

ssr_t::bounds_header_t::~bounds_header_t() {
    _clean_up();
}

void ssr_t::bounds_header_t::_clean_up() {
    if (m_time) {
        delete m_time; m_time = 0;
    }
}

ssr_t::msg_ssr_gridded_correction_t::msg_ssr_gridded_correction_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_tropo_delay_correction = 0;
    m_stec_residuals = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_gridded_correction_t::_read() {
    m_header = new gridded_correction_header_t(m__io, this, m__root);
    m_index = m__io->read_u2le();
    m_tropo_delay_correction = new tropospheric_delay_correction_t(m__io, this, m__root);
    m_stec_residuals = new std::vector<stec_residual_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_stec_residuals->push_back(new stec_residual_t(m__io, this, m__root));
            i++;
        }
    }
}

ssr_t::msg_ssr_gridded_correction_t::~msg_ssr_gridded_correction_t() {
    _clean_up();
}

void ssr_t::msg_ssr_gridded_correction_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_tropo_delay_correction) {
        delete m_tropo_delay_correction; m_tropo_delay_correction = 0;
    }
    if (m_stec_residuals) {
        for (std::vector<stec_residual_t*>::iterator it = m_stec_residuals->begin(); it != m_stec_residuals->end(); ++it) {
            delete *it;
        }
        delete m_stec_residuals; m_stec_residuals = 0;
    }
}

ssr_t::stec_residual_t::stec_residual_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sv_id = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::stec_residual_t::_read() {
    m_sv_id = new gnss_t::sv_id_t(m__io, this, m__root);
    m_residual = m__io->read_s2le();
    m_stddev = m__io->read_u1();
}

ssr_t::stec_residual_t::~stec_residual_t() {
    _clean_up();
}

void ssr_t::stec_residual_t::_clean_up() {
    if (m_sv_id) {
        delete m_sv_id; m_sv_id = 0;
    }
}

ssr_t::code_phase_biases_sat_sig_t::code_phase_biases_sat_sig_t(kaitai::kstream* p__io, ssr_t::msg_ssr_code_phase_biases_bounds_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::code_phase_biases_sat_sig_t::_read() {
    m_sat_id = m__io->read_u1();
    m_signal_id = m__io->read_u1();
    m_code_bias_bound_mu = m__io->read_u1();
    m_code_bias_bound_sig = m__io->read_u1();
    m_phase_bias_bound_mu = m__io->read_u1();
    m_phase_bias_bound_sig = m__io->read_u1();
}

ssr_t::code_phase_biases_sat_sig_t::~code_phase_biases_sat_sig_t() {
    _clean_up();
}

void ssr_t::code_phase_biases_sat_sig_t::_clean_up() {
}

ssr_t::satellite_apc_t::satellite_apc_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sid = 0;
    m_pco = 0;
    m_pcv = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::satellite_apc_t::_read() {
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_sat_info = m__io->read_u1();
    m_svn = m__io->read_u2le();
    m_pco = new std::vector<int16_t>();
    const int l_pco = 3;
    for (int i = 0; i < l_pco; i++) {
        m_pco->push_back(m__io->read_s2le());
    }
    m_pcv = new std::vector<int8_t>();
    const int l_pcv = 21;
    for (int i = 0; i < l_pcv; i++) {
        m_pcv->push_back(m__io->read_s1());
    }
}

ssr_t::satellite_apc_t::~satellite_apc_t() {
    _clean_up();
}

void ssr_t::satellite_apc_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
    if (m_pco) {
        delete m_pco; m_pco = 0;
    }
    if (m_pcv) {
        delete m_pcv; m_pcv = 0;
    }
}

ssr_t::gridded_correction_header_t::gridded_correction_header_t(kaitai::kstream* p__io, ssr_t::msg_ssr_gridded_correction_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_time = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::gridded_correction_header_t::_read() {
    m_tile_set_id = m__io->read_u2le();
    m_tile_id = m__io->read_u2le();
    m_time = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_num_msgs = m__io->read_u2le();
    m_seq_num = m__io->read_u2le();
    m_update_interval = m__io->read_u1();
    m_iod_atmo = m__io->read_u1();
    m_tropo_quality_indicator = m__io->read_u1();
}

ssr_t::gridded_correction_header_t::~gridded_correction_header_t() {
    _clean_up();
}

void ssr_t::gridded_correction_header_t::_clean_up() {
    if (m_time) {
        delete m_time; m_time = 0;
    }
}

ssr_t::stec_sat_element_t::stec_sat_element_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sv_id = 0;
    m_stec_coeff = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::stec_sat_element_t::_read() {
    m_sv_id = new gnss_t::sv_id_t(m__io, this, m__root);
    m_stec_quality_indicator = m__io->read_u1();
    m_stec_coeff = new std::vector<int16_t>();
    const int l_stec_coeff = 4;
    for (int i = 0; i < l_stec_coeff; i++) {
        m_stec_coeff->push_back(m__io->read_s2le());
    }
}

ssr_t::stec_sat_element_t::~stec_sat_element_t() {
    _clean_up();
}

void ssr_t::stec_sat_element_t::_clean_up() {
    if (m_sv_id) {
        delete m_sv_id; m_sv_id = 0;
    }
    if (m_stec_coeff) {
        delete m_stec_coeff; m_stec_coeff = 0;
    }
}

ssr_t::stec_header_dep_a_t::stec_header_dep_a_t(kaitai::kstream* p__io, ssr_t::msg_ssr_stec_correction_dep_a_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_time = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::stec_header_dep_a_t::_read() {
    m_time = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_num_msgs = m__io->read_u1();
    m_seq_num = m__io->read_u1();
    m_update_interval = m__io->read_u1();
    m_iod_atmo = m__io->read_u1();
}

ssr_t::stec_header_dep_a_t::~stec_header_dep_a_t() {
    _clean_up();
}

void ssr_t::stec_header_dep_a_t::_clean_up() {
    if (m_time) {
        delete m_time; m_time = 0;
    }
}

ssr_t::stec_header_t::stec_header_t(kaitai::kstream* p__io, ssr_t::msg_ssr_stec_correction_dep_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_time = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::stec_header_t::_read() {
    m_tile_set_id = m__io->read_u2le();
    m_tile_id = m__io->read_u2le();
    m_time = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_num_msgs = m__io->read_u1();
    m_seq_num = m__io->read_u1();
    m_update_interval = m__io->read_u1();
    m_iod_atmo = m__io->read_u1();
}

ssr_t::stec_header_t::~stec_header_t() {
    _clean_up();
}

void ssr_t::stec_header_t::_clean_up() {
    if (m_time) {
        delete m_time; m_time = 0;
    }
}

ssr_t::msg_ssr_stec_correction_dep_a_t::msg_ssr_stec_correction_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_stec_sat_list = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_stec_correction_dep_a_t::_read() {
    m_header = new stec_header_dep_a_t(m__io, this, m__root);
    m_stec_sat_list = new std::vector<stec_sat_element_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_stec_sat_list->push_back(new stec_sat_element_t(m__io, this, m__root));
            i++;
        }
    }
}

ssr_t::msg_ssr_stec_correction_dep_a_t::~msg_ssr_stec_correction_dep_a_t() {
    _clean_up();
}

void ssr_t::msg_ssr_stec_correction_dep_a_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_stec_sat_list) {
        for (std::vector<stec_sat_element_t*>::iterator it = m_stec_sat_list->begin(); it != m_stec_sat_list->end(); ++it) {
            delete *it;
        }
        delete m_stec_sat_list; m_stec_sat_list = 0;
    }
}

ssr_t::gridded_correction_header_dep_a_t::gridded_correction_header_dep_a_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_time = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::gridded_correction_header_dep_a_t::_read() {
    m_time = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_num_msgs = m__io->read_u2le();
    m_seq_num = m__io->read_u2le();
    m_update_interval = m__io->read_u1();
    m_iod_atmo = m__io->read_u1();
    m_tropo_quality_indicator = m__io->read_u1();
}

ssr_t::gridded_correction_header_dep_a_t::~gridded_correction_header_dep_a_t() {
    _clean_up();
}

void ssr_t::gridded_correction_header_dep_a_t::_clean_up() {
    if (m_time) {
        delete m_time; m_time = 0;
    }
}

ssr_t::msg_ssr_orbit_clock_bounds_t::msg_ssr_orbit_clock_bounds_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_orbit_clock_bounds = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_orbit_clock_bounds_t::_read() {
    m_header = new bounds_header_t(m__io, this, m__root);
    m_ssr_iod = m__io->read_u1();
    m_const_id = m__io->read_u1();
    m_n_sats = m__io->read_u1();
    m_orbit_clock_bounds = new std::vector<orbit_clock_bound_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_orbit_clock_bounds->push_back(new orbit_clock_bound_t(m__io, this, m__root));
            i++;
        }
    }
}

ssr_t::msg_ssr_orbit_clock_bounds_t::~msg_ssr_orbit_clock_bounds_t() {
    _clean_up();
}

void ssr_t::msg_ssr_orbit_clock_bounds_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_orbit_clock_bounds) {
        for (std::vector<orbit_clock_bound_t*>::iterator it = m_orbit_clock_bounds->begin(); it != m_orbit_clock_bounds->end(); ++it) {
            delete *it;
        }
        delete m_orbit_clock_bounds; m_orbit_clock_bounds = 0;
    }
}

ssr_t::msg_ssr_gridded_correction_bounds_t::msg_ssr_gridded_correction_bounds_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_tropo_delay_correction = 0;
    m_stec_sat_list = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_gridded_correction_bounds_t::_read() {
    m_header = new bounds_header_t(m__io, this, m__root);
    m_ssr_iod_atmo = m__io->read_u1();
    m_tile_set_id = m__io->read_u2le();
    m_tile_id = m__io->read_u2le();
    m_tropo_qi = m__io->read_u1();
    m_grid_point_id = m__io->read_u2le();
    m_tropo_delay_correction = new tropospheric_delay_correction_t(m__io, this, m__root);
    m_tropo_v_hydro_bound_mu = m__io->read_u1();
    m_tropo_v_hydro_bound_sig = m__io->read_u1();
    m_tropo_v_wet_bound_mu = m__io->read_u1();
    m_tropo_v_wet_bound_sig = m__io->read_u1();
    m_n_sats = m__io->read_u1();
    m_stec_sat_list = new std::vector<stec_sat_element_integrity_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_stec_sat_list->push_back(new stec_sat_element_integrity_t(m__io, this, m__root));
            i++;
        }
    }
}

ssr_t::msg_ssr_gridded_correction_bounds_t::~msg_ssr_gridded_correction_bounds_t() {
    _clean_up();
}

void ssr_t::msg_ssr_gridded_correction_bounds_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_tropo_delay_correction) {
        delete m_tropo_delay_correction; m_tropo_delay_correction = 0;
    }
    if (m_stec_sat_list) {
        for (std::vector<stec_sat_element_integrity_t*>::iterator it = m_stec_sat_list->begin(); it != m_stec_sat_list->end(); ++it) {
            delete *it;
        }
        delete m_stec_sat_list; m_stec_sat_list = 0;
    }
}

ssr_t::msg_ssr_grid_definition_dep_a_t::msg_ssr_grid_definition_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_rle_list = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_grid_definition_dep_a_t::_read() {
    m_header = new grid_definition_header_dep_a_t(m__io, this, m__root);
    m_rle_list = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_rle_list->push_back(m__io->read_u1());
            i++;
        }
    }
}

ssr_t::msg_ssr_grid_definition_dep_a_t::~msg_ssr_grid_definition_dep_a_t() {
    _clean_up();
}

void ssr_t::msg_ssr_grid_definition_dep_a_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_rle_list) {
        delete m_rle_list; m_rle_list = 0;
    }
}

ssr_t::code_biases_content_t::code_biases_content_t(kaitai::kstream* p__io, ssr_t::msg_ssr_code_biases_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::code_biases_content_t::_read() {
    m_code = m__io->read_u1();
    m_value = m__io->read_s2le();
}

ssr_t::code_biases_content_t::~code_biases_content_t() {
    _clean_up();
}

void ssr_t::code_biases_content_t::_clean_up() {
}

ssr_t::msg_ssr_satellite_apc_t::msg_ssr_satellite_apc_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_time = 0;
    m_apc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_satellite_apc_t::_read() {
    m_time = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_update_interval = m__io->read_u1();
    m_sol_id = m__io->read_u1();
    m_iod_ssr = m__io->read_u1();
    m_apc = new std::vector<satellite_apc_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_apc->push_back(new satellite_apc_t(m__io, this, m__root));
            i++;
        }
    }
}

ssr_t::msg_ssr_satellite_apc_t::~msg_ssr_satellite_apc_t() {
    _clean_up();
}

void ssr_t::msg_ssr_satellite_apc_t::_clean_up() {
    if (m_time) {
        delete m_time; m_time = 0;
    }
    if (m_apc) {
        for (std::vector<satellite_apc_t*>::iterator it = m_apc->begin(); it != m_apc->end(); ++it) {
            delete *it;
        }
        delete m_apc; m_apc = 0;
    }
}

ssr_t::phase_biases_content_t::phase_biases_content_t(kaitai::kstream* p__io, ssr_t::msg_ssr_phase_biases_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::phase_biases_content_t::_read() {
    m_code = m__io->read_u1();
    m_integer_indicator = m__io->read_u1();
    m_widelane_integer_indicator = m__io->read_u1();
    m_discontinuity_counter = m__io->read_u1();
    m_bias = m__io->read_s4le();
}

ssr_t::phase_biases_content_t::~phase_biases_content_t() {
    _clean_up();
}

void ssr_t::phase_biases_content_t::_clean_up() {
}

ssr_t::msg_ssr_tile_definition_dep_a_t::msg_ssr_tile_definition_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_tile_definition_dep_a_t::_read() {
    m_tile_set_id = m__io->read_u2le();
    m_tile_id = m__io->read_u2le();
    m_corner_nw_lat = m__io->read_s2le();
    m_corner_nw_lon = m__io->read_s2le();
    m_spacing_lat = m__io->read_u2le();
    m_spacing_lon = m__io->read_u2le();
    m_rows = m__io->read_u2le();
    m_cols = m__io->read_u2le();
    m_bitmask = m__io->read_u8le();
}

ssr_t::msg_ssr_tile_definition_dep_a_t::~msg_ssr_tile_definition_dep_a_t() {
    _clean_up();
}

void ssr_t::msg_ssr_tile_definition_dep_a_t::_clean_up() {
}

ssr_t::orbit_clock_bound_t::orbit_clock_bound_t(kaitai::kstream* p__io, ssr_t::msg_ssr_orbit_clock_bounds_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::orbit_clock_bound_t::_read() {
    m_sat_id = m__io->read_u1();
    m_orb_radial_bound_mu = m__io->read_u1();
    m_orb_along_bound_mu = m__io->read_u1();
    m_orb_cross_bound_mu = m__io->read_u1();
    m_orb_radial_bound_sig = m__io->read_u1();
    m_orb_along_bound_sig = m__io->read_u1();
    m_orb_cross_bound_sig = m__io->read_u1();
    m_clock_bound_mu = m__io->read_u1();
    m_clock_bound_sig = m__io->read_u1();
}

ssr_t::orbit_clock_bound_t::~orbit_clock_bound_t() {
    _clean_up();
}

void ssr_t::orbit_clock_bound_t::_clean_up() {
}

ssr_t::msg_ssr_gridded_correction_dep_a_t::msg_ssr_gridded_correction_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_tropo_delay_correction = 0;
    m_stec_residuals = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_gridded_correction_dep_a_t::_read() {
    m_header = new gridded_correction_header_dep_a_t(m__io, this, m__root);
    m_index = m__io->read_u2le();
    m_tropo_delay_correction = new tropospheric_delay_correction_t(m__io, this, m__root);
    m_stec_residuals = new std::vector<stec_residual_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_stec_residuals->push_back(new stec_residual_t(m__io, this, m__root));
            i++;
        }
    }
}

ssr_t::msg_ssr_gridded_correction_dep_a_t::~msg_ssr_gridded_correction_dep_a_t() {
    _clean_up();
}

void ssr_t::msg_ssr_gridded_correction_dep_a_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_tropo_delay_correction) {
        delete m_tropo_delay_correction; m_tropo_delay_correction = 0;
    }
    if (m_stec_residuals) {
        for (std::vector<stec_residual_t*>::iterator it = m_stec_residuals->begin(); it != m_stec_residuals->end(); ++it) {
            delete *it;
        }
        delete m_stec_residuals; m_stec_residuals = 0;
    }
}

ssr_t::msg_ssr_orbit_clock_bounds_degradation_t::msg_ssr_orbit_clock_bounds_degradation_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_orbit_clock_bounds_degradation = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_orbit_clock_bounds_degradation_t::_read() {
    m_header = new bounds_header_t(m__io, this, m__root);
    m_ssr_iod = m__io->read_u1();
    m_const_id = m__io->read_u1();
    m_sat_bitmask = m__io->read_u8le();
    m_orbit_clock_bounds_degradation = new orbit_clock_bound_degradation_t(m__io, this, m__root);
}

ssr_t::msg_ssr_orbit_clock_bounds_degradation_t::~msg_ssr_orbit_clock_bounds_degradation_t() {
    _clean_up();
}

void ssr_t::msg_ssr_orbit_clock_bounds_degradation_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_orbit_clock_bounds_degradation) {
        delete m_orbit_clock_bounds_degradation; m_orbit_clock_bounds_degradation = 0;
    }
}

ssr_t::msg_ssr_gridded_correction_no_std_dep_a_t::msg_ssr_gridded_correction_no_std_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_tropo_delay_correction = 0;
    m_stec_residuals = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_gridded_correction_no_std_dep_a_t::_read() {
    m_header = new gridded_correction_header_dep_a_t(m__io, this, m__root);
    m_index = m__io->read_u2le();
    m_tropo_delay_correction = new tropospheric_delay_correction_no_std_t(m__io, this, m__root);
    m_stec_residuals = new std::vector<stec_residual_no_std_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_stec_residuals->push_back(new stec_residual_no_std_t(m__io, this, m__root));
            i++;
        }
    }
}

ssr_t::msg_ssr_gridded_correction_no_std_dep_a_t::~msg_ssr_gridded_correction_no_std_dep_a_t() {
    _clean_up();
}

void ssr_t::msg_ssr_gridded_correction_no_std_dep_a_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_tropo_delay_correction) {
        delete m_tropo_delay_correction; m_tropo_delay_correction = 0;
    }
    if (m_stec_residuals) {
        for (std::vector<stec_residual_no_std_t*>::iterator it = m_stec_residuals->begin(); it != m_stec_residuals->end(); ++it) {
            delete *it;
        }
        delete m_stec_residuals; m_stec_residuals = 0;
    }
}

ssr_t::msg_ssr_code_phase_biases_bounds_t::msg_ssr_code_phase_biases_bounds_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_satellites_signals = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_code_phase_biases_bounds_t::_read() {
    m_header = new bounds_header_t(m__io, this, m__root);
    m_ssr_iod = m__io->read_u1();
    m_const_id = m__io->read_u1();
    m_n_sats_signals = m__io->read_u1();
    m_satellites_signals = new std::vector<code_phase_biases_sat_sig_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_satellites_signals->push_back(new code_phase_biases_sat_sig_t(m__io, this, m__root));
            i++;
        }
    }
}

ssr_t::msg_ssr_code_phase_biases_bounds_t::~msg_ssr_code_phase_biases_bounds_t() {
    _clean_up();
}

void ssr_t::msg_ssr_code_phase_biases_bounds_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_satellites_signals) {
        for (std::vector<code_phase_biases_sat_sig_t*>::iterator it = m_satellites_signals->begin(); it != m_satellites_signals->end(); ++it) {
            delete *it;
        }
        delete m_satellites_signals; m_satellites_signals = 0;
    }
}

ssr_t::msg_ssr_code_biases_t::msg_ssr_code_biases_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_time = 0;
    m_sid = 0;
    m_biases = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_code_biases_t::_read() {
    m_time = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_update_interval = m__io->read_u1();
    m_iod_ssr = m__io->read_u1();
    m_biases = new std::vector<code_biases_content_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_biases->push_back(new code_biases_content_t(m__io, this, m__root));
            i++;
        }
    }
}

ssr_t::msg_ssr_code_biases_t::~msg_ssr_code_biases_t() {
    _clean_up();
}

void ssr_t::msg_ssr_code_biases_t::_clean_up() {
    if (m_time) {
        delete m_time; m_time = 0;
    }
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
    if (m_biases) {
        for (std::vector<code_biases_content_t*>::iterator it = m_biases->begin(); it != m_biases->end(); ++it) {
            delete *it;
        }
        delete m_biases; m_biases = 0;
    }
}

ssr_t::msg_ssr_tile_definition_t::msg_ssr_tile_definition_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_time = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_tile_definition_t::_read() {
    m_time = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_update_interval = m__io->read_u1();
    m_sol_id = m__io->read_u1();
    m_iod_atmo = m__io->read_u1();
    m_tile_set_id = m__io->read_u2le();
    m_tile_id = m__io->read_u2le();
    m_corner_nw_lat = m__io->read_s2le();
    m_corner_nw_lon = m__io->read_s2le();
    m_spacing_lat = m__io->read_u2le();
    m_spacing_lon = m__io->read_u2le();
    m_rows = m__io->read_u2le();
    m_cols = m__io->read_u2le();
    m_bitmask = m__io->read_u8le();
}

ssr_t::msg_ssr_tile_definition_t::~msg_ssr_tile_definition_t() {
    _clean_up();
}

void ssr_t::msg_ssr_tile_definition_t::_clean_up() {
    if (m_time) {
        delete m_time; m_time = 0;
    }
}

ssr_t::orbit_clock_bound_degradation_t::orbit_clock_bound_degradation_t(kaitai::kstream* p__io, ssr_t::msg_ssr_orbit_clock_bounds_degradation_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::orbit_clock_bound_degradation_t::_read() {
    m_orb_radial_bound_mu_dot = m__io->read_u1();
    m_orb_along_bound_mu_dot = m__io->read_u1();
    m_orb_cross_bound_mu_dot = m__io->read_u1();
    m_orb_radial_bound_sig_dot = m__io->read_u1();
    m_orb_along_bound_sig_dot = m__io->read_u1();
    m_orb_cross_bound_sig_dot = m__io->read_u1();
    m_clock_bound_mu_dot = m__io->read_u1();
    m_clock_bound_sig_dot = m__io->read_u1();
}

ssr_t::orbit_clock_bound_degradation_t::~orbit_clock_bound_degradation_t() {
    _clean_up();
}

void ssr_t::orbit_clock_bound_degradation_t::_clean_up() {
}

ssr_t::msg_ssr_satellite_apc_dep_t::msg_ssr_satellite_apc_dep_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_apc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_satellite_apc_dep_t::_read() {
    m_apc = new std::vector<satellite_apc_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_apc->push_back(new satellite_apc_t(m__io, this, m__root));
            i++;
        }
    }
}

ssr_t::msg_ssr_satellite_apc_dep_t::~msg_ssr_satellite_apc_dep_t() {
    _clean_up();
}

void ssr_t::msg_ssr_satellite_apc_dep_t::_clean_up() {
    if (m_apc) {
        for (std::vector<satellite_apc_t*>::iterator it = m_apc->begin(); it != m_apc->end(); ++it) {
            delete *it;
        }
        delete m_apc; m_apc = 0;
    }
}

ssr_t::tropospheric_delay_correction_t::tropospheric_delay_correction_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::tropospheric_delay_correction_t::_read() {
    m_hydro = m__io->read_s2le();
    m_wet = m__io->read_s1();
    m_stddev = m__io->read_u1();
}

ssr_t::tropospheric_delay_correction_t::~tropospheric_delay_correction_t() {
    _clean_up();
}

void ssr_t::tropospheric_delay_correction_t::_clean_up() {
}

ssr_t::msg_ssr_tile_definition_dep_b_t::msg_ssr_tile_definition_dep_b_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_tile_definition_dep_b_t::_read() {
    m_ssr_sol_id = m__io->read_u1();
    m_tile_set_id = m__io->read_u2le();
    m_tile_id = m__io->read_u2le();
    m_corner_nw_lat = m__io->read_s2le();
    m_corner_nw_lon = m__io->read_s2le();
    m_spacing_lat = m__io->read_u2le();
    m_spacing_lon = m__io->read_u2le();
    m_rows = m__io->read_u2le();
    m_cols = m__io->read_u2le();
    m_bitmask = m__io->read_u8le();
}

ssr_t::msg_ssr_tile_definition_dep_b_t::~msg_ssr_tile_definition_dep_b_t() {
    _clean_up();
}

void ssr_t::msg_ssr_tile_definition_dep_b_t::_clean_up() {
}

ssr_t::msg_ssr_phase_biases_t::msg_ssr_phase_biases_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ssr_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_time = 0;
    m_sid = 0;
    m_biases = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ssr_t::msg_ssr_phase_biases_t::_read() {
    m_time = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_update_interval = m__io->read_u1();
    m_iod_ssr = m__io->read_u1();
    m_dispersive_bias = m__io->read_u1();
    m_mw_consistency = m__io->read_u1();
    m_yaw = m__io->read_u2le();
    m_yaw_rate = m__io->read_s1();
    m_biases = new std::vector<phase_biases_content_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_biases->push_back(new phase_biases_content_t(m__io, this, m__root));
            i++;
        }
    }
}

ssr_t::msg_ssr_phase_biases_t::~msg_ssr_phase_biases_t() {
    _clean_up();
}

void ssr_t::msg_ssr_phase_biases_t::_clean_up() {
    if (m_time) {
        delete m_time; m_time = 0;
    }
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
    if (m_biases) {
        for (std::vector<phase_biases_content_t*>::iterator it = m_biases->begin(); it != m_biases->end(); ++it) {
            delete *it;
        }
        delete m_biases; m_biases = 0;
    }
}
