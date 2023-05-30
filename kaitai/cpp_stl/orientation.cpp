// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "orientation.h"

orientation_t::orientation_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, orientation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void orientation_t::_read() {
}

orientation_t::~orientation_t() {
    _clean_up();
}

void orientation_t::_clean_up() {
}

orientation_t::msg_baseline_heading_t::msg_baseline_heading_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, orientation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void orientation_t::msg_baseline_heading_t::_read() {
    m_tow = m__io->read_u4le();
    m_heading = m__io->read_u4le();
    m_n_sats = m__io->read_u1();
    m_flags = m__io->read_u1();
}

orientation_t::msg_baseline_heading_t::~msg_baseline_heading_t() {
    _clean_up();
}

void orientation_t::msg_baseline_heading_t::_clean_up() {
}

orientation_t::msg_orient_quat_t::msg_orient_quat_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, orientation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void orientation_t::msg_orient_quat_t::_read() {
    m_tow = m__io->read_u4le();
    m_w = m__io->read_s4le();
    m_x = m__io->read_s4le();
    m_y = m__io->read_s4le();
    m_z = m__io->read_s4le();
    m_w_accuracy = m__io->read_f4le();
    m_x_accuracy = m__io->read_f4le();
    m_y_accuracy = m__io->read_f4le();
    m_z_accuracy = m__io->read_f4le();
    m_flags = m__io->read_u1();
}

orientation_t::msg_orient_quat_t::~msg_orient_quat_t() {
    _clean_up();
}

void orientation_t::msg_orient_quat_t::_clean_up() {
}

orientation_t::msg_orient_euler_t::msg_orient_euler_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, orientation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void orientation_t::msg_orient_euler_t::_read() {
    m_tow = m__io->read_u4le();
    m_roll = m__io->read_s4le();
    m_pitch = m__io->read_s4le();
    m_yaw = m__io->read_s4le();
    m_roll_accuracy = m__io->read_f4le();
    m_pitch_accuracy = m__io->read_f4le();
    m_yaw_accuracy = m__io->read_f4le();
    m_flags = m__io->read_u1();
}

orientation_t::msg_orient_euler_t::~msg_orient_euler_t() {
    _clean_up();
}

void orientation_t::msg_orient_euler_t::_clean_up() {
}

orientation_t::msg_angular_rate_t::msg_angular_rate_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, orientation_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void orientation_t::msg_angular_rate_t::_read() {
    m_tow = m__io->read_u4le();
    m_x = m__io->read_s4le();
    m_y = m__io->read_s4le();
    m_z = m__io->read_s4le();
    m_flags = m__io->read_u1();
}

orientation_t::msg_angular_rate_t::~msg_angular_rate_t() {
    _clean_up();
}

void orientation_t::msg_angular_rate_t::_clean_up() {
}
