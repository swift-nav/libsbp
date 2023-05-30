// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "system.h"

system_t::system_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void system_t::_read() {
}

system_t::~system_t() {
    _clean_up();
}

void system_t::_clean_up() {
}

system_t::msg_heartbeat_t::msg_heartbeat_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void system_t::msg_heartbeat_t::_read() {
    m_flags = m__io->read_u4le();
}

system_t::msg_heartbeat_t::~msg_heartbeat_t() {
    _clean_up();
}

void system_t::msg_heartbeat_t::_clean_up() {
}

system_t::msg_status_journal_t::msg_status_journal_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_journal = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void system_t::msg_status_journal_t::_read() {
    m_reporting_system = m__io->read_u2le();
    m_sbp_version = m__io->read_u2le();
    m_total_status_reports = m__io->read_u4le();
    m_sequence_descriptor = m__io->read_u1();
    m_journal = new std::vector<status_journal_item_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_journal->push_back(new status_journal_item_t(m__io, this, m__root));
            i++;
        }
    }
}

system_t::msg_status_journal_t::~msg_status_journal_t() {
    _clean_up();
}

void system_t::msg_status_journal_t::_clean_up() {
    if (m_journal) {
        for (std::vector<status_journal_item_t*>::iterator it = m_journal->begin(); it != m_journal->end(); ++it) {
            delete *it;
        }
        delete m_journal; m_journal = 0;
    }
}

system_t::msg_ins_status_t::msg_ins_status_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void system_t::msg_ins_status_t::_read() {
    m_flags = m__io->read_u4le();
}

system_t::msg_ins_status_t::~msg_ins_status_t() {
    _clean_up();
}

void system_t::msg_ins_status_t::_clean_up() {
}

system_t::msg_gnss_time_offset_t::msg_gnss_time_offset_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void system_t::msg_gnss_time_offset_t::_read() {
    m_weeks = m__io->read_s2le();
    m_milliseconds = m__io->read_s4le();
    m_microseconds = m__io->read_s2le();
    m_flags = m__io->read_u1();
}

system_t::msg_gnss_time_offset_t::~msg_gnss_time_offset_t() {
    _clean_up();
}

void system_t::msg_gnss_time_offset_t::_clean_up() {
}

