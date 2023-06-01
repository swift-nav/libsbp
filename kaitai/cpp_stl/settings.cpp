// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "settings.h"

settings_t::settings_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, settings_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void settings_t::_read() {
}

settings_t::~settings_t() {
    _clean_up();
}

void settings_t::_clean_up() {
}

settings_t::msg_settings_read_resp_t::msg_settings_read_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, settings_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void settings_t::msg_settings_read_resp_t::_read() {
    m_setting = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

settings_t::msg_settings_read_resp_t::~msg_settings_read_resp_t() {
    _clean_up();
}

void settings_t::msg_settings_read_resp_t::_clean_up() {
}

settings_t::msg_settings_write_resp_t::msg_settings_write_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, settings_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void settings_t::msg_settings_write_resp_t::_read() {
    m_status = m__io->read_u1();
    m_setting = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

settings_t::msg_settings_write_resp_t::~msg_settings_write_resp_t() {
    _clean_up();
}

void settings_t::msg_settings_write_resp_t::_clean_up() {
}

settings_t::msg_settings_register_resp_t::msg_settings_register_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, settings_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void settings_t::msg_settings_register_resp_t::_read() {
    m_status = m__io->read_u1();
    m_setting = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

settings_t::msg_settings_register_resp_t::~msg_settings_register_resp_t() {
    _clean_up();
}

void settings_t::msg_settings_register_resp_t::_clean_up() {
}

settings_t::msg_settings_read_by_index_resp_t::msg_settings_read_by_index_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, settings_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void settings_t::msg_settings_read_by_index_resp_t::_read() {
    m_index = m__io->read_u2le();
    m_setting = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

settings_t::msg_settings_read_by_index_resp_t::~msg_settings_read_by_index_resp_t() {
    _clean_up();
}

void settings_t::msg_settings_read_by_index_resp_t::_clean_up() {
}

settings_t::msg_settings_read_req_t::msg_settings_read_req_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, settings_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void settings_t::msg_settings_read_req_t::_read() {
    m_setting = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

settings_t::msg_settings_read_req_t::~msg_settings_read_req_t() {
    _clean_up();
}

void settings_t::msg_settings_read_req_t::_clean_up() {
}

settings_t::msg_settings_save_t::msg_settings_save_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, settings_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void settings_t::msg_settings_save_t::_read() {
}

settings_t::msg_settings_save_t::~msg_settings_save_t() {
    _clean_up();
}

void settings_t::msg_settings_save_t::_clean_up() {
}

settings_t::msg_settings_register_t::msg_settings_register_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, settings_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void settings_t::msg_settings_register_t::_read() {
    m_setting = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

settings_t::msg_settings_register_t::~msg_settings_register_t() {
    _clean_up();
}

void settings_t::msg_settings_register_t::_clean_up() {
}

settings_t::msg_settings_read_by_index_req_t::msg_settings_read_by_index_req_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, settings_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void settings_t::msg_settings_read_by_index_req_t::_read() {
    m_index = m__io->read_u2le();
}

settings_t::msg_settings_read_by_index_req_t::~msg_settings_read_by_index_req_t() {
    _clean_up();
}

void settings_t::msg_settings_read_by_index_req_t::_clean_up() {
}

settings_t::msg_settings_read_by_index_done_t::msg_settings_read_by_index_done_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, settings_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void settings_t::msg_settings_read_by_index_done_t::_read() {
}

settings_t::msg_settings_read_by_index_done_t::~msg_settings_read_by_index_done_t() {
    _clean_up();
}

void settings_t::msg_settings_read_by_index_done_t::_clean_up() {
}

settings_t::msg_settings_write_t::msg_settings_write_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, settings_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void settings_t::msg_settings_write_t::_read() {
    m_setting = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

settings_t::msg_settings_write_t::~msg_settings_write_t() {
    _clean_up();
}

void settings_t::msg_settings_write_t::_clean_up() {
}
