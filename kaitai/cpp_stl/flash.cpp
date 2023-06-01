// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "flash.h"

flash_t::flash_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, flash_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void flash_t::_read() {
}

flash_t::~flash_t() {
    _clean_up();
}

void flash_t::_clean_up() {
}

flash_t::msg_flash_done_t::msg_flash_done_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, flash_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void flash_t::msg_flash_done_t::_read() {
    m_response = m__io->read_u1();
}

flash_t::msg_flash_done_t::~msg_flash_done_t() {
    _clean_up();
}

void flash_t::msg_flash_done_t::_clean_up() {
}

flash_t::msg_m25_flash_write_status_t::msg_m25_flash_write_status_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, flash_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_status = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void flash_t::msg_m25_flash_write_status_t::_read() {
    m_status = new std::vector<uint8_t>();
    const int l_status = 1;
    for (int i = 0; i < l_status; i++) {
        m_status->push_back(m__io->read_u1());
    }
}

flash_t::msg_m25_flash_write_status_t::~msg_m25_flash_write_status_t() {
    _clean_up();
}

void flash_t::msg_m25_flash_write_status_t::_clean_up() {
    if (m_status) {
        delete m_status; m_status = 0;
    }
}

flash_t::msg_flash_read_resp_t::msg_flash_read_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, flash_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_addr_start = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void flash_t::msg_flash_read_resp_t::_read() {
    m_target = m__io->read_u1();
    m_addr_start = new std::vector<uint8_t>();
    const int l_addr_start = 3;
    for (int i = 0; i < l_addr_start; i++) {
        m_addr_start->push_back(m__io->read_u1());
    }
    m_addr_len = m__io->read_u1();
}

flash_t::msg_flash_read_resp_t::~msg_flash_read_resp_t() {
    _clean_up();
}

void flash_t::msg_flash_read_resp_t::_clean_up() {
    if (m_addr_start) {
        delete m_addr_start; m_addr_start = 0;
    }
}

flash_t::msg_flash_erase_t::msg_flash_erase_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, flash_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void flash_t::msg_flash_erase_t::_read() {
    m_target = m__io->read_u1();
    m_sector_num = m__io->read_u4le();
}

flash_t::msg_flash_erase_t::~msg_flash_erase_t() {
    _clean_up();
}

void flash_t::msg_flash_erase_t::_clean_up() {
}

flash_t::msg_stm_unique_id_resp_t::msg_stm_unique_id_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, flash_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_stm_id = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void flash_t::msg_stm_unique_id_resp_t::_read() {
    m_stm_id = new std::vector<uint8_t>();
    const int l_stm_id = 12;
    for (int i = 0; i < l_stm_id; i++) {
        m_stm_id->push_back(m__io->read_u1());
    }
}

flash_t::msg_stm_unique_id_resp_t::~msg_stm_unique_id_resp_t() {
    _clean_up();
}

void flash_t::msg_stm_unique_id_resp_t::_clean_up() {
    if (m_stm_id) {
        delete m_stm_id; m_stm_id = 0;
    }
}

flash_t::msg_stm_unique_id_req_t::msg_stm_unique_id_req_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, flash_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void flash_t::msg_stm_unique_id_req_t::_read() {
}

flash_t::msg_stm_unique_id_req_t::~msg_stm_unique_id_req_t() {
    _clean_up();
}

void flash_t::msg_stm_unique_id_req_t::_clean_up() {
}

flash_t::msg_flash_program_t::msg_flash_program_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, flash_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_addr_start = 0;
    m_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void flash_t::msg_flash_program_t::_read() {
    m_target = m__io->read_u1();
    m_addr_start = new std::vector<uint8_t>();
    const int l_addr_start = 3;
    for (int i = 0; i < l_addr_start; i++) {
        m_addr_start->push_back(m__io->read_u1());
    }
    m_addr_len = m__io->read_u1();
    m_data = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_data->push_back(m__io->read_u1());
            i++;
        }
    }
}

flash_t::msg_flash_program_t::~msg_flash_program_t() {
    _clean_up();
}

void flash_t::msg_flash_program_t::_clean_up() {
    if (m_addr_start) {
        delete m_addr_start; m_addr_start = 0;
    }
    if (m_data) {
        delete m_data; m_data = 0;
    }
}

flash_t::msg_flash_read_req_t::msg_flash_read_req_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, flash_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_addr_start = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void flash_t::msg_flash_read_req_t::_read() {
    m_target = m__io->read_u1();
    m_addr_start = new std::vector<uint8_t>();
    const int l_addr_start = 3;
    for (int i = 0; i < l_addr_start; i++) {
        m_addr_start->push_back(m__io->read_u1());
    }
    m_addr_len = m__io->read_u1();
}

flash_t::msg_flash_read_req_t::~msg_flash_read_req_t() {
    _clean_up();
}

void flash_t::msg_flash_read_req_t::_clean_up() {
    if (m_addr_start) {
        delete m_addr_start; m_addr_start = 0;
    }
}

flash_t::msg_stm_flash_unlock_sector_t::msg_stm_flash_unlock_sector_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, flash_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void flash_t::msg_stm_flash_unlock_sector_t::_read() {
    m_sector = m__io->read_u4le();
}

flash_t::msg_stm_flash_unlock_sector_t::~msg_stm_flash_unlock_sector_t() {
    _clean_up();
}

void flash_t::msg_stm_flash_unlock_sector_t::_clean_up() {
}

flash_t::msg_stm_flash_lock_sector_t::msg_stm_flash_lock_sector_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, flash_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void flash_t::msg_stm_flash_lock_sector_t::_read() {
    m_sector = m__io->read_u4le();
}

flash_t::msg_stm_flash_lock_sector_t::~msg_stm_flash_lock_sector_t() {
    _clean_up();
}

void flash_t::msg_stm_flash_lock_sector_t::_clean_up() {
}
