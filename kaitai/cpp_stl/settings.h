#ifndef SETTINGS_H_
#define SETTINGS_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class settings_t : public kaitai::kstruct {

public:
    class msg_settings_read_resp_t;
    class msg_settings_write_resp_t;
    class msg_settings_register_resp_t;
    class msg_settings_read_by_index_resp_t;
    class msg_settings_read_req_t;
    class msg_settings_save_t;
    class msg_settings_register_t;
    class msg_settings_read_by_index_req_t;
    class msg_settings_read_by_index_done_t;
    class msg_settings_write_t;

    settings_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, settings_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~settings_t();

    /**
     * The setting message with which the device responds after a
     * MSG_SETTING_READ_REQ is sent to device. The string field is a NULL-
     * terminated and NULL-delimited string with contents
     * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
     * denotes the NULL character and where quotation marks are omitted. An
     * example string that could be sent from device is
     * "solution\0soln_freq\010\0".
     */

    class msg_settings_read_resp_t : public kaitai::kstruct {

    public:

        msg_settings_read_resp_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, settings_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_settings_read_resp_t();

    private:
        std::string m_setting;
        settings_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * A NULL-terminated and NULL-delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE\0"
         */
        std::string setting() const { return m_setting; }
        settings_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Return the status of a write request with the new value of the setting.
     * If the requested value is rejected, the current value will be returned.
     * The string field is a NULL-terminated and NULL-delimited string with
     * contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape
     * sequence denotes the NULL character and where quotation marks are
     * omitted. An example string that could be sent from device is
     * "solution\0soln_freq\010\0".
     */

    class msg_settings_write_resp_t : public kaitai::kstruct {

    public:

        msg_settings_write_resp_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, settings_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_settings_write_resp_t();

    private:
        uint8_t m_status;
        std::string m_setting;
        settings_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Write status
         */
        uint8_t status() const { return m_status; }

        /**
         * A NULL-terminated and delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE\0"
         */
        std::string setting() const { return m_setting; }
        settings_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message responds to setting registration with the effective value.
     * The effective value shall differ from the given default value if setting
     * was already registered or is available in the permanent setting storage
     * and had a different value.
     */

    class msg_settings_register_resp_t : public kaitai::kstruct {

    public:

        msg_settings_register_resp_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, settings_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_settings_register_resp_t();

    private:
        uint8_t m_status;
        std::string m_setting;
        settings_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Register status
         */
        uint8_t status() const { return m_status; }

        /**
         * A NULL-terminated and delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
         * according to the status field.
         */
        std::string setting() const { return m_setting; }
        settings_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The settings message that reports the value of a setting at an index.
     * 
     * In the string field, it reports NULL-terminated and delimited string
     * with contents "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where
     * the '\0' escape sequence denotes the NULL character and where quotation
     * marks are omitted. The FORMAT_TYPE field is optional and denotes
     * possible string values of the setting as a hint to the user. If
     * included, the format type portion of the string has the format
     * "enum:value1,value2,value3". An example string that could be sent from
     * the device is "simulator\0enabled\0True\0enum:True,False\0".
     */

    class msg_settings_read_by_index_resp_t : public kaitai::kstruct {

    public:

        msg_settings_read_by_index_resp_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, settings_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_settings_read_by_index_resp_t();

    private:
        uint16_t m_index;
        std::string m_setting;
        settings_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * An index into the device settings, with values ranging from 0 to
         * length(settings)
         */
        uint16_t index() const { return m_index; }

        /**
         * A NULL-terminated and delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
         */
        std::string setting() const { return m_setting; }
        settings_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The setting message that reads the device configuration. The string
     * field is a NULL-terminated and NULL-delimited string with contents
     * "SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the
     * NULL character and where quotation marks are omitted. An example string
     * that could be sent to a device is "solution\0soln_freq\0". A device will
     * only respond to this message when it is received from sender ID 0x42. A
     * device should respond with a MSG_SETTINGS_READ_RESP message (msg_id
     * 0x00A5).
     */

    class msg_settings_read_req_t : public kaitai::kstruct {

    public:

        msg_settings_read_req_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, settings_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_settings_read_req_t();

    private:
        std::string m_setting;
        settings_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * A NULL-terminated and NULL-delimited string with contents
         * "SECTION_SETTING\0SETTING\0"
         */
        std::string setting() const { return m_setting; }
        settings_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The save settings message persists the device's current settings
     * configuration to its onboard flash memory file system.
     */

    class msg_settings_save_t : public kaitai::kstruct {

    public:

        msg_settings_save_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, settings_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_settings_save_t();

    private:
        settings_t* m__root;
        sbp_t::message_t* m__parent;

    public:
        settings_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message registers the presence and default value of a setting with
     * a settings daemon.  The host should reply with MSG_SETTINGS_WRITE for
     * this setting to set the initial value.
     */

    class msg_settings_register_t : public kaitai::kstruct {

    public:

        msg_settings_register_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, settings_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_settings_register_t();

    private:
        std::string m_setting;
        settings_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * A NULL-terminated and delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE".
         */
        std::string setting() const { return m_setting; }
        settings_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The settings message for iterating through the settings values. A device
     * will respond to this message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".
     */

    class msg_settings_read_by_index_req_t : public kaitai::kstruct {

    public:

        msg_settings_read_by_index_req_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, settings_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_settings_read_by_index_req_t();

    private:
        uint16_t m_index;
        settings_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * An index into the device settings, with values ranging from 0 to
         * length(settings).
         */
        uint16_t index() const { return m_index; }
        settings_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The settings message for indicating end of the settings values.
     */

    class msg_settings_read_by_index_done_t : public kaitai::kstruct {

    public:

        msg_settings_read_by_index_done_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, settings_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_settings_read_by_index_done_t();

    private:
        settings_t* m__root;
        sbp_t::message_t* m__parent;

    public:
        settings_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The setting message writes the device configuration for a particular
     * setting via A NULL-terminated and NULL-delimited string with contents
     * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
     * denotes the NULL character and where quotation marks are omitted. A
     * device will only process to this message when it is received from sender
     * ID 0x42. An example string that could be sent to a device is
     * "solution\0soln_freq\010\0".
     */

    class msg_settings_write_t : public kaitai::kstruct {

    public:

        msg_settings_write_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, settings_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_settings_write_t();

    private:
        std::string m_setting;
        settings_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * A NULL-terminated and NULL-delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE\0"
         */
        std::string setting() const { return m_setting; }
        settings_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

private:
    settings_t* m__root;
    kaitai::kstruct* m__parent;

public:
    settings_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // SETTINGS_H_
