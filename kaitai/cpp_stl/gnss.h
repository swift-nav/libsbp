#ifndef GNSS_H_
#define GNSS_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class gnss_t : public kaitai::kstruct {

public:
    class gnss_signal_dep_t;
    class carrier_phase_t;
    class gps_time_dep_t;
    class gnss_signal_t;
    class gps_time_t;
    class gps_time_sec_t;
    class sv_id_t;

    gnss_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, gnss_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~gnss_t();

    /**
     * Deprecated.
     */

    class gnss_signal_dep_t : public kaitai::kstruct {

    public:

        gnss_signal_dep_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, gnss_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~gnss_signal_dep_t();

    private:
        uint16_t m_sat;
        uint8_t m_code;
        uint8_t m_reserved;
        gnss_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Constellation-specific satellite identifier.
         * 
         * Note: unlike GnssSignal, GPS satellites are encoded as (PRN - 1).
         * Other constellations do not have this offset.
         */
        uint16_t sat() const { return m_sat; }

        /**
         * Signal constellation, band and code
         */
        uint8_t code() const { return m_code; }

        /**
         * Reserved
         */
        uint8_t reserved() const { return m_reserved; }
        gnss_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * Carrier phase measurement in cycles represented as a 40-bit fixed point
     * number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
     * fractional cycles. This phase has the same sign as the pseudorange.
     */

    class carrier_phase_t : public kaitai::kstruct {

    public:

        carrier_phase_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, gnss_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~carrier_phase_t();

    private:
        int32_t m_i;
        uint8_t m_f;
        gnss_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Carrier phase whole cycles
         */
        int32_t i() const { return m_i; }

        /**
         * Carrier phase fractional part
         */
        uint8_t f() const { return m_f; }
        gnss_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * A wire-appropriate GPS time, defined as the number of milliseconds since
     * beginning of the week on the Saturday/Sunday transition.
     */

    class gps_time_dep_t : public kaitai::kstruct {

    public:

        gps_time_dep_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, gnss_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~gps_time_dep_t();

    private:
        uint32_t m_tow;
        uint16_t m_wn;
        gnss_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Milliseconds since start of GPS week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * GPS week number
         */
        uint16_t wn() const { return m_wn; }
        gnss_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * Signal identifier containing constellation, band, and satellite
     * identifier.
     */

    class gnss_signal_t : public kaitai::kstruct {

    public:

        gnss_signal_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, gnss_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~gnss_signal_t();

    private:
        uint8_t m_sat;
        uint8_t m_code;
        gnss_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Constellation-specific satellite id. For GLO can either be (100+FCN)
         * where FCN is in [-7,+6] or the Slot ID in [1,28].
         */
        uint8_t sat() const { return m_sat; }

        /**
         * Signal constellation, band and code
         */
        uint8_t code() const { return m_code; }
        gnss_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * A wire-appropriate receiver clock time, defined as the time since the
     * beginning of the week on the Saturday/Sunday transition. In most cases,
     * observations are epoch aligned so ns field will be 0.
     */

    class gps_time_t : public kaitai::kstruct {

    public:

        gps_time_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, gnss_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~gps_time_t();

    private:
        uint32_t m_tow;
        int32_t m_ns_residual;
        uint16_t m_wn;
        gnss_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Milliseconds since start of GPS week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
         * to 500000)
         */
        int32_t ns_residual() const { return m_ns_residual; }

        /**
         * GPS week number
         */
        uint16_t wn() const { return m_wn; }
        gnss_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * A GPS time, defined as the number of seconds since beginning of the week
     * on the Saturday/Sunday transition.
     */

    class gps_time_sec_t : public kaitai::kstruct {

    public:

        gps_time_sec_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, gnss_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~gps_time_sec_t();

    private:
        uint32_t m_tow;
        uint16_t m_wn;
        gnss_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Seconds since start of GPS week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * GPS week number
         */
        uint16_t wn() const { return m_wn; }
        gnss_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * A (Constellation ID, satellite ID) tuple that uniquely identifies a
     * space vehicle.
     */

    class sv_id_t : public kaitai::kstruct {

    public:

        sv_id_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, gnss_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~sv_id_t();

    private:
        uint8_t m_sat_id;
        uint8_t m_constellation;
        gnss_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Constellation-specific satellite id. For GLO can either be (100+FCN)
         * where FCN is in [-7,+6] or the Slot ID in [1,28].
         */
        uint8_t sat_id() const { return m_sat_id; }

        /**
         * Constellation ID to which the SV belongs
         */
        uint8_t constellation() const { return m_constellation; }
        gnss_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

private:
    gnss_t* m__root;
    kaitai::kstruct* m__parent;

public:
    gnss_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // GNSS_H_
