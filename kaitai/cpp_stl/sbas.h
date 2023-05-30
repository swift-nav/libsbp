#ifndef SBAS_H_
#define SBAS_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class sbas_t : public kaitai::kstruct {

public:
    class msg_sbas_raw_t;

    sbas_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, sbas_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~sbas_t();

    /**
     * This message is sent once per second per SBAS satellite. ME checks the
     * parity of the data block and sends only blocks that pass the check.
     */

    class msg_sbas_raw_t : public kaitai::kstruct {

    public:

        msg_sbas_raw_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, sbas_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_sbas_raw_t();

    private:
        gnss_t::gnss_signal_t* m_sid;
        uint32_t m_tow;
        uint8_t m_message_type;
        std::vector<uint8_t>* m_data;
        sbas_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GNSS signal identifier.
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * GPS time-of-week at the start of the data block.
         */
        uint32_t tow() const { return m_tow; }

        /**
         * SBAS message type (0-63)
         */
        uint8_t message_type() const { return m_message_type; }

        /**
         * Raw SBAS data field of 212 bits (last byte padded with zeros).
         */
        std::vector<uint8_t>* data() const { return m_data; }
        sbas_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

private:
    sbas_t* m__root;
    kaitai::kstruct* m__parent;

public:
    sbas_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // SBAS_H_
