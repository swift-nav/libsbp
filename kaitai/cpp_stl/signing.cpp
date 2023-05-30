// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "signing.h"

signing_t::signing_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, signing_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void signing_t::_read() {
}

signing_t::~signing_t() {
    _clean_up();
}

void signing_t::_clean_up() {
}

signing_t::msg_ed25519_signature_dep_b_t::msg_ed25519_signature_dep_b_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, signing_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_signature = 0;
    m_fingerprint = 0;
    m_signed_messages = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void signing_t::msg_ed25519_signature_dep_b_t::_read() {
    m_stream_counter = m__io->read_u1();
    m_on_demand_counter = m__io->read_u1();
    m_signature = new std::vector<uint8_t>();
    const int l_signature = 64;
    for (int i = 0; i < l_signature; i++) {
        m_signature->push_back(m__io->read_u1());
    }
    m_fingerprint = new std::vector<uint8_t>();
    const int l_fingerprint = 20;
    for (int i = 0; i < l_fingerprint; i++) {
        m_fingerprint->push_back(m__io->read_u1());
    }
    m_signed_messages = new std::vector<uint32_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_signed_messages->push_back(m__io->read_u4le());
            i++;
        }
    }
}

signing_t::msg_ed25519_signature_dep_b_t::~msg_ed25519_signature_dep_b_t() {
    _clean_up();
}

void signing_t::msg_ed25519_signature_dep_b_t::_clean_up() {
    if (m_signature) {
        delete m_signature; m_signature = 0;
    }
    if (m_fingerprint) {
        delete m_fingerprint; m_fingerprint = 0;
    }
    if (m_signed_messages) {
        delete m_signed_messages; m_signed_messages = 0;
    }
}

signing_t::msg_ed25519_certificate_dep_t::msg_ed25519_certificate_dep_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, signing_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_fingerprint = 0;
    m_certificate_bytes = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void signing_t::msg_ed25519_certificate_dep_t::_read() {
    m_n_msg = m__io->read_u1();
    m_fingerprint = new std::vector<uint8_t>();
    const int l_fingerprint = 20;
    for (int i = 0; i < l_fingerprint; i++) {
        m_fingerprint->push_back(m__io->read_u1());
    }
    m_certificate_bytes = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_certificate_bytes->push_back(m__io->read_u1());
            i++;
        }
    }
}

signing_t::msg_ed25519_certificate_dep_t::~msg_ed25519_certificate_dep_t() {
    _clean_up();
}

void signing_t::msg_ed25519_certificate_dep_t::_clean_up() {
    if (m_fingerprint) {
        delete m_fingerprint; m_fingerprint = 0;
    }
    if (m_certificate_bytes) {
        delete m_certificate_bytes; m_certificate_bytes = 0;
    }
}

signing_t::utc_time_t::utc_time_t(kaitai::kstream* p__io, signing_t::msg_certificate_chain_t* p__parent, signing_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void signing_t::utc_time_t::_read() {
    m_year = m__io->read_u2le();
    m_month = m__io->read_u1();
    m_day = m__io->read_u1();
    m_hours = m__io->read_u1();
    m_minutes = m__io->read_u1();
    m_seconds = m__io->read_u1();
    m_ns = m__io->read_u4le();
}

signing_t::utc_time_t::~utc_time_t() {
    _clean_up();
}

void signing_t::utc_time_t::_clean_up() {
}

signing_t::msg_ed25519_signature_dep_a_t::msg_ed25519_signature_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, signing_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_signature = 0;
    m_fingerprint = 0;
    m_signed_messages = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void signing_t::msg_ed25519_signature_dep_a_t::_read() {
    m_signature = new std::vector<uint8_t>();
    const int l_signature = 64;
    for (int i = 0; i < l_signature; i++) {
        m_signature->push_back(m__io->read_u1());
    }
    m_fingerprint = new std::vector<uint8_t>();
    const int l_fingerprint = 20;
    for (int i = 0; i < l_fingerprint; i++) {
        m_fingerprint->push_back(m__io->read_u1());
    }
    m_signed_messages = new std::vector<uint32_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_signed_messages->push_back(m__io->read_u4le());
            i++;
        }
    }
}

signing_t::msg_ed25519_signature_dep_a_t::~msg_ed25519_signature_dep_a_t() {
    _clean_up();
}

void signing_t::msg_ed25519_signature_dep_a_t::_clean_up() {
    if (m_signature) {
        delete m_signature; m_signature = 0;
    }
    if (m_fingerprint) {
        delete m_fingerprint; m_fingerprint = 0;
    }
    if (m_signed_messages) {
        delete m_signed_messages; m_signed_messages = 0;
    }
}

