#ifndef EXT_EVENTS_H_
#define EXT_EVENTS_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class ext_events_t : public kaitai::kstruct {

public:
    class msg_ext_event_t;

    ext_events_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, ext_events_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~ext_events_t();

    /**
     * Reports detection of an external event, the GPS time it occurred, which
     * pin it was and whether it was rising or falling.
     */

    class msg_ext_event_t : public kaitai::kstruct {

    public:

        msg_ext_event_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, ext_events_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ext_event_t();

    private:
        uint16_t m_wn;
        uint32_t m_tow;
        int32_t m_ns_residual;
        uint8_t m_flags;
        uint8_t m_pin;
        ext_events_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * GPS week number
         */
        uint16_t wn() const { return m_wn; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
         * to 500000)
         */
        int32_t ns_residual() const { return m_ns_residual; }

        /**
         * Flags
         */
        uint8_t flags() const { return m_flags; }

        /**
         * Pin number.  0..9 = DEBUG0..9.
         */
        uint8_t pin() const { return m_pin; }
        ext_events_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

private:
    ext_events_t* m__root;
    kaitai::kstruct* m__parent;

public:
    ext_events_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // EXT_EVENTS_H_
