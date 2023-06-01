// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "mag.h"

mag_t::mag_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, mag_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void mag_t::_read() {
}

mag_t::~mag_t() {
    _clean_up();
}

void mag_t::_clean_up() {
}

mag_t::msg_mag_raw_t::msg_mag_raw_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, mag_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void mag_t::msg_mag_raw_t::_read() {
    m_tow = m__io->read_u4le();
    m_tow_f = m__io->read_u1();
    m_mag_x = m__io->read_s2le();
    m_mag_y = m__io->read_s2le();
    m_mag_z = m__io->read_s2le();
}

mag_t::msg_mag_raw_t::~msg_mag_raw_t() {
    _clean_up();
}

void mag_t::msg_mag_raw_t::_clean_up() {
}
