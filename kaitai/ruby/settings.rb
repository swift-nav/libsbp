# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Settings < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # The setting message with which the device responds after a
  # MSG_SETTING_READ_REQ is sent to device. The string field is a NULL-
  # terminated and NULL-delimited string with contents
  # "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
  # denotes the NULL character and where quotation marks are omitted. An
  # example string that could be sent from device is
  # "solution\0soln_freq\010\0".
  class MsgSettingsReadResp < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @setting = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # A NULL-terminated and NULL-delimited string with contents
    # "SECTION_SETTING\0SETTING\0VALUE\0"
    attr_reader :setting
  end

  ##
  # Return the status of a write request with the new value of the setting.
  # If the requested value is rejected, the current value will be returned.
  # The string field is a NULL-terminated and NULL-delimited string with
  # contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape
  # sequence denotes the NULL character and where quotation marks are
  # omitted. An example string that could be sent from device is
  # "solution\0soln_freq\010\0".
  class MsgSettingsWriteResp < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @status = @_io.read_u1
      @setting = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # Write status
    attr_reader :status

    ##
    # A NULL-terminated and delimited string with contents
    # "SECTION_SETTING\0SETTING\0VALUE\0"
    attr_reader :setting
  end

  ##
  # This message responds to setting registration with the effective value.
  # The effective value shall differ from the given default value if setting
  # was already registered or is available in the permanent setting storage
  # and had a different value.
  class MsgSettingsRegisterResp < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @status = @_io.read_u1
      @setting = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # Register status
    attr_reader :status

    ##
    # A NULL-terminated and delimited string with contents
    # "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
    # according to the status field.
    attr_reader :setting
  end

  ##
  # The settings message that reports the value of a setting at an index.
  # 
  # In the string field, it reports NULL-terminated and delimited string
  # with contents "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where
  # the '\0' escape sequence denotes the NULL character and where quotation
  # marks are omitted. The FORMAT_TYPE field is optional and denotes
  # possible string values of the setting as a hint to the user. If
  # included, the format type portion of the string has the format
  # "enum:value1,value2,value3". An example string that could be sent from
  # the device is "simulator\0enabled\0True\0enum:True,False\0".
  class MsgSettingsReadByIndexResp < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @index = @_io.read_u2le
      @setting = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # An index into the device settings, with values ranging from 0 to
    # length(settings)
    attr_reader :index

    ##
    # A NULL-terminated and delimited string with contents
    # "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
    attr_reader :setting
  end

  ##
  # The setting message that reads the device configuration. The string
  # field is a NULL-terminated and NULL-delimited string with contents
  # "SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the
  # NULL character and where quotation marks are omitted. An example string
  # that could be sent to a device is "solution\0soln_freq\0". A device will
  # only respond to this message when it is received from sender ID 0x42. A
  # device should respond with a MSG_SETTINGS_READ_RESP message (msg_id
  # 0x00A5).
  class MsgSettingsReadReq < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @setting = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # A NULL-terminated and NULL-delimited string with contents
    # "SECTION_SETTING\0SETTING\0"
    attr_reader :setting
  end

  ##
  # The save settings message persists the device's current settings
  # configuration to its onboard flash memory file system.
  class MsgSettingsSave < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      self
    end
  end

  ##
  # This message registers the presence and default value of a setting with
  # a settings daemon.  The host should reply with MSG_SETTINGS_WRITE for
  # this setting to set the initial value.
  class MsgSettingsRegister < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @setting = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # A NULL-terminated and delimited string with contents
    # "SECTION_SETTING\0SETTING\0VALUE".
    attr_reader :setting
  end

  ##
  # The settings message for iterating through the settings values. A device
  # will respond to this message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".
  class MsgSettingsReadByIndexReq < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @index = @_io.read_u2le
      self
    end

    ##
    # An index into the device settings, with values ranging from 0 to
    # length(settings).
    attr_reader :index
  end

  ##
  # The settings message for indicating end of the settings values.
  class MsgSettingsReadByIndexDone < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      self
    end
  end

  ##
  # The setting message writes the device configuration for a particular
  # setting via A NULL-terminated and NULL-delimited string with contents
  # "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
  # denotes the NULL character and where quotation marks are omitted. A
  # device will only process to this message when it is received from sender
  # ID 0x42. An example string that could be sent to a device is
  # "solution\0soln_freq\010\0".
  class MsgSettingsWrite < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @setting = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # A NULL-terminated and NULL-delimited string with contents
    # "SECTION_SETTING\0SETTING\0VALUE\0"
    attr_reader :setting
  end
end
