# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Bootload < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # The device message from the host reads a unique device identifier from
  # the SwiftNAP, an FPGA. The host requests the ID by sending a
  # MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
  # MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
  # that this ID is tied to the FPGA, and not related to the Piksi's serial
  # number.
  class MsgNapDeviceDnaReq < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      self
    end
  end

  ##
  # The host initiates the bootloader to jump to the application.
  class MsgBootloaderJumpToApp < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @jump = @_io.read_u1
      self
    end

    ##
    # Ignored by the device
    attr_reader :jump
  end

  ##
  # The handshake message response from the device establishes a handshake
  # between the device bootloader and the host. The request from the host is
  # MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader
  # version number and the SBP protocol version number.
  class MsgBootloaderHandshakeResp < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @flags = @_io.read_u4le
      @version = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # Bootloader flags
    attr_reader :flags

    ##
    # Bootloader version number
    attr_reader :version
  end

  ##
  # The device message from the host reads a unique device identifier from
  # the SwiftNAP, an FPGA. The host requests the ID by sending a
  # MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
  # MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
  # that this ID is tied to the FPGA, and not related to the Piksi's serial
  # number.
  class MsgNapDeviceDnaResp < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @dna = []
      (8).times { |i|
        @dna << @_io.read_u1
      }
      self
    end

    ##
    # 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the
    # right.
    attr_reader :dna
  end

  ##
  # The handshake message request from the host establishes a handshake
  # between the device bootloader and the host. The response from the device
  # is MSG_BOOTLOADER_HANDSHAKE_RESP.
  class MsgBootloaderHandshakeReq < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      self
    end
  end

  ##
  # Deprecated.
  class MsgBootloaderHandshakeDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @handshake = []
      i = 0
      while not @_io.eof?
        @handshake << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # Version number string (not NULL terminated)
    attr_reader :handshake
  end
end
