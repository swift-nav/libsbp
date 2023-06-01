#ifndef NDB_H_
#define NDB_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class ndb_t : public kaitai::kstruct {

public:
    class msg_ndb_event_t;

    ndb_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, ndb_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~ndb_t();

    /**
     * This message is sent out when an object is stored into NDB. If needed
     * message could also be sent out when fetching an object from NDB.
     */

    class msg_ndb_event_t : public kaitai::kstruct {

    public:

        msg_ndb_event_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, ndb_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ndb_event_t();

    private:
        uint64_t m_recv_time;
        uint8_t m_event;
        uint8_t m_object_type;
        uint8_t m_result;
        uint8_t m_data_source;
        gnss_t::gnss_signal_t* m_object_sid;
        gnss_t::gnss_signal_t* m_src_sid;
        uint16_t m_original_sender;
        ndb_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * HW time in milliseconds.
         */
        uint64_t recv_time() const { return m_recv_time; }

        /**
         * Event type.
         */
        uint8_t event() const { return m_event; }

        /**
         * Event object type.
         */
        uint8_t object_type() const { return m_object_type; }

        /**
         * Event result.
         */
        uint8_t result() const { return m_result; }

        /**
         * Data source for STORE event, reserved for other events.
         */
        uint8_t data_source() const { return m_data_source; }

        /**
         * GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid
         * indicates for which signal the object belongs to. Reserved in other
         * cases.
         */
        gnss_t::gnss_signal_t* object_sid() const { return m_object_sid; }

        /**
         * GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono
         * OR L2C capabilities AND data_source is NDB_DS_RECEIVER sid indicates
         * from which SV data was decoded. Reserved in other cases.
         */
        gnss_t::gnss_signal_t* src_sid() const { return m_src_sid; }

        /**
         * A unique identifier of the sending hardware. For v1.0, set to the 2
         * least significant bytes of the device serial number, valid only if
         * data_source is NDB_DS_SBP. Reserved in case of other data_source.
         */
        uint16_t original_sender() const { return m_original_sender; }
        ndb_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

private:
    ndb_t* m__root;
    kaitai::kstruct* m__parent;

public:
    ndb_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // NDB_H_
