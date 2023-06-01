#ifndef USER_H_
#define USER_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class user_t : public kaitai::kstruct {

public:
    class msg_user_data_t;

    user_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, user_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~user_t();

    /**
     * This message can contain any application specific user data up to a
     * maximum length of 255 bytes per message.
     */

    class msg_user_data_t : public kaitai::kstruct {

    public:

        msg_user_data_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, user_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_user_data_t();

    private:
        std::vector<uint8_t>* m_contents;
        user_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * User data payload
         */
        std::vector<uint8_t>* contents() const { return m_contents; }
        user_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

private:
    user_t* m__root;
    kaitai::kstruct* m__parent;

public:
    user_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // USER_H_
