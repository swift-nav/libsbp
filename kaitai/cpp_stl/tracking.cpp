// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "tracking.h"

tracking_t::tracking_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tracking_t::_read() {
}

tracking_t::~tracking_t() {
    _clean_up();
}

void tracking_t::_clean_up() {
}

tracking_t::msg_tracking_state_detailed_dep_t::msg_tracking_state_detailed_dep_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_tot = 0;
    m_l = 0;
    m_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tracking_t::msg_tracking_state_detailed_dep_t::_read() {
    m_recv_time = m__io->read_u8le();
    m_tot = new gnss_t::gps_time_dep_t(m__io, this, m__root);
    m_p = m__io->read_u4le();
    m_p_std = m__io->read_u2le();
    m_l = new gnss_t::carrier_phase_t(m__io, this, m__root);
    m_cn0 = m__io->read_u1();
    m_lock = m__io->read_u2le();
    m_sid = new gnss_t::gnss_signal_dep_t(m__io, this, m__root);
    m_doppler = m__io->read_s4le();
    m_doppler_std = m__io->read_u2le();
    m_uptime = m__io->read_u4le();
    m_clock_offset = m__io->read_s2le();
    m_clock_drift = m__io->read_s2le();
    m_corr_spacing = m__io->read_u2le();
    m_acceleration = m__io->read_s1();
    m_sync_flags = m__io->read_u1();
    m_tow_flags = m__io->read_u1();
    m_track_flags = m__io->read_u1();
    m_nav_flags = m__io->read_u1();
    m_pset_flags = m__io->read_u1();
    m_misc_flags = m__io->read_u1();
}

tracking_t::msg_tracking_state_detailed_dep_t::~msg_tracking_state_detailed_dep_t() {
    _clean_up();
}

void tracking_t::msg_tracking_state_detailed_dep_t::_clean_up() {
    if (m_tot) {
        delete m_tot; m_tot = 0;
    }
    if (m_l) {
        delete m_l; m_l = 0;
    }
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

tracking_t::tracking_channel_state_dep_b_t::tracking_channel_state_dep_b_t(kaitai::kstream* p__io, tracking_t::msg_tracking_state_dep_b_t* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
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

void tracking_t::tracking_channel_state_dep_b_t::_read() {
    m_state = m__io->read_u1();
    m_sid = new gnss_t::gnss_signal_dep_t(m__io, this, m__root);
    m_cn0 = m__io->read_f4le();
}

tracking_t::tracking_channel_state_dep_b_t::~tracking_channel_state_dep_b_t() {
    _clean_up();
}

void tracking_t::tracking_channel_state_dep_b_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

tracking_t::tracking_channel_state_t::tracking_channel_state_t(kaitai::kstream* p__io, tracking_t::msg_tracking_state_t* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
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

void tracking_t::tracking_channel_state_t::_read() {
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_fcn = m__io->read_u1();
    m_cn0 = m__io->read_u1();
}

tracking_t::tracking_channel_state_t::~tracking_channel_state_t() {
    _clean_up();
}

void tracking_t::tracking_channel_state_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

tracking_t::msg_tracking_state_t::msg_tracking_state_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_states = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tracking_t::msg_tracking_state_t::_read() {
    m_states = new std::vector<tracking_channel_state_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_states->push_back(new tracking_channel_state_t(m__io, this, m__root));
            i++;
        }
    }
}

tracking_t::msg_tracking_state_t::~msg_tracking_state_t() {
    _clean_up();
}

void tracking_t::msg_tracking_state_t::_clean_up() {
    if (m_states) {
        for (std::vector<tracking_channel_state_t*>::iterator it = m_states->begin(); it != m_states->end(); ++it) {
            delete *it;
        }
        delete m_states; m_states = 0;
    }
}

tracking_t::tracking_channel_state_dep_a_t::tracking_channel_state_dep_a_t(kaitai::kstream* p__io, tracking_t::msg_tracking_state_dep_a_t* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tracking_t::tracking_channel_state_dep_a_t::_read() {
    m_state = m__io->read_u1();
    m_prn = m__io->read_u1();
    m_cn0 = m__io->read_f4le();
}

tracking_t::tracking_channel_state_dep_a_t::~tracking_channel_state_dep_a_t() {
    _clean_up();
}

void tracking_t::tracking_channel_state_dep_a_t::_clean_up() {
}

tracking_t::msg_tracking_iq_dep_a_t::msg_tracking_iq_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sid = 0;
    m_corrs = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tracking_t::msg_tracking_iq_dep_a_t::_read() {
    m_channel = m__io->read_u1();
    m_sid = new gnss_t::gnss_signal_dep_t(m__io, this, m__root);
    m_corrs = new std::vector<uint64_t>();
    const int l_corrs = 3;
    for (int i = 0; i < l_corrs; i++) {
        m_corrs->push_back(m__io->read_u8le());
    }
}

tracking_t::msg_tracking_iq_dep_a_t::~msg_tracking_iq_dep_a_t() {
    _clean_up();
}

void tracking_t::msg_tracking_iq_dep_a_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
    if (m_corrs) {
        delete m_corrs; m_corrs = 0;
    }
}

tracking_t::tracking_channel_correlation_dep_t::tracking_channel_correlation_dep_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tracking_t::tracking_channel_correlation_dep_t::_read() {
    m_i = m__io->read_s4le();
    m_q = m__io->read_s4le();
}

tracking_t::tracking_channel_correlation_dep_t::~tracking_channel_correlation_dep_t() {
    _clean_up();
}

void tracking_t::tracking_channel_correlation_dep_t::_clean_up() {
}

tracking_t::msg_tracking_state_dep_a_t::msg_tracking_state_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_states = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tracking_t::msg_tracking_state_dep_a_t::_read() {
    m_states = new std::vector<tracking_channel_state_dep_a_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_states->push_back(new tracking_channel_state_dep_a_t(m__io, this, m__root));
            i++;
        }
    }
}

