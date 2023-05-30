// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "gnss.h"

gnss_t::gnss_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, gnss_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void gnss_t::_read() {
}

gnss_t::~gnss_t() {
    _clean_up();
}

void gnss_t::_clean_up() {
}

gnss_t::gnss_signal_dep_t::gnss_signal_dep_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, gnss_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void gnss_t::gnss_signal_dep_t::_read() {
    m_sat = m__io->read_u2le();
    m_code = m__io->read_u1();
    m_reserved = m__io->read_u1();
}

gnss_t::gnss_signal_dep_t::~gnss_signal_dep_t() {
    _clean_up();
}

void gnss_t::gnss_signal_dep_t::_clean_up() {
}

gnss_t::carrier_phase_t::carrier_phase_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, gnss_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void gnss_t::carrier_phase_t::_read() {
    m_i = m__io->read_s4le();
    m_f = m__io->read_u1();
}

gnss_t::carrier_phase_t::~carrier_phase_t() {
    _clean_up();
}

void gnss_t::carrier_phase_t::_clean_up() {
}

gnss_t::gps_time_dep_t::gps_time_dep_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, gnss_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void gnss_t::gps_time_dep_t::_read() {
    m_tow = m__io->read_u4le();
    m_wn = m__io->read_u2le();
}

gnss_t::gps_time_dep_t::~gps_time_dep_t() {
    _clean_up();
}

void gnss_t::gps_time_dep_t::_clean_up() {
}

gnss_t::gnss_signal_t::gnss_signal_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, gnss_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void gnss_t::gnss_signal_t::_read() {
    m_sat = m__io->read_u1();
    m_code = m__io->read_u1();
}

gnss_t::gnss_signal_t::~gnss_signal_t() {
    _clean_up();
}

void gnss_t::gnss_signal_t::_clean_up() {
}

gnss_t::gps_time_t::gps_time_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, gnss_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void gnss_t::gps_time_t::_read() {
    m_tow = m__io->read_u4le();
    m_ns_residual = m__io->read_s4le();
    m_wn = m__io->read_u2le();
}

gnss_t::gps_time_t::~gps_time_t() {
    _clean_up();
}

void gnss_t::gps_time_t::_clean_up() {
}

gnss_t::gps_time_sec_t::gps_time_sec_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, gnss_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void gnss_t::gps_time_sec_t::_read() {
    m_tow = m__io->read_u4le();
    m_wn = m__io->read_u2le();
}

gnss_t::gps_time_sec_t::~gps_time_sec_t() {
    _clean_up();
}

void gnss_t::gps_time_sec_t::_clean_up() {
}

gnss_t::sv_id_t::sv_id_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, gnss_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void gnss_t::sv_id_t::_read() {
    m_sat_id = m__io->read_u1();
    m_constellation = m__io->read_u1();
}

gnss_t::sv_id_t::~sv_id_t() {
    _clean_up();
}

void gnss_t::sv_id_t::_clean_up() {
}
