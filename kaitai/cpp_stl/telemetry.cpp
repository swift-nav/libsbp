// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "telemetry.h"

telemetry_t::telemetry_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, telemetry_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void telemetry_t::_read() {
}

telemetry_t::~telemetry_t() {
    _clean_up();
}

void telemetry_t::_clean_up() {
}

telemetry_t::telemetry_sv_t::telemetry_sv_t(kaitai::kstream* p__io, telemetry_t::msg_tel_sv_t* p__parent, telemetry_t* p__root) : kaitai::kstruct(p__io) {
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

void telemetry_t::telemetry_sv_t::_read() {
    m_az = m__io->read_u1();
    m_el = m__io->read_s1();
    m_availability_flags = m__io->read_u1();
    m_pseudorange_residual = m__io->read_s2le();
    m_phase_residual = m__io->read_s2le();
    m_outlier_flags = m__io->read_u1();
    m_ephemeris_flags = m__io->read_u1();
    m_correction_flags = m__io->read_u1();
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
}

telemetry_t::telemetry_sv_t::~telemetry_sv_t() {
    _clean_up();
}

void telemetry_t::telemetry_sv_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

telemetry_t::msg_tel_sv_t::msg_tel_sv_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, telemetry_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sv_tel = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void telemetry_t::msg_tel_sv_t::_read() {
    m_wn = m__io->read_u2le();
    m_tow = m__io->read_u4le();
    m_n_obs = m__io->read_u1();
    m_origin_flags = m__io->read_u1();
    m_sv_tel = new std::vector<telemetry_sv_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_sv_tel->push_back(new telemetry_sv_t(m__io, this, m__root));
            i++;
        }
    }
}

telemetry_t::msg_tel_sv_t::~msg_tel_sv_t() {
    _clean_up();
}

void telemetry_t::msg_tel_sv_t::_clean_up() {
    if (m_sv_tel) {
        for (std::vector<telemetry_sv_t*>::iterator it = m_sv_tel->begin(); it != m_sv_tel->end(); ++it) {
            delete *it;
        }
        delete m_sv_tel; m_sv_tel = 0;
    }
}
