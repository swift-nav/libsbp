// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "piksi.h"

piksi_t::piksi_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::_read() {
}

piksi_t::~piksi_t() {
    _clean_up();
}

void piksi_t::_clean_up() {
}

piksi_t::msg_network_state_resp_t::msg_network_state_resp_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_ipv4_address = 0;
    m_ipv6_address = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_network_state_resp_t::_read() {
    m_ipv4_address = new std::vector<uint8_t>();
    const int l_ipv4_address = 4;
    for (int i = 0; i < l_ipv4_address; i++) {
        m_ipv4_address->push_back(m__io->read_u1());
    }
    m_ipv4_mask_size = m__io->read_u1();
    m_ipv6_address = new std::vector<uint8_t>();
    const int l_ipv6_address = 16;
    for (int i = 0; i < l_ipv6_address; i++) {
        m_ipv6_address->push_back(m__io->read_u1());
    }
    m_ipv6_mask_size = m__io->read_u1();
    m_rx_bytes = m__io->read_u4le();
    m_tx_bytes = m__io->read_u4le();
    m_interface_name = kaitai::kstream::bytes_to_str(m__io->read_bytes(16), std::string("ascii"));
    m_flags = m__io->read_u4le();
}

piksi_t::msg_network_state_resp_t::~msg_network_state_resp_t() {
    _clean_up();
}

void piksi_t::msg_network_state_resp_t::_clean_up() {
    if (m_ipv4_address) {
        delete m_ipv4_address; m_ipv4_address = 0;
    }
    if (m_ipv6_address) {
        delete m_ipv6_address; m_ipv6_address = 0;
    }
}

