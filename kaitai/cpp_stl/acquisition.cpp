// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "acquisition.h"

acquisition_t::acquisition_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, acquisition_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void acquisition_t::_read() {
}

acquisition_t::~acquisition_t() {
    _clean_up();
}

void acquisition_t::_clean_up() {
}

acquisition_t::msg_acq_result_dep_c_t::msg_acq_result_dep_c_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, acquisition_t* p__root) : kaitai::kstruct(p__io) {
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

void acquisition_t::msg_acq_result_dep_c_t::_read() {
    m_cn0 = m__io->read_f4le();
    m_cp = m__io->read_f4le();
    m_cf = m__io->read_f4le();
    m_sid = new gnss_t::gnss_signal_dep_t(m__io, this, m__root);
}

acquisition_t::msg_acq_result_dep_c_t::~msg_acq_result_dep_c_t() {
    _clean_up();
}

void acquisition_t::msg_acq_result_dep_c_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

acquisition_t::msg_acq_result_dep_b_t::msg_acq_result_dep_b_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, acquisition_t* p__root) : kaitai::kstruct(p__io) {
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

void acquisition_t::msg_acq_result_dep_b_t::_read() {
    m_snr = m__io->read_f4le();
    m_cp = m__io->read_f4le();
    m_cf = m__io->read_f4le();
    m_sid = new gnss_t::gnss_signal_dep_t(m__io, this, m__root);
}

acquisition_t::msg_acq_result_dep_b_t::~msg_acq_result_dep_b_t() {
    _clean_up();
}

void acquisition_t::msg_acq_result_dep_b_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

acquisition_t::acq_sv_profile_t::acq_sv_profile_t(kaitai::kstream* p__io, acquisition_t::msg_acq_sv_profile_t* p__parent, acquisition_t* p__root) : kaitai::kstruct(p__io) {
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

void acquisition_t::acq_sv_profile_t::_read() {
    m_job_type = m__io->read_u1();
    m_status = m__io->read_u1();
    m_cn0 = m__io->read_u2le();
    m_int_time = m__io->read_u1();
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
    m_bin_width = m__io->read_u2le();
    m_timestamp = m__io->read_u4le();
    m_time_spent = m__io->read_u4le();
    m_cf_min = m__io->read_s4le();
    m_cf_max = m__io->read_s4le();
    m_cf = m__io->read_s4le();
    m_cp = m__io->read_u4le();
}

acquisition_t::acq_sv_profile_t::~acq_sv_profile_t() {
    _clean_up();
}

void acquisition_t::acq_sv_profile_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

acquisition_t::msg_acq_sv_profile_t::msg_acq_sv_profile_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, acquisition_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_acq_sv_profile = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void acquisition_t::msg_acq_sv_profile_t::_read() {
    m_acq_sv_profile = new std::vector<acq_sv_profile_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_acq_sv_profile->push_back(new acq_sv_profile_t(m__io, this, m__root));
            i++;
        }
    }
}

acquisition_t::msg_acq_sv_profile_t::~msg_acq_sv_profile_t() {
    _clean_up();
}

void acquisition_t::msg_acq_sv_profile_t::_clean_up() {
    if (m_acq_sv_profile) {
        for (std::vector<acq_sv_profile_t*>::iterator it = m_acq_sv_profile->begin(); it != m_acq_sv_profile->end(); ++it) {
            delete *it;
        }
        delete m_acq_sv_profile; m_acq_sv_profile = 0;
    }
}

acquisition_t::acq_sv_profile_dep_t::acq_sv_profile_dep_t(kaitai::kstream* p__io, acquisition_t::msg_acq_sv_profile_dep_t* p__parent, acquisition_t* p__root) : kaitai::kstruct(p__io) {
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

void acquisition_t::acq_sv_profile_dep_t::_read() {
    m_job_type = m__io->read_u1();
    m_status = m__io->read_u1();
    m_cn0 = m__io->read_u2le();
    m_int_time = m__io->read_u1();
    m_sid = new gnss_t::gnss_signal_dep_t(m__io, this, m__root);
    m_bin_width = m__io->read_u2le();
    m_timestamp = m__io->read_u4le();
    m_time_spent = m__io->read_u4le();
    m_cf_min = m__io->read_s4le();
    m_cf_max = m__io->read_s4le();
    m_cf = m__io->read_s4le();
    m_cp = m__io->read_u4le();
}

acquisition_t::acq_sv_profile_dep_t::~acq_sv_profile_dep_t() {
    _clean_up();
}

void acquisition_t::acq_sv_profile_dep_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

acquisition_t::msg_acq_result_t::msg_acq_result_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, acquisition_t* p__root) : kaitai::kstruct(p__io) {
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

void acquisition_t::msg_acq_result_t::_read() {
    m_cn0 = m__io->read_f4le();
    m_cp = m__io->read_f4le();
    m_cf = m__io->read_f4le();
    m_sid = new gnss_t::gnss_signal_t(m__io, this, m__root);
}

acquisition_t::msg_acq_result_t::~msg_acq_result_t() {
    _clean_up();
}

void acquisition_t::msg_acq_result_t::_clean_up() {
    if (m_sid) {
        delete m_sid; m_sid = 0;
    }
}

acquisition_t::msg_acq_result_dep_a_t::msg_acq_result_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, acquisition_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void acquisition_t::msg_acq_result_dep_a_t::_read() {
    m_snr = m__io->read_f4le();
    m_cp = m__io->read_f4le();
    m_cf = m__io->read_f4le();
    m_prn = m__io->read_u1();
}

acquisition_t::msg_acq_result_dep_a_t::~msg_acq_result_dep_a_t() {
    _clean_up();
}

void acquisition_t::msg_acq_result_dep_a_t::_clean_up() {
}

acquisition_t::msg_acq_sv_profile_dep_t::msg_acq_sv_profile_dep_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, acquisition_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_acq_sv_profile = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void acquisition_t::msg_acq_sv_profile_dep_t::_read() {
    m_acq_sv_profile = new std::vector<acq_sv_profile_dep_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_acq_sv_profile->push_back(new acq_sv_profile_dep_t(m__io, this, m__root));
            i++;
        }
    }
}

acquisition_t::msg_acq_sv_profile_dep_t::~msg_acq_sv_profile_dep_t() {
    _clean_up();
}

void acquisition_t::msg_acq_sv_profile_dep_t::_clean_up() {
    if (m_acq_sv_profile) {
        for (std::vector<acq_sv_profile_dep_t*>::iterator it = m_acq_sv_profile->begin(); it != m_acq_sv_profile->end(); ++it) {
            delete *it;
        }
        delete m_acq_sv_profile; m_acq_sv_profile = 0;
    }
}
