// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "linux.h"

linux_t::linux_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, linux_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void linux_t::_read() {
}

linux_t::~linux_t() {
    _clean_up();
}

void linux_t::_clean_up() {
}

linux_t::msg_linux_socket_usage_t::msg_linux_socket_usage_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, linux_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_socket_state_counts = 0;
    m_socket_type_counts = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void linux_t::msg_linux_socket_usage_t::_read() {
    m_avg_queue_depth = m__io->read_u4le();
    m_max_queue_depth = m__io->read_u4le();
    m_socket_state_counts = new std::vector<uint16_t>();
    const int l_socket_state_counts = 16;
    for (int i = 0; i < l_socket_state_counts; i++) {
        m_socket_state_counts->push_back(m__io->read_u2le());
    }
    m_socket_type_counts = new std::vector<uint16_t>();
    const int l_socket_type_counts = 16;
    for (int i = 0; i < l_socket_type_counts; i++) {
        m_socket_type_counts->push_back(m__io->read_u2le());
    }
}

linux_t::msg_linux_socket_usage_t::~msg_linux_socket_usage_t() {
    _clean_up();
}

void linux_t::msg_linux_socket_usage_t::_clean_up() {
    if (m_socket_state_counts) {
        delete m_socket_state_counts; m_socket_state_counts = 0;
    }
    if (m_socket_type_counts) {
        delete m_socket_type_counts; m_socket_type_counts = 0;
    }
}

linux_t::msg_linux_sys_state_t::msg_linux_sys_state_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, linux_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void linux_t::msg_linux_sys_state_t::_read() {
    m_mem_total = m__io->read_u2le();
    m_pcpu = m__io->read_u1();
    m_pmem = m__io->read_u1();
    m_procs_starting = m__io->read_u2le();
    m_procs_stopping = m__io->read_u2le();
    m_pid_count = m__io->read_u2le();
    m_time = m__io->read_u4le();
    m_flags = m__io->read_u1();
}

linux_t::msg_linux_sys_state_t::~msg_linux_sys_state_t() {
    _clean_up();
}

void linux_t::msg_linux_sys_state_t::_clean_up() {
}

