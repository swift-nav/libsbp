// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "imu.h"

imu_t::imu_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, imu_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void imu_t::_read() {
}

imu_t::~imu_t() {
    _clean_up();
}

void imu_t::_clean_up() {
}

imu_t::msg_imu_raw_t::msg_imu_raw_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, imu_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void imu_t::msg_imu_raw_t::_read() {
    m_tow = m__io->read_u4le();
    m_tow_f = m__io->read_u1();
    m_acc_x = m__io->read_s2le();
    m_acc_y = m__io->read_s2le();
    m_acc_z = m__io->read_s2le();
    m_gyr_x = m__io->read_s2le();
    m_gyr_y = m__io->read_s2le();
    m_gyr_z = m__io->read_s2le();
}

imu_t::msg_imu_raw_t::~msg_imu_raw_t() {
    _clean_up();
}

void imu_t::msg_imu_raw_t::_clean_up() {
}

imu_t::msg_imu_aux_t::msg_imu_aux_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent, imu_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void imu_t::msg_imu_aux_t::_read() {
    m_imu_type = m__io->read_u1();
    m_temp = m__io->read_s2le();
    m_imu_conf = m__io->read_u1();
}

imu_t::msg_imu_aux_t::~msg_imu_aux_t() {
    _clean_up();
}

void imu_t::msg_imu_aux_t::_clean_up() {
}
