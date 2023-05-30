// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "user.h"

user_t::user_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, user_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void user_t::_read() {
}

user_t::~user_t() {
    _clean_up();
}

void user_t::_clean_up() {
}

user_t::msg_user_data_t::msg_user_data_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, user_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_contents = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void user_t::msg_user_data_t::_read() {
    m_contents = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_contents->push_back(m__io->read_u1());
            i++;
        }
    }
}

user_t::msg_user_data_t::~msg_user_data_t() {
    _clean_up();
}

void user_t::msg_user_data_t::_clean_up() {
    if (m_contents) {
        delete m_contents; m_contents = 0;
    }
}