piksi_t::network_usage_t::network_usage_t(kaitai::kstream* p__io, piksi_t::msg_network_bandwidth_usage_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::network_usage_t::_read() {
    m_duration = m__io->read_u8le();
    m_total_bytes = m__io->read_u8le();
    m_rx_bytes = m__io->read_u4le();
    m_tx_bytes = m__io->read_u4le();
    m_interface_name = kaitai::kstream::bytes_to_str(m__io->read_bytes(16), std::string("ascii"));
}

piksi_t::network_usage_t::~network_usage_t() {
    _clean_up();
}

void piksi_t::network_usage_t::_clean_up() {
}

piksi_t::msg_command_resp_t::msg_command_resp_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_command_resp_t::_read() {
    m_sequence = m__io->read_u4le();
    m_code = m__io->read_s4le();
}

piksi_t::msg_command_resp_t::~msg_command_resp_t() {
    _clean_up();
}

void piksi_t::msg_command_resp_t::_clean_up() {
}

piksi_t::msg_command_output_t::msg_command_output_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_command_output_t::_read() {
    m_sequence = m__io->read_u4le();
    m_line = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

piksi_t::msg_command_output_t::~msg_command_output_t() {
    _clean_up();
}

void piksi_t::msg_command_output_t::_clean_up() {
}

piksi_t::latency_t::latency_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::latency_t::_read() {
    m_avg = m__io->read_s4le();
    m_lmin = m__io->read_s4le();
    m_lmax = m__io->read_s4le();
    m_current = m__io->read_s4le();
}

piksi_t::latency_t::~latency_t() {
    _clean_up();
}

void piksi_t::latency_t::_clean_up() {
}

piksi_t::msg_thread_state_t::msg_thread_state_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_thread_state_t::_read() {
    m_name = kaitai::kstream::bytes_to_str(m__io->read_bytes(20), std::string("ascii"));
    m_cpu = m__io->read_u2le();
    m_stack_free = m__io->read_u4le();
}

piksi_t::msg_thread_state_t::~msg_thread_state_t() {
    _clean_up();
}

void piksi_t::msg_thread_state_t::_clean_up() {
}

piksi_t::msg_uart_state_depa_t::msg_uart_state_depa_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_uart_a = 0;
    m_uart_b = 0;
    m_uart_ftdi = 0;
    m_latency = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_uart_state_depa_t::_read() {
    m_uart_a = new uart_channel_t(m__io, this, m__root);
    m_uart_b = new uart_channel_t(m__io, this, m__root);
    m_uart_ftdi = new uart_channel_t(m__io, this, m__root);
    m_latency = new latency_t(m__io, this, m__root);
}

piksi_t::msg_uart_state_depa_t::~msg_uart_state_depa_t() {
    _clean_up();
}

void piksi_t::msg_uart_state_depa_t::_clean_up() {
    if (m_uart_a) {
        delete m_uart_a; m_uart_a = 0;
    }
    if (m_uart_b) {
        delete m_uart_b; m_uart_b = 0;
    }
    if (m_uart_ftdi) {
        delete m_uart_ftdi; m_uart_ftdi = 0;
    }
    if (m_latency) {
        delete m_latency; m_latency = 0;
    }
}

piksi_t::msg_network_state_req_t::msg_network_state_req_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_network_state_req_t::_read() {
}

piksi_t::msg_network_state_req_t::~msg_network_state_req_t() {
    _clean_up();
}

void piksi_t::msg_network_state_req_t::_clean_up() {
}

piksi_t::msg_device_monitor_t::msg_device_monitor_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_device_monitor_t::_read() {
    m_dev_vin = m__io->read_s2le();
    m_cpu_vint = m__io->read_s2le();
    m_cpu_vaux = m__io->read_s2le();
    m_cpu_temperature = m__io->read_s2le();
    m_fe_temperature = m__io->read_s2le();
}

piksi_t::msg_device_monitor_t::~msg_device_monitor_t() {
    _clean_up();
}

void piksi_t::msg_device_monitor_t::_clean_up() {
}

piksi_t::msg_mask_satellite_dep_t::msg_mask_satellite_dep_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_mask_satellite_dep_t::_read() {
    m_mask = m__io->read_u1();
    m_sid = new gnss_t::gnss_signal_dep_t(m__io, this, m__root);
}

piksi_t::msg_mask_satellite_dep_t::~msg_mask_satellite_dep_t() {
    _clean_up();
}

void piksi_t::msg_mask_satellite_dep_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

piksi_t::msg_uart_state_t::msg_uart_state_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_uart_a = 0;
    m_uart_b = 0;
    m_uart_ftdi = 0;
    m_latency = 0;
    m_obs_period = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_uart_state_t::_read() {
    m_uart_a = new uart_channel_t(m__io, this, m__root);
    m_uart_b = new uart_channel_t(m__io, this, m__root);
    m_uart_ftdi = new uart_channel_t(m__io, this, m__root);
    m_latency = new latency_t(m__io, this, m__root);
    m_obs_period = new period_t(m__io, this, m__root);
}

piksi_t::msg_uart_state_t::~msg_uart_state_t() {
    _clean_up();
}

void piksi_t::msg_uart_state_t::_clean_up() {
    if (m_uart_a) {
        delete m_uart_a; m_uart_a = 0;
    }
    if (m_uart_b) {
        delete m_uart_b; m_uart_b = 0;
    }
    if (m_uart_ftdi) {
        delete m_uart_ftdi; m_uart_ftdi = 0;
    }
    if (m_latency) {
        delete m_latency; m_latency = 0;
    }
    if (m_obs_period) {
        delete m_obs_period; m_obs_period = 0;
    }
}

piksi_t::msg_specan_t::msg_specan_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_t = 0;
    m_amplitude_value = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_specan_t::_read() {
    m_channel_tag = m__io->read_u2le();
    m_t = new gnss_t::gps_time_t(m__io, this, m__root);
    m_freq_ref = m__io->read_f4le();
    m_freq_step = m__io->read_f4le();
    m_amplitude_ref = m__io->read_f4le();
    m_amplitude_unit = m__io->read_f4le();
    m_amplitude_value = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_amplitude_value->push_back(m__io->read_u1());
            i++;
        }
    }
}