tracking_t::msg_tracking_state_dep_a_t::~msg_tracking_state_dep_a_t() {
    _clean_up();
}

void tracking_t::msg_tracking_state_dep_a_t::_clean_up() {
    if (m_states) {
        for (std::vector<tracking_channel_state_dep_a_t*>::iterator it = m_states->begin(); it != m_states->end(); ++it) {
            delete *it;
        }
        delete m_states; m_states = 0;
    }
}

tracking_t::msg_measurement_state_t::msg_measurement_state_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_states = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tracking_t::msg_measurement_state_t::_read() {
    m_states = new std::vector<measurement_state_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_states->push_back(new measurement_state_t(m__io, this, m__root));
            i++;
        }
    }
}

tracking_t::msg_measurement_state_t::~msg_measurement_state_t() {
    _clean_up();
}

void tracking_t::msg_measurement_state_t::_clean_up() {
    if (m_states) {
        for (std::vector<measurement_state_t*>::iterator it = m_states->begin(); it != m_states->end(); ++it) {
            delete *it;
        }
        delete m_states; m_states = 0;
    }
}

tracking_t::tracking_channel_correlation_t::tracking_channel_correlation_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tracking_t::tracking_channel_correlation_t::_read() {
    m_i = m__io->read_s2le();
    m_q = m__io->read_s2le();
}

tracking_t::tracking_channel_correlation_t::~tracking_channel_correlation_t() {
    _clean_up();
}

void tracking_t::tracking_channel_correlation_t::_clean_up() {
}

tracking_t::msg_tracking_iq_t::msg_tracking_iq_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sid = 0;
    m_corrs = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tracking_t::msg_tracking_iq_t::_read() {
    m_channel = m__io->read_u1();
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_corrs = new std::vector<uint64_t>();
    const int l_corrs = 3;
    for (int i = 0; i < l_corrs; i++) {
        m_corrs->push_back(m__io->read_u8le());
    }
}

