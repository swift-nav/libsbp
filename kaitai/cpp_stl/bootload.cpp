// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "bootload.h"

bootload_t::bootload_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, bootload_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void bootload_t::_read() {
}

bootload_t::~bootload_t() {
    _clean_up();
}

void bootload_t::_clean_up() {
}

bootload_t::msg_nap_device_dna_req_t::msg_nap_device_dna_req_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, bootload_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void bootload_t::msg_nap_device_dna_req_t::_read() {
}

bootload_t::msg_nap_device_dna_req_t::~msg_nap_device_dna_req_t() {
    _clean_up();
}

void bootload_t::msg_nap_device_dna_req_t::_clean_up() {
}

bootload_t::msg_bootloader_jump_to_app_t::msg_bootloader_jump_to_app_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, bootload_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void bootload_t::msg_bootloader_jump_to_app_t::_read() {
    m_jump = m__io->read_u1();
}

bootload_t::msg_bootloader_jump_to_app_t::~msg_bootloader_jump_to_app_t() {
    _clean_up();
}

void bootload_t::msg_bootloader_jump_to_app_t::_clean_up() {
}

bootload_t::msg_bootloader_handshake_resp_t::msg_bootloader_handshake_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, bootload_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void bootload_t::msg_bootloader_handshake_resp_t::_read() {
    m_flags = m__io->read_u4le();
    m_version = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

bootload_t::msg_bootloader_handshake_resp_t::~msg_bootloader_handshake_resp_t() {
    _clean_up();
}

void bootload_t::msg_bootloader_handshake_resp_t::_clean_up() {
}

bootload_t::msg_nap_device_dna_resp_t::msg_nap_device_dna_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, bootload_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_dna = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void bootload_t::msg_nap_device_dna_resp_t::_read() {
    m_dna = new std::vector<uint8_t>();
    const int l_dna = 8;
    for (int i = 0; i < l_dna; i++) {
        m_dna->push_back(m__io->read_u1());
    }
}

bootload_t::msg_nap_device_dna_resp_t::~msg_nap_device_dna_resp_t() {
    _clean_up();
}

void bootload_t::msg_nap_device_dna_resp_t::_clean_up() {
    if (m_dna) {
        delete m_dna; m_dna = 0;
    }
}

bootload_t::msg_bootloader_handshake_req_t::msg_bootloader_handshake_req_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, bootload_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void bootload_t::msg_bootloader_handshake_req_t::_read() {
}

bootload_t::msg_bootloader_handshake_req_t::~msg_bootloader_handshake_req_t() {
    _clean_up();
}

void bootload_t::msg_bootloader_handshake_req_t::_clean_up() {
}

bootload_t::msg_bootloader_handshake_dep_a_t::msg_bootloader_handshake_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, bootload_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_handshake = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void bootload_t::msg_bootloader_handshake_dep_a_t::_read() {
    m_handshake = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_handshake->push_back(m__io->read_u1());
            i++;
        }
    }
}

bootload_t::msg_bootloader_handshake_dep_a_t::~msg_bootloader_handshake_dep_a_t() {
    _clean_up();
}

void bootload_t::msg_bootloader_handshake_dep_a_t::_clean_up() {
    if (m_handshake) {
        delete m_handshake; m_handshake = 0;
    }
}
