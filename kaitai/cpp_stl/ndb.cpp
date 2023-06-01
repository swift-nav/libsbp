// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "ndb.h"

ndb_t::ndb_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, ndb_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ndb_t::_read() {
}

ndb_t::~ndb_t() {
    _clean_up();
}

void ndb_t::_clean_up() {
}

ndb_t::msg_ndb_event_t::msg_ndb_event_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, ndb_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_object_sid = 0;
    m_src_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ndb_t::msg_ndb_event_t::_read() {
    m_recv_time = m__io->read_u8le();
    m_event = m__io->read_u1();
    m_object_type = m__io->read_u1();
    m_result = m__io->read_u1();
    m_data_source = m__io->read_u1();
    m_object_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_src_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_original_sender = m__io->read_u2le();
}

ndb_t::msg_ndb_event_t::~msg_ndb_event_t() {
    _clean_up();
}

void ndb_t::msg_ndb_event_t::_clean_up() {
    if (m_object_sid) {
        delete m_object_sid; m_object_sid = 0;
    }
    if (m_src_sid) {
        delete m_src_sid; m_src_sid = 0;
    }
}
