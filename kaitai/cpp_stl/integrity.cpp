// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "integrity.h"

integrity_t::integrity_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, integrity_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void integrity_t::_read() {
}

integrity_t::~integrity_t() {
    _clean_up();
}

void integrity_t::_clean_up() {
}

integrity_t::msg_ssr_flag_satellites_t::msg_ssr_flag_satellites_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, integrity_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_obs_time = 0;
    m_faulty_sats = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void integrity_t::msg_ssr_flag_satellites_t::_read() {
    m_obs_time = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_num_msgs = m__io->read_u1();
    m_seq_num = m__io->read_u1();
    m_ssr_sol_id = m__io->read_u1();
    m_chain_id = m__io->read_u1();
    m_const_id = m__io->read_u1();
    m_n_faulty_sats = m__io->read_u1();
    m_faulty_sats = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_faulty_sats->push_back(m__io->read_u1());
            i++;
        }
    }
}

integrity_t::msg_ssr_flag_satellites_t::~msg_ssr_flag_satellites_t() {
    _clean_up();
}

void integrity_t::msg_ssr_flag_satellites_t::_clean_up() {
    if (m_obs_time) {
        delete m_obs_time; m_obs_time = 0;
    }
    if (m_faulty_sats) {
        delete m_faulty_sats; m_faulty_sats = 0;
    }
}

integrity_t::msg_ssr_flag_iono_tile_sat_los_t::msg_ssr_flag_iono_tile_sat_los_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, integrity_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_faulty_los = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void integrity_t::msg_ssr_flag_iono_tile_sat_los_t::_read() {
    m_header = new integrity_ssr_header_t(m__io, this, m__root);
    m_n_faulty_los = m__io->read_u1();
    m_faulty_los = new std::vector<gnss_t::sv_id_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_faulty_los->push_back(new gnss_t::sv_id_t(m__io, this, m__root));
            i++;
        }
    }
}

integrity_t::msg_ssr_flag_iono_tile_sat_los_t::~msg_ssr_flag_iono_tile_sat_los_t() {
    _clean_up();
}

void integrity_t::msg_ssr_flag_iono_tile_sat_los_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_faulty_los) {
        for (std::vector<gnss_t::sv_id_t*>::iterator it = m_faulty_los->begin(); it != m_faulty_los->end(); ++it) {
            delete *it;
        }
        delete m_faulty_los; m_faulty_los = 0;
    }
}

integrity_t::msg_ssr_flag_iono_grid_point_sat_los_t::msg_ssr_flag_iono_grid_point_sat_los_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, integrity_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_faulty_los = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void integrity_t::msg_ssr_flag_iono_grid_point_sat_los_t::_read() {
    m_header = new integrity_ssr_header_t(m__io, this, m__root);
    m_grid_point_id = m__io->read_u2le();
    m_n_faulty_los = m__io->read_u1();
    m_faulty_los = new std::vector<gnss_t::sv_id_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_faulty_los->push_back(new gnss_t::sv_id_t(m__io, this, m__root));
            i++;
        }
    }
}

integrity_t::msg_ssr_flag_iono_grid_point_sat_los_t::~msg_ssr_flag_iono_grid_point_sat_los_t() {
    _clean_up();
}

void integrity_t::msg_ssr_flag_iono_grid_point_sat_los_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_faulty_los) {
        for (std::vector<gnss_t::sv_id_t*>::iterator it = m_faulty_los->begin(); it != m_faulty_los->end(); ++it) {
            delete *it;
        }
        delete m_faulty_los; m_faulty_los = 0;
    }
}

integrity_t::integrity_ssr_header_t::integrity_ssr_header_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, integrity_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_obs_time = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void integrity_t::integrity_ssr_header_t::_read() {
    m_obs_time = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_num_msgs = m__io->read_u1();
    m_seq_num = m__io->read_u1();
    m_ssr_sol_id = m__io->read_u1();
    m_tile_set_id = m__io->read_u2le();
    m_tile_id = m__io->read_u2le();
    m_chain_id = m__io->read_u1();
}

integrity_t::integrity_ssr_header_t::~integrity_ssr_header_t() {
    _clean_up();
}