piksi_t::msg_specan_t::~msg_specan_t() {
    _clean_up();
}

void piksi_t::msg_specan_t::_clean_up() {
    if (m_t) {
        delete m_t; m_t = 0;
    }
    if (m_amplitude_value) {
        delete m_amplitude_value; m_amplitude_value = 0;
    }
}

piksi_t::msg_iar_state_t::msg_iar_state_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_iar_state_t::_read() {
    m_num_hyps = m__io->read_u4le();
}

piksi_t::msg_iar_state_t::~msg_iar_state_t() {
    _clean_up();
}

void piksi_t::msg_iar_state_t::_clean_up() {
}

piksi_t::msg_almanac_t::msg_almanac_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_almanac_t::_read() {
}

piksi_t::msg_almanac_t::~msg_almanac_t() {
    _clean_up();
}

void piksi_t::msg_almanac_t::_clean_up() {
}

piksi_t::msg_reset_filters_t::msg_reset_filters_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_reset_filters_t::_read() {
    m_filter = m__io->read_u1();
}

piksi_t::msg_reset_filters_t::~msg_reset_filters_t() {
    _clean_up();
}

void piksi_t::msg_reset_filters_t::_clean_up() {
}

piksi_t::uart_channel_t::uart_channel_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::uart_channel_t::_read() {
    m_tx_throughput = m__io->read_f4le();
    m_rx_throughput = m__io->read_f4le();
    m_crc_error_count = m__io->read_u2le();
    m_io_error_count = m__io->read_u2le();
    m_tx_buffer_level = m__io->read_u1();
    m_rx_buffer_level = m__io->read_u1();
}

piksi_t::uart_channel_t::~uart_channel_t() {
    _clean_up();
}

void piksi_t::uart_channel_t::_clean_up() {
}

piksi_t::msg_command_req_t::msg_command_req_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_command_req_t::_read() {
    m_sequence = m__io->read_u4le();
    m_command = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

piksi_t::msg_command_req_t::~msg_command_req_t() {
    _clean_up();
}

void piksi_t::msg_command_req_t::_clean_up() {
}

piksi_t::msg_mask_satellite_t::msg_mask_satellite_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_mask_satellite_t::_read() {
    m_mask = m__io->read_u1();
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
}

piksi_t::msg_mask_satellite_t::~msg_mask_satellite_t() {
    _clean_up();
}

void piksi_t::msg_mask_satellite_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

piksi_t::msg_network_bandwidth_usage_t::msg_network_bandwidth_usage_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_interfaces = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_network_bandwidth_usage_t::_read() {
    m_interfaces = new std::vector<network_usage_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_interfaces->push_back(new network_usage_t(m__io, this, m__root));
            i++;
        }
    }
}

piksi_t::msg_network_bandwidth_usage_t::~msg_network_bandwidth_usage_t() {
    _clean_up();
}

void piksi_t::msg_network_bandwidth_usage_t::_clean_up() {
    if (m_interfaces) {
        for (std::vector<network_usage_t*>::iterator it = m_interfaces->begin(); it != m_interfaces->end(); ++it) {
            delete *it;
        }
        delete m_interfaces; m_interfaces = 0;
    }
}

piksi_t::msg_reset_t::msg_reset_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_reset_t::_read() {
    m_flags = m__io->read_u4le();
}

piksi_t::msg_reset_t::~msg_reset_t() {
    _clean_up();
}

void piksi_t::msg_reset_t::_clean_up() {
}

piksi_t::msg_cell_modem_status_t::msg_cell_modem_status_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_reserved = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_cell_modem_status_t::_read() {
    m_signal_strength = m__io->read_s1();
    m_signal_error_rate = m__io->read_f4le();
    m_reserved = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_reserved->push_back(m__io->read_u1());
            i++;
        }
    }
}

piksi_t::msg_cell_modem_status_t::~msg_cell_modem_status_t() {
    _clean_up();
}

