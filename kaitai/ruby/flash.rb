# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Flash < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # This message defines success or failure codes for a variety of flash
  # memory requests from the host to the device. Flash read and write
  # messages, such as MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return
  # this message on failure.
  class MsgFlashDone < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @response = @_io.read_u1
      self
    end

    ##
    # Response flags
    attr_reader :response
  end

  ##
  # The flash status message writes to the 8-bit M25 flash status register.
  # The device replies with a MSG_FLASH_DONE message.
  class MsgM25FlashWriteStatus < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @status = []
      (1).times { |i|
        @status << @_io.read_u1
      }
      self
    end

    ##
    # Byte to write to the M25 flash status register
    attr_reader :status
  end

  ##
  # The flash read message reads a set of addresses of either the STM or M25
  # onboard flash. The device replies with a MSG_FLASH_READ_RESP message
  # containing either the read data on success or a MSG_FLASH_DONE message
  # containing the return code FLASH_INVALID_LEN (2) if the maximum read
  # size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
  # the allowed range.
  class MsgFlashReadResp < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @target = @_io.read_u1
      @addr_start = []
      (3).times { |i|
        @addr_start << @_io.read_u1
      }
      @addr_len = @_io.read_u1
      self
    end

    ##
    # Target flags
    attr_reader :target

    ##
    # Starting address offset to read from
    attr_reader :addr_start

    ##
    # Length of set of addresses to read, counting up from starting
    # address
    attr_reader :addr_len
  end

  ##
  # The flash erase message from the host erases a sector of either the STM
  # or M25 onboard flash memory. The device will reply with a MSG_FLASH_DONE
  # message containing the return code - FLASH_OK (0) on success or
  # FLASH_INVALID_FLASH (1) if the flash specified is invalid.
  class MsgFlashErase < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @target = @_io.read_u1
      @sector_num = @_io.read_u4le
      self
    end

    ##
    # Target flags
    attr_reader :target

    ##
    # Flash sector number to erase (0-11 for the STM, 0-15 for the M25)
    attr_reader :sector_num
  end

  ##
  # This message reads the device's hard-coded unique ID. The host requests
  # the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
  # MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
  class MsgStmUniqueIdResp < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @stm_id = []
      (12).times { |i|
        @stm_id << @_io.read_u1
      }
      self
    end

    ##
    # Device unique ID
    attr_reader :stm_id
  end

  ##
  # This message reads the device's hard-coded unique ID. The host requests
  # the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
  # MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
  class MsgStmUniqueIdReq < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      self
    end
  end

  ##
  # The flash program message programs a set of addresses of either the STM
  # or M25 flash. The device replies with either a MSG_FLASH_DONE message
  # containing the return code FLASH_OK (0) on success, or FLASH_INVALID_LEN
  # (2) if the maximum write size is exceeded. Note that the sector-
  # containing addresses must be erased before addresses can be programmed.
  class MsgFlashProgram < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @target = @_io.read_u1
      @addr_start = []
      (3).times { |i|
        @addr_start << @_io.read_u1
      }
      @addr_len = @_io.read_u1
      @data = []
      i = 0
      while not @_io.eof?
        @data << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # Target flags
    attr_reader :target

    ##
    # Starting address offset to program
    attr_reader :addr_start

    ##
    # Length of set of addresses to program, counting up from starting
    # address
    attr_reader :addr_len

    ##
    # Data to program addresses with, with length N=addr_len
    attr_reader :data
  end

  ##
  # The flash read message reads a set of addresses of either the STM or M25
  # onboard flash. The device replies with a MSG_FLASH_READ_RESP message
  # containing either the read data on success or a MSG_FLASH_DONE message
  # containing the return code FLASH_INVALID_LEN (2) if the maximum read
  # size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
  # the allowed range.
  class MsgFlashReadReq < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @target = @_io.read_u1
      @addr_start = []
      (3).times { |i|
        @addr_start << @_io.read_u1
      }
      @addr_len = @_io.read_u1
      self
    end

    ##
    # Target flags
    attr_reader :target

    ##
    # Starting address offset to read from
    attr_reader :addr_start

    ##
    # Length of set of addresses to read, counting up from starting
    # address
    attr_reader :addr_len
  end

  ##
  # The flash unlock message unlocks a sector of the STM flash memory. The
  # device replies with a MSG_FLASH_DONE message.
  class MsgStmFlashUnlockSector < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sector = @_io.read_u4le
      self
    end

    ##
    # Flash sector number to unlock
    attr_reader :sector
  end

  ##
  # The flash lock message locks a sector of the STM flash memory. The
  # device replies with a MSG_FLASH_DONE message.
  class MsgStmFlashLockSector < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sector = @_io.read_u4le
      self
    end

    ##
    # Flash sector number to lock
    attr_reader :sector
  end
end
