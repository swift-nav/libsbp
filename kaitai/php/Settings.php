<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Settings extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Settings $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * The setting message with which the device responds after a
 * MSG_SETTING_READ_REQ is sent to device. The string field is a NULL-
 * terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
 * denotes the NULL character and where quotation marks are omitted. An
 * example string that could be sent from device is
 * "solution\0soln_freq\010\0".
 */

namespace Settings {
    class MsgSettingsReadResp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Settings $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_setting = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_setting;

        /**
         * A NULL-terminated and NULL-delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE\0"
         */
        public function setting() { return $this->_m_setting; }
    }
}

/**
 * Return the status of a write request with the new value of the setting.
 * If the requested value is rejected, the current value will be returned.
 * The string field is a NULL-terminated and NULL-delimited string with
 * contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape
 * sequence denotes the NULL character and where quotation marks are
 * omitted. An example string that could be sent from device is
 * "solution\0soln_freq\010\0".
 */

namespace Settings {
    class MsgSettingsWriteResp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Settings $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_status = $this->_io->readU1();
            $this->_m_setting = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_status;
        protected $_m_setting;

        /**
         * Write status
         */
        public function status() { return $this->_m_status; }

        /**
         * A NULL-terminated and delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE\0"
         */
        public function setting() { return $this->_m_setting; }
    }
}

/**
 * This message responds to setting registration with the effective value.
 * The effective value shall differ from the given default value if setting
 * was already registered or is available in the permanent setting storage
 * and had a different value.
 */

namespace Settings {
    class MsgSettingsRegisterResp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Settings $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_status = $this->_io->readU1();
            $this->_m_setting = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_status;
        protected $_m_setting;

        /**
         * Register status
         */
        public function status() { return $this->_m_status; }

        /**
         * A NULL-terminated and delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
         * according to the status field.
         */
        public function setting() { return $this->_m_setting; }
    }
}

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

namespace Settings {
    class MsgSettingsReadByIndexResp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Settings $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_index = $this->_io->readU2le();
            $this->_m_setting = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_index;
        protected $_m_setting;

        /**
         * An index into the device settings, with values ranging from 0 to
         * length(settings)
         */
        public function index() { return $this->_m_index; }

        /**
         * A NULL-terminated and delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
         */
        public function setting() { return $this->_m_setting; }
    }
}

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

namespace Settings {
    class MsgSettingsReadReq extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Settings $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_setting = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_setting;

        /**
         * A NULL-terminated and NULL-delimited string with contents
         * "SECTION_SETTING\0SETTING\0"
         */
        public function setting() { return $this->_m_setting; }
    }
}

/**
 * The save settings message persists the device's current settings
 * configuration to its onboard flash memory file system.
 */

namespace Settings {
    class MsgSettingsSave extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Settings $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * This message registers the presence and default value of a setting with
 * a settings daemon.  The host should reply with MSG_SETTINGS_WRITE for
 * this setting to set the initial value.
 */

namespace Settings {
    class MsgSettingsRegister extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Settings $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_setting = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_setting;

        /**
         * A NULL-terminated and delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE".
         */
        public function setting() { return $this->_m_setting; }
    }
}

/**
 * The settings message for iterating through the settings values. A device
 * will respond to this message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".
 */

namespace Settings {
    class MsgSettingsReadByIndexReq extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Settings $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_index = $this->_io->readU2le();
        }
        protected $_m_index;

        /**
         * An index into the device settings, with values ranging from 0 to
         * length(settings).
         */
        public function index() { return $this->_m_index; }
    }
}

/**
 * The settings message for indicating end of the settings values.
 */

namespace Settings {
    class MsgSettingsReadByIndexDone extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Settings $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * The setting message writes the device configuration for a particular
 * setting via A NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
 * denotes the NULL character and where quotation marks are omitted. A
 * device will only process to this message when it is received from sender
 * ID 0x42. An example string that could be sent to a device is
 * "solution\0soln_freq\010\0".
 */

namespace Settings {
    class MsgSettingsWrite extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Settings $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_setting = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_setting;

        /**
         * A NULL-terminated and NULL-delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE\0"
         */
        public function setting() { return $this->_m_setting; }
    }
}