void piksi_t::msg_cell_modem_status_t::_clean_up() {
    if (m_reserved) {
        delete m_reserved; m_reserved = 0;
    }
}

piksi_t::msg_front_end_gain_t::msg_front_end_gain_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_rf_gain = 0;
    m_if_gain = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_front_end_gain_t::_read() {
    m_rf_gain = new std::vector<int8_t>();
    const int l_rf_gain = 8;
    for (int i = 0; i < l_rf_gain; i++) {
        m_rf_gain->push_back(m__io->read_s1());
    }
    m_if_gain = new std::vector<int8_t>();
    const int l_if_gain = 8;
    for (int i = 0; i < l_if_gain; i++) {
        m_if_gain->push_back(m__io->read_s1());
    }
}

piksi_t::msg_front_end_gain_t::~msg_front_end_gain_t() {
    _clean_up();
}

void piksi_t::msg_front_end_gain_t::_clean_up() {
    if (m_rf_gain) {
        delete m_rf_gain; m_rf_gain = 0;
    }
    if (m_if_gain) {
        delete m_if_gain; m_if_gain = 0;
    }
}

piksi_t::msg_reset_dep_t::msg_reset_dep_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_reset_dep_t::_read() {
}

piksi_t::msg_reset_dep_t::~msg_reset_dep_t() {
    _clean_up();
}

void piksi_t::msg_reset_dep_t::_clean_up() {
}

piksi_t::msg_set_time_t::msg_set_time_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_set_time_t::_read() {
}

piksi_t::msg_set_time_t::~msg_set_time_t() {
    _clean_up();
}

void piksi_t::msg_set_time_t::_clean_up() {
}

piksi_t::msg_cw_results_t::msg_cw_results_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_cw_results_t::_read() {
}

piksi_t::msg_cw_results_t::~msg_cw_results_t() {
    _clean_up();
}

void piksi_t::msg_cw_results_t::_clean_up() {
}

piksi_t::msg_specan_dep_t::msg_specan_dep_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_t = 0;
    m_amplitude_value = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_specan_dep_t::_read() {
    m_channel_tag = m__io->read_u2le();
    m_t = new gnss_t::gps_time_dep_t(m__io, this, m__root);
    m_freq_ref = m__io->read_f4le();
    m_freq_step = m__io->read_f4le();
    m_amplitude_ref = m__io->read_f4le();
    m_amplitude_unit = m__io->read_f4le();
    m_amplitude_value = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_amplitude_value->push_back(m__io->read_u1());
            i++;
        }
    }
}

piksi_t::msg_specan_dep_t::~msg_specan_dep_t() {
    _clean_up();
}

void piksi_t::msg_specan_dep_t::_clean_up() {
    if (m_t) {
        delete m_t; m_t = 0;
    }
    if (m_amplitude_value) {
        delete m_amplitude_value; m_amplitude_value = 0;
    }
}

piksi_t::msg_init_base_dep_t::msg_init_base_dep_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_init_base_dep_t::_read() {
}

piksi_t::msg_init_base_dep_t::~msg_init_base_dep_t() {
    _clean_up();
}

void piksi_t::msg_init_base_dep_t::_clean_up() {
}

piksi_t::period_t::period_t(kaitai::kstream* p__io, piksi_t::msg_uart_state_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::period_t::_read() {
    m_avg = m__io->read_s4le();
    m_pmin = m__io->read_s4le();
    m_pmax = m__io->read_s4le();
    m_current = m__io->read_s4le();
}

piksi_t::period_t::~period_t() {
    _clean_up();
}

void piksi_t::period_t::_clean_up() {
}

piksi_t::msg_cw_start_t::msg_cw_start_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, piksi_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void piksi_t::msg_cw_start_t::_read() {
}

piksi_t::msg_cw_start_t::~msg_cw_start_t() {
    _clean_up();
}

void piksi_t::msg_cw_start_t::_clean_up() {
}
