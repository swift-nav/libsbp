// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "file_io.h"

file_io_t::file_io_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, file_io_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void file_io_t::_read() {
}

file_io_t::~file_io_t() {
    _clean_up();
}

void file_io_t::_clean_up() {
}

file_io_t::msg_fileio_write_req_t::msg_fileio_write_req_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, file_io_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void file_io_t::msg_fileio_write_req_t::_read() {
    m_sequence = m__io->read_u4le();
    m_offset = m__io->read_u4le();
    m_filename = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
    m_data = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_data->push_back(m__io->read_u1());
            i++;
        }
    }
}

file_io_t::msg_fileio_write_req_t::~msg_fileio_write_req_t() {
    _clean_up();
}

void file_io_t::msg_fileio_write_req_t::_clean_up() {
    if (m_data) {
        delete m_data; m_data = 0;
    }
}

file_io_t::msg_fileio_config_resp_t::msg_fileio_config_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, file_io_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void file_io_t::msg_fileio_config_resp_t::_read() {
    m_sequence = m__io->read_u4le();
    m_window_size = m__io->read_u4le();
    m_batch_size = m__io->read_u4le();
    m_fileio_version = m__io->read_u4le();
}

file_io_t::msg_fileio_config_resp_t::~msg_fileio_config_resp_t() {
    _clean_up();
}

void file_io_t::msg_fileio_config_resp_t::_clean_up() {
}

file_io_t::msg_fileio_remove_t::msg_fileio_remove_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, file_io_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void file_io_t::msg_fileio_remove_t::_read() {
    m_filename = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

file_io_t::msg_fileio_remove_t::~msg_fileio_remove_t() {
    _clean_up();
}

void file_io_t::msg_fileio_remove_t::_clean_up() {
}

file_io_t::msg_fileio_config_req_t::msg_fileio_config_req_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, file_io_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void file_io_t::msg_fileio_config_req_t::_read() {
    m_sequence = m__io->read_u4le();
}

file_io_t::msg_fileio_config_req_t::~msg_fileio_config_req_t() {
    _clean_up();
}

void file_io_t::msg_fileio_config_req_t::_clean_up() {
}

file_io_t::msg_fileio_read_dir_req_t::msg_fileio_read_dir_req_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, file_io_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void file_io_t::msg_fileio_read_dir_req_t::_read() {
    m_sequence = m__io->read_u4le();
    m_offset = m__io->read_u4le();
    m_dirname = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

file_io_t::msg_fileio_read_dir_req_t::~msg_fileio_read_dir_req_t() {
    _clean_up();
}

void file_io_t::msg_fileio_read_dir_req_t::_clean_up() {
}

file_io_t::msg_fileio_write_resp_t::msg_fileio_write_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, file_io_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void file_io_t::msg_fileio_write_resp_t::_read() {
    m_sequence = m__io->read_u4le();
}

file_io_t::msg_fileio_write_resp_t::~msg_fileio_write_resp_t() {
    _clean_up();
}

void file_io_t::msg_fileio_write_resp_t::_clean_up() {
}

file_io_t::msg_fileio_read_dir_resp_t::msg_fileio_read_dir_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, file_io_t* p__root) : kaitai::kstruct(p__io) {
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

void file_io_t::msg_fileio_read_dir_resp_t::_read() {
    m_sequence = m__io->read_u4le();
    m_contents = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_contents->push_back(m__io->read_u1());
            i++;
        }
    }
}

file_io_t::msg_fileio_read_dir_resp_t::~msg_fileio_read_dir_resp_t() {
    _clean_up();
}

void file_io_t::msg_fileio_read_dir_resp_t::_clean_up() {
    if (m_contents) {
        delete m_contents; m_contents = 0;
    }
}

file_io_t::msg_fileio_read_req_t::msg_fileio_read_req_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, file_io_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void file_io_t::msg_fileio_read_req_t::_read() {
    m_sequence = m__io->read_u4le();
    m_offset = m__io->read_u4le();
    m_chunk_size = m__io->read_u1();
    m_filename = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

file_io_t::msg_fileio_read_req_t::~msg_fileio_read_req_t() {
    _clean_up();
}

void file_io_t::msg_fileio_read_req_t::_clean_up() {
}

file_io_t::msg_fileio_read_resp_t::msg_fileio_read_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, file_io_t* p__root) : kaitai::kstruct(p__io) {
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

void file_io_t::msg_fileio_read_resp_t::_read() {
    m_sequence = m__io->read_u4le();
    m_contents = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_contents->push_back(m__io->read_u1());
            i++;
        }
    }
}

file_io_t::msg_fileio_read_resp_t::~msg_fileio_read_resp_t() {
    _clean_up();
}

void file_io_t::msg_fileio_read_resp_t::_clean_up() {
    if (m_contents) {
        delete m_contents; m_contents = 0;
    }
}