signing_t::msg_certificate_chain_t::msg_certificate_chain_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, signing_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_root_certificate = 0;
    m_intermediate_certificate = 0;
    m_corrections_certificate = 0;
    m_expiration = 0;
    m_signature = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void signing_t::msg_certificate_chain_t::_read() {
    m_root_certificate = new std::vector<uint8_t>();
    const int l_root_certificate = 20;
    for (int i = 0; i < l_root_certificate; i++) {
        m_root_certificate->push_back(m__io->read_u1());
    }
    m_intermediate_certificate = new std::vector<uint8_t>();
    const int l_intermediate_certificate = 20;
    for (int i = 0; i < l_intermediate_certificate; i++) {
        m_intermediate_certificate->push_back(m__io->read_u1());
    }
    m_corrections_certificate = new std::vector<uint8_t>();
    const int l_corrections_certificate = 20;
    for (int i = 0; i < l_corrections_certificate; i++) {
        m_corrections_certificate->push_back(m__io->read_u1());
    }
    m_expiration = new utc_time_t(m__io, this, m__root);
    m_signature = new std::vector<uint8_t>();
    const int l_signature = 64;
    for (int i = 0; i < l_signature; i++) {
        m_signature->push_back(m__io->read_u1());
    }
}

signing_t::msg_certificate_chain_t::~msg_certificate_chain_t() {
    _clean_up();
}

void signing_t::msg_certificate_chain_t::_clean_up() {
    if (m_root_certificate) {
        delete m_root_certificate; m_root_certificate = 0;
    }
    if (m_intermediate_certificate) {
        delete m_intermediate_certificate; m_intermediate_certificate = 0;
    }
    if (m_corrections_certificate) {
        delete m_corrections_certificate; m_corrections_certificate = 0;
    }
    if (m_expiration) {
        delete m_expiration; m_expiration = 0;
    }
    if (m_signature) {
        delete m_signature; m_signature = 0;
    }
}

signing_t::msg_ecdsa_certificate_t::msg_ecdsa_certificate_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, signing_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_certificate_id = 0;
    m_certificate_bytes = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void signing_t::msg_ecdsa_certificate_t::_read() {
    m_n_msg = m__io->read_u1();
    m_certificate_id = new std::vector<uint8_t>();
    const int l_certificate_id = 4;
    for (int i = 0; i < l_certificate_id; i++) {
        m_certificate_id->push_back(m__io->read_u1());
    }
    m_flags = m__io->read_u1();
    m_certificate_bytes = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_certificate_bytes->push_back(m__io->read_u1());
            i++;
        }
    }
}

signing_t::msg_ecdsa_certificate_t::~msg_ecdsa_certificate_t() {
    _clean_up();
}

void signing_t::msg_ecdsa_certificate_t::_clean_up() {
    if (m_certificate_id) {
        delete m_certificate_id; m_certificate_id = 0;
    }
    if (m_certificate_bytes) {
        delete m_certificate_bytes; m_certificate_bytes = 0;
    }
}

signing_t::msg_ecdsa_signature_t::msg_ecdsa_signature_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, signing_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_certificate_id = 0;
    m_signature = 0;
    m_signed_messages = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void signing_t::msg_ecdsa_signature_t::_read() {
    m_flags = m__io->read_u1();
    m_stream_counter = m__io->read_u1();
    m_on_demand_counter = m__io->read_u1();
    m_certificate_id = new std::vector<uint8_t>();
    const int l_certificate_id = 4;
    for (int i = 0; i < l_certificate_id; i++) {
        m_certificate_id->push_back(m__io->read_u1());
    }
    m_signature = new std::vector<uint8_t>();
    const int l_signature = 64;
    for (int i = 0; i < l_signature; i++) {
        m_signature->push_back(m__io->read_u1());
    }
    m_signed_messages = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_signed_messages->push_back(m__io->read_u1());
            i++;
        }
    }
}

signing_t::msg_ecdsa_signature_t::~msg_ecdsa_signature_t() {
    _clean_up();
}

void signing_t::msg_ecdsa_signature_t::_clean_up() {
    if (m_certificate_id) {
        delete m_certificate_id; m_certificate_id = 0;
    }
    if (m_signature) {
        delete m_signature; m_signature = 0;
    }
    if (m_signed_messages) {
        delete m_signed_messages; m_signed_messages = 0;
    }
}
