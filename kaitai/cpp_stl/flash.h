#ifndef FLASH_H_
#define FLASH_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class flash_t : public kaitai::kstruct {

public:
    class msg_flash_done_t;
    class msg_m25_flash_write_status_t;
    class msg_flash_read_resp_t;
    class msg_flash_erase_t;
    class msg_stm_unique_id_resp_t;
    class msg_stm_unique_id_req_t;
    class msg_flash_program_t;
    class msg_flash_read_req_t;
    class msg_stm_flash_unlock_sector_t;
    class msg_stm_flash_lock_sector_t;

    flash_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, flash_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~flash_t();

    /**
     * This message defines success or failure codes for a variety of flash
     * memory requests from the host to the device. Flash read and write
     * messages, such as MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return
     * this message on failure.
     */

    class msg_flash_done_t : public kaitai::kstruct {

    public:

        msg_flash_done_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, flash_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_flash_done_t();

    private:
        uint8_t m_response;
        flash_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Response flags
         */
        uint8_t response() const { return m_response; }
        flash_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The flash status message writes to the 8-bit M25 flash status register.
     * The device replies with a MSG_FLASH_DONE message.
     */

    class msg_m25_flash_write_status_t : public kaitai::kstruct {

    public:

        msg_m25_flash_write_status_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, flash_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_m25_flash_write_status_t();

    private:
        std::vector<uint8_t>* m_status;
        flash_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Byte to write to the M25 flash status register
         */
        std::vector<uint8_t>* status() const { return m_status; }
        flash_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The flash read message reads a set of addresses of either the STM or M25
     * onboard flash. The device replies with a MSG_FLASH_READ_RESP message
     * containing either the read data on success or a MSG_FLASH_DONE message
     * containing the return code FLASH_INVALID_LEN (2) if the maximum read
     * size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
     * the allowed range.
     */

    class msg_flash_read_resp_t : public kaitai::kstruct {

    public:

        msg_flash_read_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, flash_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_flash_read_resp_t();

    private:
        uint8_t m_target;
        std::vector<uint8_t>* m_addr_start;
        uint8_t m_addr_len;
        flash_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Target flags
         */
        uint8_t target() const { return m_target; }

        /**
         * Starting address offset to read from
         */
        std::vector<uint8_t>* addr_start() const { return m_addr_start; }

        /**
         * Length of set of addresses to read, counting up from starting
         * address
         */
        uint8_t addr_len() const { return m_addr_len; }
        flash_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The flash erase message from the host erases a sector of either the STM
     * or M25 onboard flash memory. The device will reply with a MSG_FLASH_DONE
     * message containing the return code - FLASH_OK (0) on success or
     * FLASH_INVALID_FLASH (1) if the flash specified is invalid.
     */

    class msg_flash_erase_t : public kaitai::kstruct {

    public:

        msg_flash_erase_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, flash_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_flash_erase_t();

    private:
        uint8_t m_target;
        uint32_t m_sector_num;
        flash_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Target flags
         */
        uint8_t target() const { return m_target; }

        /**
         * Flash sector number to erase (0-11 for the STM, 0-15 for the M25)
         */
        uint32_t sector_num() const { return m_sector_num; }
        flash_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reads the device's hard-coded unique ID. The host requests
     * the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
     * MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
     */

    class msg_stm_unique_id_resp_t : public kaitai::kstruct {

    public:

        msg_stm_unique_id_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, flash_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_stm_unique_id_resp_t();

    private:
        std::vector<uint8_t>* m_stm_id;
        flash_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Device unique ID
         */
        std::vector<uint8_t>* stm_id() const { return m_stm_id; }
        flash_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reads the device's hard-coded unique ID. The host requests
     * the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
     * MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
     */

    class msg_stm_unique_id_req_t : public kaitai::kstruct {

    public:

        msg_stm_unique_id_req_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, flash_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_stm_unique_id_req_t();

    private:
        flash_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:
        flash_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The flash program message programs a set of addresses of either the STM
     * or M25 flash. The device replies with either a MSG_FLASH_DONE message
     * containing the return code FLASH_OK (0) on success, or FLASH_INVALID_LEN
     * (2) if the maximum write size is exceeded. Note that the sector-
     * containing addresses must be erased before addresses can be programmed.
     */

    class msg_flash_program_t : public kaitai::kstruct {

    public:

        msg_flash_program_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, flash_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_flash_program_t();

    private:
        uint8_t m_target;
        std::vector<uint8_t>* m_addr_start;
        uint8_t m_addr_len;
        std::vector<uint8_t>* m_data;
        flash_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Target flags
         */
        uint8_t target() const { return m_target; }

        /**
         * Starting address offset to program
         */
        std::vector<uint8_t>* addr_start() const { return m_addr_start; }

        /**
         * Length of set of addresses to program, counting up from starting
         * address
         */
        uint8_t addr_len() const { return m_addr_len; }

        /**
         * Data to program addresses with, with length N=addr_len
         */
        std::vector<uint8_t>* data() const { return m_data; }
        flash_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The flash read message reads a set of addresses of either the STM or M25
     * onboard flash. The device replies with a MSG_FLASH_READ_RESP message
     * containing either the read data on success or a MSG_FLASH_DONE message
     * containing the return code FLASH_INVALID_LEN (2) if the maximum read
     * size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
     * the allowed range.
     */

    class msg_flash_read_req_t : public kaitai::kstruct {

    public:

        msg_flash_read_req_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, flash_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_flash_read_req_t();

    private:
        uint8_t m_target;
        std::vector<uint8_t>* m_addr_start;
        uint8_t m_addr_len;
        flash_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Target flags
         */
        uint8_t target() const { return m_target; }

        /**
         * Starting address offset to read from
         */
        std::vector<uint8_t>* addr_start() const { return m_addr_start; }

        /**
         * Length of set of addresses to read, counting up from starting
         * address
         */
        uint8_t addr_len() const { return m_addr_len; }
        flash_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The flash unlock message unlocks a sector of the STM flash memory. The
     * device replies with a MSG_FLASH_DONE message.
     */

    class msg_stm_flash_unlock_sector_t : public kaitai::kstruct {

    public:

        msg_stm_flash_unlock_sector_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, flash_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_stm_flash_unlock_sector_t();

    private:
        uint32_t m_sector;
        flash_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Flash sector number to unlock
         */
        uint32_t sector() const { return m_sector; }
        flash_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The flash lock message locks a sector of the STM flash memory. The
     * device replies with a MSG_FLASH_DONE message.
     */

    class msg_stm_flash_lock_sector_t : public kaitai::kstruct {

    public:

        msg_stm_flash_lock_sector_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, flash_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_stm_flash_lock_sector_t();

    private:
        uint32_t m_sector;
        flash_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Flash sector number to lock
         */
        uint32_t sector() const { return m_sector; }
        flash_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

private:
    flash_t* m__root;
    kaitai::kstruct* m__parent;

public:
    flash_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // FLASH_H_
