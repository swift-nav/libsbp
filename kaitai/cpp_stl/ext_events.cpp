// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "ext_events.h"

ext_events_t::ext_events_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, ext_events_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ext_events_t::_read() {
}

ext_events_t::~ext_events_t() {
    _clean_up();
}

void ext_events_t::_clean_up() {
}

ext_events_t::msg_ext_event_t::msg_ext_event_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, ext_events_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void ext_events_t::msg_ext_event_t::_read() {
    m_wn = m__io->read_u2le();
    m_tow = m__io->read_u4le();
    m_ns_residual = m__io->read_s4le();
    m_flags = m__io->read_u1();
    m_pin = m__io->read_u1();
}

ext_events_t::msg_ext_event_t::~msg_ext_event_t() {
    _clean_up();
}

void ext_events_t::msg_ext_event_t::_clean_up() {
}
