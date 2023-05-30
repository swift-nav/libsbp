#ifndef LOGGING_H_
#define LOGGING_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class logging_t : public kaitai::kstruct {

public:
    class msg_log_t;
    class msg_fwd_t;
    class msg_print_dep_t;

    logging_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, logging_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~logging_t();

    /**
     * This message contains a human-readable payload string from the device
     * containing errors, warnings and informational messages at ERROR,
     * WARNING, DEBUG, INFO logging levels.
     */

    class msg_log_t : public kaitai::kstruct {

    public:

        msg_log_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, logging_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_log_t();

    private:
        uint8_t m_level;
        std::string m_text;
        logging_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Logging level
         */
        uint8_t level() const { return m_level; }

        /**
         * Human-readable string
         */
        std::string text() const { return m_text; }
        logging_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message provides the ability to forward messages over SBP.  This
     * may take the form of wrapping up SBP messages received by Piksi for
     * logging purposes or wrapping another protocol with SBP.
     * 
     * The source identifier indicates from what interface a forwarded stream
     * derived. The protocol identifier identifies what the expected protocol
     * the forwarded msg contains. Protocol 0 represents SBP and the remaining
     * values are implementation defined.
     */

    class msg_fwd_t : public kaitai::kstruct {

    public:

        msg_fwd_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, logging_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_fwd_t();

    private:
        uint8_t m_source;
        uint8_t m_protocol;
        std::vector<uint8_t>* m_fwd_payload;
        logging_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * source identifier
         */
        uint8_t source() const { return m_source; }

        /**
         * protocol identifier
         */
        uint8_t protocol() const { return m_protocol; }

        /**
         * variable length wrapped binary message
         */
        std::vector<uint8_t>* fwd_payload() const { return m_fwd_payload; }
        logging_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_print_dep_t : public kaitai::kstruct {

    public:

        msg_print_dep_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, logging_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_print_dep_t();

    private:
        std::string m_text;
        logging_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Human-readable string
         */
        std::string text() const { return m_text; }
        logging_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

private:
    logging_t* m__root;
    kaitai::kstruct* m__parent;

public:
    logging_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // LOGGING_H_
