// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "solution_meta.h"

solution_meta_t::solution_meta_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, solution_meta_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void solution_meta_t::_read() {
}

solution_meta_t::~solution_meta_t() {
    _clean_up();
}

void solution_meta_t::_clean_up() {
}

solution_meta_t::gnss_input_type_t::gnss_input_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, solution_meta_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void solution_meta_t::gnss_input_type_t::_read() {
    m_flags = m__io->read_u1();
}

solution_meta_t::gnss_input_type_t::~gnss_input_type_t() {
    _clean_up();
}

void solution_meta_t::gnss_input_type_t::_clean_up() {
}

solution_meta_t::msg_soln_meta_t::msg_soln_meta_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, solution_meta_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sol_in = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void solution_meta_t::msg_soln_meta_t::_read() {
    m_tow = m__io->read_u4le();
    m_pdop = m__io->read_u2le();
    m_hdop = m__io->read_u2le();
    m_vdop = m__io->read_u2le();
    m_age_corrections = m__io->read_u2le();
    m_age_gnss = m__io->read_u4le();
    m_sol_in = new std::vector<solution_input_type_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_sol_in->push_back(new solution_input_type_t(m__io, this, m__root));
            i++;
        }
    }
}

solution_meta_t::msg_soln_meta_t::~msg_soln_meta_t() {
    _clean_up();
}

void solution_meta_t::msg_soln_meta_t::_clean_up() {
    if (m_sol_in) {
        for (std::vector<solution_input_type_t*>::iterator it = m_sol_in->begin(); it != m_sol_in->end(); ++it) {
            delete *it;
        }
        delete m_sol_in; m_sol_in = 0;
    }
}

solution_meta_t::msg_soln_meta_dep_a_t::msg_soln_meta_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, solution_meta_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sol_in = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void solution_meta_t::msg_soln_meta_dep_a_t::_read() {
    m_pdop = m__io->read_u2le();
    m_hdop = m__io->read_u2le();
    m_vdop = m__io->read_u2le();
    m_n_sats = m__io->read_u1();
    m_age_corrections = m__io->read_u2le();
    m_alignment_status = m__io->read_u1();
    m_last_used_gnss_pos_tow = m__io->read_u4le();
    m_last_used_gnss_vel_tow = m__io->read_u4le();
    m_sol_in = new std::vector<solution_input_type_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_sol_in->push_back(new solution_input_type_t(m__io, this, m__root));
            i++;
        }
    }
}

solution_meta_t::msg_soln_meta_dep_a_t::~msg_soln_meta_dep_a_t() {
    _clean_up();
}

void solution_meta_t::msg_soln_meta_dep_a_t::_clean_up() {
    if (m_sol_in) {
        for (std::vector<solution_input_type_t*>::iterator it = m_sol_in->begin(); it != m_sol_in->end(); ++it) {
            delete *it;
        }
        delete m_sol_in; m_sol_in = 0;
    }
}

solution_meta_t::imu_input_type_t::imu_input_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, solution_meta_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void solution_meta_t::imu_input_type_t::_read() {
    m_flags = m__io->read_u1();
}

solution_meta_t::imu_input_type_t::~imu_input_type_t() {
    _clean_up();
}

void solution_meta_t::imu_input_type_t::_clean_up() {
}

solution_meta_t::odo_input_type_t::odo_input_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, solution_meta_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void solution_meta_t::odo_input_type_t::_read() {
    m_flags = m__io->read_u1();
}

solution_meta_t::odo_input_type_t::~odo_input_type_t() {
    _clean_up();
}

void solution_meta_t::odo_input_type_t::_clean_up() {
}

solution_meta_t::solution_input_type_t::solution_input_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, solution_meta_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void solution_meta_t::solution_input_type_t::_read() {
    m_sensor_type = m__io->read_u1();
    m_flags = m__io->read_u1();
}

solution_meta_t::solution_input_type_t::~solution_input_type_t() {
    _clean_up();
}

void solution_meta_t::solution_input_type_t::_clean_up() {
}
