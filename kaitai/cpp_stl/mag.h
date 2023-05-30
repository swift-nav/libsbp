#ifndef MAG_H_
#define MAG_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class mag_t : public kaitai::kstruct {

public:
    class msg_mag_raw_t;

    mag_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, mag_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~mag_t();

    /**
     * Raw data from the magnetometer.
     */

    class msg_mag_raw_t : public kaitai::kstruct {

    public:

        msg_mag_raw_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, mag_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_mag_raw_t();

    private:
        uint32_t m_tow;
        uint8_t m_tow_f;
        int16_t m_mag_x;
        int16_t m_mag_y;
        int16_t m_mag_z;
        mag_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Milliseconds since start of GPS week. If the high bit is set, the
         * time is unknown or invalid.
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Milliseconds since start of GPS week, fractional part
         */
        uint8_t tow_f() const { return m_tow_f; }

        /**
         * Magnetic field in the body frame X axis
         */
        int16_t mag_x() const { return m_mag_x; }

        /**
         * Magnetic field in the body frame Y axis
         */
        int16_t mag_y() const { return m_mag_y; }

        /**
         * Magnetic field in the body frame Z axis
         */
        int16_t mag_z() const { return m_mag_z; }
        mag_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

private:
    mag_t* m__root;
    kaitai::kstruct* m__parent;

public:
    mag_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // MAG_H_
