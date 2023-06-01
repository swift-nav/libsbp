// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "logging.h"

logging_t::logging_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, logging_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void logging_t::_read() {
}

logging_t::~logging_t() {
    _clean_up();
}

void logging_t::_clean_up() {
}

logging_t::msg_log_t::msg_log_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, logging_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void logging_t::msg_log_t::_read() {
    m_level = m__io->read_u1();
    m_text = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

logging_t::msg_log_t::~msg_log_t() {
    _clean_up();
}

void logging_t::msg_log_t::_clean_up() {
}

logging_t::msg_fwd_t::msg_fwd_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, logging_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_fwd_payload = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void logging_t::msg_fwd_t::_read() {
    m_source = m__io->read_u1();
    m_protocol = m__io->read_u1();
    m_fwd_payload = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_fwd_payload->push_back(m__io->read_u1());
            i++;
        }
    }
}

logging_t::msg_fwd_t::~msg_fwd_t() {
    _clean_up();
}

void logging_t::msg_fwd_t::_clean_up() {
    if (m_fwd_payload) {
        delete m_fwd_payload; m_fwd_payload = 0;
    }
}

logging_t::msg_print_dep_t::msg_print_dep_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, logging_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void logging_t::msg_print_dep_t::_read() {
    m_text = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

logging_t::msg_print_dep_t::~msg_print_dep_t() {
    _clean_up();
}

void logging_t::msg_print_dep_t::_clean_up() {
}