linux_t::msg_linux_cpu_state_dep_a_t::msg_linux_cpu_state_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, linux_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void linux_t::msg_linux_cpu_state_dep_a_t::_read() {
    m_index = m__io->read_u1();
    m_pid = m__io->read_u2le();
    m_pcpu = m__io->read_u1();
    m_tname = kaitai::kstream::bytes_to_str(m__io->read_bytes(15), std::string("ascii"));
    m_cmdline = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

linux_t::msg_linux_cpu_state_dep_a_t::~msg_linux_cpu_state_dep_a_t() {
    _clean_up();
}

void linux_t::msg_linux_cpu_state_dep_a_t::_clean_up() {
}

linux_t::msg_linux_mem_state_t::msg_linux_mem_state_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, linux_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void linux_t::msg_linux_mem_state_t::_read() {
    m_index = m__io->read_u1();
    m_pid = m__io->read_u2le();
    m_pmem = m__io->read_u1();
    m_time = m__io->read_u4le();
    m_flags = m__io->read_u1();
    m_tname = kaitai::kstream::bytes_to_str(m__io->read_bytes(15), std::string("ascii"));
    m_cmdline = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

linux_t::msg_linux_mem_state_t::~msg_linux_mem_state_t() {
    _clean_up();
}

void linux_t::msg_linux_mem_state_t::_clean_up() {
}

linux_t::msg_linux_process_fd_count_t::msg_linux_process_fd_count_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, linux_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void linux_t::msg_linux_process_fd_count_t::_read() {
    m_index = m__io->read_u1();
    m_pid = m__io->read_u2le();
    m_fd_count = m__io->read_u2le();
    m_cmdline = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

linux_t::msg_linux_process_fd_count_t::~msg_linux_process_fd_count_t() {
    _clean_up();
}

void linux_t::msg_linux_process_fd_count_t::_clean_up() {
}

linux_t::msg_linux_mem_state_dep_a_t::msg_linux_mem_state_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, linux_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void linux_t::msg_linux_mem_state_dep_a_t::_read() {
    m_index = m__io->read_u1();
    m_pid = m__io->read_u2le();
    m_pmem = m__io->read_u1();
    m_tname = kaitai::kstream::bytes_to_str(m__io->read_bytes(15), std::string("ascii"));
    m_cmdline = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

linux_t::msg_linux_mem_state_dep_a_t::~msg_linux_mem_state_dep_a_t() {
    _clean_up();
}

void linux_t::msg_linux_mem_state_dep_a_t::_clean_up() {
}

linux_t::msg_linux_process_socket_queues_t::msg_linux_process_socket_queues_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, linux_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void linux_t::msg_linux_process_socket_queues_t::_read() {
    m_index = m__io->read_u1();
    m_pid = m__io->read_u2le();
    m_recv_queued = m__io->read_u2le();
    m_send_queued = m__io->read_u2le();
    m_socket_types = m__io->read_u2le();
    m_socket_states = m__io->read_u2le();
    m_address_of_largest = kaitai::kstream::bytes_to_str(m__io->read_bytes(64), std::string("ascii"));
    m_cmdline = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

linux_t::msg_linux_process_socket_queues_t::~msg_linux_process_socket_queues_t() {
    _clean_up();
}

void linux_t::msg_linux_process_socket_queues_t::_clean_up() {
}

linux_t::msg_linux_sys_state_dep_a_t::msg_linux_sys_state_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, linux_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void linux_t::msg_linux_sys_state_dep_a_t::_read() {
    m_mem_total = m__io->read_u2le();
    m_pcpu = m__io->read_u1();
    m_pmem = m__io->read_u1();
    m_procs_starting = m__io->read_u2le();
    m_procs_stopping = m__io->read_u2le();
    m_pid_count = m__io->read_u2le();
}

linux_t::msg_linux_sys_state_dep_a_t::~msg_linux_sys_state_dep_a_t() {
    _clean_up();
}

void linux_t::msg_linux_sys_state_dep_a_t::_clean_up() {
}

linux_t::msg_linux_process_fd_summary_t::msg_linux_process_fd_summary_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, linux_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void linux_t::msg_linux_process_fd_summary_t::_read() {
    m_sys_fd_count = m__io->read_u4le();
    m_most_opened = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

linux_t::msg_linux_process_fd_summary_t::~msg_linux_process_fd_summary_t() {
    _clean_up();
}

void linux_t::msg_linux_process_fd_summary_t::_clean_up() {
}

linux_t::msg_linux_cpu_state_t::msg_linux_cpu_state_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, linux_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void linux_t::msg_linux_cpu_state_t::_read() {
    m_index = m__io->read_u1();
    m_pid = m__io->read_u2le();
    m_pcpu = m__io->read_u1();
    m_time = m__io->read_u4le();
    m_flags = m__io->read_u1();
    m_tname = kaitai::kstream::bytes_to_str(m__io->read_bytes(15), std::string("ascii"));
    m_cmdline = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

linux_t::msg_linux_cpu_state_t::~msg_linux_cpu_state_t() {
    _clean_up();
}

void linux_t::msg_linux_cpu_state_t::_clean_up() {
}

linux_t::msg_linux_process_socket_counts_t::msg_linux_process_socket_counts_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, linux_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void linux_t::msg_linux_process_socket_counts_t::_read() {
    m_index = m__io->read_u1();
    m_pid = m__io->read_u2le();
    m_socket_count = m__io->read_u2le();
    m_socket_types = m__io->read_u2le();
    m_socket_states = m__io->read_u2le();
    m_cmdline = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

linux_t::msg_linux_process_socket_counts_t::~msg_linux_process_socket_counts_t() {
    _clean_up();
}

void linux_t::msg_linux_process_socket_counts_t::_clean_up() {
}
