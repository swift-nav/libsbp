// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "vehicle.h"

vehicle_t::vehicle_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, vehicle_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void vehicle_t::_read() {
}

vehicle_t::~vehicle_t() {
    _clean_up();
}

void vehicle_t::_clean_up() {
}

vehicle_t::msg_odometry_t::msg_odometry_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, vehicle_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void vehicle_t::msg_odometry_t::_read() {
    m_tow = m__io->read_u4le();
    m_velocity = m__io->read_s4le();
    m_flags = m__io->read_u1();
}

vehicle_t::msg_odometry_t::~msg_odometry_t() {
    _clean_up();
}

void vehicle_t::msg_odometry_t::_clean_up() {
}

vehicle_t::msg_wheeltick_t::msg_wheeltick_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent, vehicle_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void vehicle_t::msg_wheeltick_t::_read() {
    m_time = m__io->read_u8le();
    m_flags = m__io->read_u1();
    m_source = m__io->read_u1();
    m_ticks = m__io->read_s4le();
}

vehicle_t::msg_wheeltick_t::~msg_wheeltick_t() {
    _clean_up();
}

void vehicle_t::msg_wheeltick_t::_clean_up() {
}
