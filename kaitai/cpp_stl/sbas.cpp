// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "sbas.h"

sbas_t::sbas_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, sbas_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void sbas_t::_read() {
}

sbas_t::~sbas_t() {
    _clean_up();
}

void sbas_t::_clean_up() {
}

sbas_t::msg_sbas_raw_t::msg_sbas_raw_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, sbas_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sid = 0;
    m_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void sbas_t::msg_sbas_raw_t::_read() {
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_tow = m__io->read_u4le();
    m_message_type = m__io->read_u1();
    m_data = new std::vector<uint8_t>();
    const int l_data = 27;
    for (int i = 0; i < l_data; i++) {
        m_data->push_back(m__io->read_u1());
    }
}

sbas_t::msg_sbas_raw_t::~msg_sbas_raw_t() {
    _clean_up();
}

void sbas_t::msg_sbas_raw_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
    if (m_data) {
        delete m_data; m_data = 0;
    }
}