system_t::msg_csac_telemetry_t::msg_csac_telemetry_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void system_t::msg_csac_telemetry_t::_read() {
    m_id = m__io->read_u1();
    m_telemetry = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

system_t::msg_csac_telemetry_t::~msg_csac_telemetry_t() {
    _clean_up();
}

void system_t::msg_csac_telemetry_t::_clean_up() {
}

system_t::msg_pps_time_t::msg_pps_time_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void system_t::msg_pps_time_t::_read() {
    m_time = m__io->read_u8le();
    m_flags = m__io->read_u1();
}

system_t::msg_pps_time_t::~msg_pps_time_t() {
    _clean_up();
}

void system_t::msg_pps_time_t::_clean_up() {
}

system_t::msg_ins_updates_t::msg_ins_updates_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void system_t::msg_ins_updates_t::_read() {
    m_tow = m__io->read_u4le();
    m_gnsspos = m__io->read_u1();
    m_gnssvel = m__io->read_u1();
    m_wheelticks = m__io->read_u1();
    m_speed = m__io->read_u1();
    m_nhc = m__io->read_u1();
    m_zerovel = m__io->read_u1();
}

system_t::msg_ins_updates_t::~msg_ins_updates_t() {
    _clean_up();
}

void system_t::msg_ins_updates_t::_clean_up() {
}

system_t::msg_dgnss_status_t::msg_dgnss_status_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void system_t::msg_dgnss_status_t::_read() {
    m_flags = m__io->read_u1();
    m_latency = m__io->read_u2le();
    m_num_signals = m__io->read_u1();
    m_source = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

system_t::msg_dgnss_status_t::~msg_dgnss_status_t() {
    _clean_up();
}

void system_t::msg_dgnss_status_t::_clean_up() {
}

system_t::msg_csac_telemetry_labels_t::msg_csac_telemetry_labels_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void system_t::msg_csac_telemetry_labels_t::_read() {
    m_id = m__io->read_u1();
    m_telemetry_labels = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

system_t::msg_csac_telemetry_labels_t::~msg_csac_telemetry_labels_t() {
    _clean_up();
}

void system_t::msg_csac_telemetry_labels_t::_clean_up() {
}

system_t::msg_startup_t::msg_startup_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void system_t::msg_startup_t::_read() {
    m_cause = m__io->read_u1();
    m_startup_type = m__io->read_u1();
    m_reserved = m__io->read_u2le();
}

system_t::msg_startup_t::~msg_startup_t() {
    _clean_up();
}

void system_t::msg_startup_t::_clean_up() {
}

system_t::msg_group_meta_t::msg_group_meta_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_group_msgs = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void system_t::msg_group_meta_t::_read() {
    m_group_id = m__io->read_u1();
    m_flags = m__io->read_u1();
    m_n_group_msgs = m__io->read_u1();
    m_group_msgs = new std::vector<uint16_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_group_msgs->push_back(m__io->read_u2le());
            i++;
        }
    }
}

system_t::msg_group_meta_t::~msg_group_meta_t() {
    _clean_up();
}

void system_t::msg_group_meta_t::_clean_up() {
    if (m_group_msgs) {
        delete m_group_msgs; m_group_msgs = 0;
    }
}

system_t::msg_sensor_aid_event_t::msg_sensor_aid_event_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void system_t::msg_sensor_aid_event_t::_read() {
    m_time = m__io->read_u4le();
    m_sensor_type = m__io->read_u1();
    m_sensor_id = m__io->read_u2le();
    m_sensor_state = m__io->read_u1();
    m_n_available_meas = m__io->read_u1();
    m_n_attempted_meas = m__io->read_u1();
    m_n_accepted_meas = m__io->read_u1();
    m_flags = m__io->read_u4le();
}

system_t::msg_sensor_aid_event_t::~msg_sensor_aid_event_t() {
    _clean_up();
}

void system_t::msg_sensor_aid_event_t::_clean_up() {
}

system_t::sub_system_report_t::sub_system_report_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void system_t::sub_system_report_t::_read() {
    m_component = m__io->read_u2le();
    m_generic = m__io->read_u1();
    m_specific = m__io->read_u1();
}

system_t::sub_system_report_t::~sub_system_report_t() {
    _clean_up();
}

void system_t::sub_system_report_t::_clean_up() {
}

system_t::msg_status_report_t::msg_status_report_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
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

void system_t::msg_status_report_t::_read() {
    m_reporting_system = m__io->read_u2le();
    m_sbp_version = m__io->read_u2le();
    m_sequence = m__io->read_u4le();
    m_uptime = m__io->read_u4le();
    m_status = new std::vector<sub_system_report_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_status->push_back(new sub_system_report_t(m__io, this, m__root));
            i++;
        }
    }
}

system_t::msg_status_report_t::~msg_status_report_t() {
    _clean_up();
}

void system_t::msg_status_report_t::_clean_up() {
    if (m_status) {
        for (std::vector<sub_system_report_t*>::iterator it = m_status->begin(); it != m_status->end(); ++it) {
            delete *it;
        }
        delete m_status; m_status = 0;
    }
}

system_t::status_journal_item_t::status_journal_item_t(kaitai::kstream* p__io, system_t::msg_status_journal_t* p__parent, system_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_report = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void system_t::status_journal_item_t::_read() {
    m_uptime = m__io->read_u4le();
    m_report = new sub_system_report_t(m__io, this, m__root);
}

system_t::status_journal_item_t::~status_journal_item_t() {
    _clean_up();
}

void system_t::status_journal_item_t::_clean_up() {
    if (m_report) {
        delete m_report; m_report = 0;
    }
}