void integrity_t::integrity_ssr_header_t::_clean_up() {
    if (m_obs_time) {
        delete m_obs_time; m_obs_time = 0;
    }
}

integrity_t::msg_acknowledge_t::msg_acknowledge_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, integrity_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void integrity_t::msg_acknowledge_t::_read() {
    m_request_id = m__io->read_u1();
    m_area_id = m__io->read_u4le();
    m_response_code = m__io->read_u1();
    m_correction_mask_on_demand = m__io->read_u2le();
    m_correction_mask_stream = m__io->read_u2le();
    m_solution_id = m__io->read_u1();
}

integrity_t::msg_acknowledge_t::~msg_acknowledge_t() {
    _clean_up();
}

void integrity_t::msg_acknowledge_t::_clean_up() {
}

integrity_t::msg_ssr_flag_iono_grid_points_t::msg_ssr_flag_iono_grid_points_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, integrity_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_faulty_points = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void integrity_t::msg_ssr_flag_iono_grid_points_t::_read() {
    m_header = new integrity_ssr_header_t(m__io, this, m__root);
    m_n_faulty_points = m__io->read_u1();
    m_faulty_points = new std::vector<uint16_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_faulty_points->push_back(m__io->read_u2le());
            i++;
        }
    }
}

integrity_t::msg_ssr_flag_iono_grid_points_t::~msg_ssr_flag_iono_grid_points_t() {
    _clean_up();
}

void integrity_t::msg_ssr_flag_iono_grid_points_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_faulty_points) {
        delete m_faulty_points; m_faulty_points = 0;
    }
}

integrity_t::msg_ssr_flag_tropo_grid_points_t::msg_ssr_flag_tropo_grid_points_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, integrity_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;
    m_faulty_points = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void integrity_t::msg_ssr_flag_tropo_grid_points_t::_read() {
    m_header = new integrity_ssr_header_t(m__io, this, m__root);
    m_n_faulty_points = m__io->read_u1();
    m_faulty_points = new std::vector<uint16_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_faulty_points->push_back(m__io->read_u2le());
            i++;
        }
    }
}

integrity_t::msg_ssr_flag_tropo_grid_points_t::~msg_ssr_flag_tropo_grid_points_t() {
    _clean_up();
}

void integrity_t::msg_ssr_flag_tropo_grid_points_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (m_faulty_points) {
        delete m_faulty_points; m_faulty_points = 0;
    }
}

integrity_t::msg_ssr_flag_high_level_t::msg_ssr_flag_high_level_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, integrity_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_obs_time = 0;
    m_corr_time = 0;
    m_reserved = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void integrity_t::msg_ssr_flag_high_level_t::_read() {
    m_obs_time = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_corr_time = new gnss_t::gps_time_sec_t(m__io, this, m__root);
    m_ssr_sol_id = m__io->read_u1();
    m_tile_set_id = m__io->read_u2le();
    m_tile_id = m__io->read_u2le();
    m_chain_id = m__io->read_u1();
    m_use_gps_sat = m__io->read_u1();
    m_use_gal_sat = m__io->read_u1();
    m_use_bds_sat = m__io->read_u1();
    m_reserved = new std::vector<uint8_t>();
    const int l_reserved = 6;
    for (int i = 0; i < l_reserved; i++) {
        m_reserved->push_back(m__io->read_u1());
    }
    m_use_tropo_grid_points = m__io->read_u1();
    m_use_iono_grid_points = m__io->read_u1();
    m_use_iono_tile_sat_los = m__io->read_u1();
    m_use_iono_grid_point_sat_los = m__io->read_u1();
}

integrity_t::msg_ssr_flag_high_level_t::~msg_ssr_flag_high_level_t() {
    _clean_up();
}

void integrity_t::msg_ssr_flag_high_level_t::_clean_up() {
    if (m_obs_time) {
        delete m_obs_time; m_obs_time = 0;
    }
    if (m_corr_time) {
        delete m_corr_time; m_corr_time = 0;
    }
    if (m_reserved) {
        delete m_reserved; m_reserved = 0;
    }
}
