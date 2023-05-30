#ifndef BOOTLOAD_H_
#define BOOTLOAD_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class bootload_t : public kaitai::kstruct {

public:
    class msg_nap_device_dna_req_t;
    class msg_bootloader_jump_to_app_t;
    class msg_bootloader_handshake_resp_t;
    class msg_nap_device_dna_resp_t;
    class msg_bootloader_handshake_req_t;
    class msg_bootloader_handshake_dep_a_t;

    bootload_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, bootload_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~bootload_t();

    /**
     * The device message from the host reads a unique device identifier from
     * the SwiftNAP, an FPGA. The host requests the ID by sending a
     * MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
     * MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
     * that this ID is tied to the FPGA, and not related to the Piksi's serial
     * number.
     */

    class msg_nap_device_dna_req_t : public kaitai::kstruct {

    public:

        msg_nap_device_dna_req_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, bootload_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_nap_device_dna_req_t();

    private:
        bootload_t* m__root;
        sbp_t::message_t* m__parent;

    public:
        bootload_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The host initiates the bootloader to jump to the application.
     */

    class msg_bootloader_jump_to_app_t : public kaitai::kstruct {

    public:

        msg_bootloader_jump_to_app_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, bootload_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_bootloader_jump_to_app_t();

    private:
        uint8_t m_jump;
        bootload_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Ignored by the device
         */
        uint8_t jump() const { return m_jump; }
        bootload_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The handshake message response from the device establishes a handshake
     * between the device bootloader and the host. The request from the host is
     * MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader
     * version number and the SBP protocol version number.
     */

    class msg_bootloader_handshake_resp_t : public kaitai::kstruct {

    public:

        msg_bootloader_handshake_resp_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, bootload_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_bootloader_handshake_resp_t();

    private:
        uint32_t m_flags;
        std::string m_version;
        bootload_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Bootloader flags
         */
        uint32_t flags() const { return m_flags; }

        /**
         * Bootloader version number
         */
        std::string version() const { return m_version; }
        bootload_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The device message from the host reads a unique device identifier from
     * the SwiftNAP, an FPGA. The host requests the ID by sending a
     * MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
     * MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
     * that this ID is tied to the FPGA, and not related to the Piksi's serial
     * number.
     */

    class msg_nap_device_dna_resp_t : public kaitai::kstruct {

    public:

        msg_nap_device_dna_resp_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, bootload_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_nap_device_dna_resp_t();

    private:
        std::vector<uint8_t>* m_dna;
        bootload_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the
         * right.
         */
        std::vector<uint8_t>* dna() const { return m_dna; }
        bootload_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The handshake message request from the host establishes a handshake
     * between the device bootloader and the host. The response from the device
     * is MSG_BOOTLOADER_HANDSHAKE_RESP.
     */

    class msg_bootloader_handshake_req_t : public kaitai::kstruct {

    public:

        msg_bootloader_handshake_req_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, bootload_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_bootloader_handshake_req_t();

    private:
        bootload_t* m__root;
        sbp_t::message_t* m__parent;

    public:
        bootload_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_bootloader_handshake_dep_a_t : public kaitai::kstruct {

    public:

        msg_bootloader_handshake_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, bootload_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_bootloader_handshake_dep_a_t();

    private:
        std::vector<uint8_t>* m_handshake;
        bootload_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Version number string (not NULL terminated)
         */
        std::vector<uint8_t>* handshake() const { return m_handshake; }
        bootload_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

private:
    bootload_t* m__root;
    kaitai::kstruct* m__parent;

public:
    bootload_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // BOOTLOAD_H_