tracking_t::msg_tracking_iq_t::~msg_tracking_iq_t() {
    _clean_up();
}

void tracking_t::msg_tracking_iq_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
    if (m_corrs) {
        delete m_corrs; m_corrs = 0;
    }
}

tracking_t::msg_tracking_state_detailed_dep_a_t::msg_tracking_state_detailed_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_tot = 0;
    m_l = 0;
    m_sid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tracking_t::msg_tracking_state_detailed_dep_a_t::_read() {
    m_recv_time = m__io->read_u8le();
    m_tot = new gnss_t::gps_time_t(m__io, this, m__root);
    m_p = m__io->read_u4le();
    m_p_std = m__io->read_u2le();
    m_l = new gnss_t::carrier_phase_t(m__io, this, m__root);
    m_cn0 = m__io->read_u1();
    m_lock = m__io->read_u2le();
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_doppler = m__io->read_s4le();
    m_doppler_std = m__io->read_u2le();
    m_uptime = m__io->read_u4le();
    m_clock_offset = m__io->read_s2le();
    m_clock_drift = m__io->read_s2le();
    m_corr_spacing = m__io->read_u2le();
    m_acceleration = m__io->read_s1();
    m_sync_flags = m__io->read_u1();
    m_tow_flags = m__io->read_u1();
    m_track_flags = m__io->read_u1();
    m_nav_flags = m__io->read_u1();
    m_pset_flags = m__io->read_u1();
    m_misc_flags = m__io->read_u1();
}

tracking_t::msg_tracking_state_detailed_dep_a_t::~msg_tracking_state_detailed_dep_a_t() {
    _clean_up();
}

void tracking_t::msg_tracking_state_detailed_dep_a_t::_clean_up() {
    if (m_tot) {
        delete m_tot; m_tot = 0;
    }
    if (m_l) {
        delete m_l; m_l = 0;
    }
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

tracking_t::msg_tracking_state_dep_b_t::msg_tracking_state_dep_b_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_states = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tracking_t::msg_tracking_state_dep_b_t::_read() {
    m_states = new std::vector<tracking_channel_state_dep_b_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_states->push_back(new tracking_channel_state_dep_b_t(m__io, this, m__root));
            i++;
        }
    }
}

tracking_t::msg_tracking_state_dep_b_t::~msg_tracking_state_dep_b_t() {
    _clean_up();
}

void tracking_t::msg_tracking_state_dep_b_t::_clean_up() {
    if (m_states) {
        for (std::vector<tracking_channel_state_dep_b_t*>::iterator it = m_states->begin(); it != m_states->end(); ++it) {
            delete *it;
        }
        delete m_states; m_states = 0;
    }
}

tracking_t::measurement_state_t::measurement_state_t(kaitai::kstream* p__io, tracking_t::msg_measurement_state_t* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_mesid = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tracking_t::measurement_state_t::_read() {
    m_mesid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_cn0 = m__io->read_u1();
}

tracking_t::measurement_state_t::~measurement_state_t() {
    _clean_up();
}

void tracking_t::measurement_state_t::_clean_up() {
    if (m_mesid) {
        delete m_mesid; m_mesid = 0;
    }
}

tracking_t::msg_tracking_iq_dep_b_t::msg_tracking_iq_dep_b_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, tracking_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sid = 0;
    m_corrs = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tracking_t::msg_tracking_iq_dep_b_t::_read() {
    m_channel = m__io->read_u1();
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_corrs = new std::vector<uint64_t>();
    const int l_corrs = 3;
    for (int i = 0; i < l_corrs; i++) {
        m_corrs->push_back(m__io->read_u8le());
    }
}

tracking_t::msg_tracking_iq_dep_b_t::~msg_tracking_iq_dep_b_t() {
    _clean_up();
}

void tracking_t::msg_tracking_iq_dep_b_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
    if (m_corrs) {
        delete m_corrs; m_corrs = 0;
    }
}
