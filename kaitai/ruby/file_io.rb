# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class FileIo < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # The file write message writes a certain length (up to 255 bytes) of data
  # to a file at a given offset. Returns a copy of the original
  # MSG_FILEIO_WRITE_RESP message to check integrity of the write. The
  # sequence number in the request will be returned in the response. If
  # message is invalid, a followup MSG_PRINT message will print "Invalid
  # fileio write message". A device will only process this message when it
  # is received from sender ID 0x42.
  class MsgFileioWriteReq < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sequence = @_io.read_u4le
      @offset = @_io.read_u4le
      @filename = (@_io.read_bytes_full).force_encoding("ascii")
      @data = []
      i = 0
      while not @_io.eof?
        @data << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # Write sequence number
    attr_reader :sequence

    ##
    # Offset into the file at which to start writing in bytes
    attr_reader :offset

    ##
    # Name of the file to write to
    attr_reader :filename

    ##
    # Variable-length array of data to write
    attr_reader :data
  end

  ##
  # The advice on the optimal configuration for a FileIO transfer.  Newer
  # version of FileIO can support greater throughput by supporting a large
  # window of FileIO data that can be in-flight during read or write
  # operations.
  class MsgFileioConfigResp < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sequence = @_io.read_u4le
      @window_size = @_io.read_u4le
      @batch_size = @_io.read_u4le
      @fileio_version = @_io.read_u4le
      self
    end

    ##
    # Advice sequence number
    attr_reader :sequence

    ##
    # The number of SBP packets in the data in-flight window
    attr_reader :window_size

    ##
    # The number of SBP packets sent in one PDU
    attr_reader :batch_size

    ##
    # The version of FileIO that is supported
    attr_reader :fileio_version
  end

  ##
  # The file remove message deletes a file from the file system. If the
  # message is invalid, a followup MSG_PRINT message will print "Invalid
  # fileio remove message". A device will only process this message when it
  # is received from sender ID 0x42.
  class MsgFileioRemove < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @filename = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # Name of the file to delete
    attr_reader :filename
  end

  ##
  # Requests advice on the optimal configuration for a FileIO transfer.
  # Newer version of FileIO can support greater throughput by supporting a
  # large window of FileIO data that can be in-flight during read or write
  # operations.
  class MsgFileioConfigReq < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sequence = @_io.read_u4le
      self
    end

    ##
    # Advice sequence number
    attr_reader :sequence
  end

  ##
  # The read directory message lists the files in a directory on the
  # device's onboard flash file system.  The offset parameter can be used to
  # skip the first n elements of the file list. Returns a
  # MSG_FILEIO_READ_DIR_RESP message containing the directory listings as a
  # NULL delimited list. The listing is chunked over multiple SBP packets.
  # The sequence number in the request will be returned in the response.  If
  # message is invalid, a followup MSG_PRINT message will print "Invalid
  # fileio read message". A device will only respond to this message when it
  # is received from sender ID 0x42.
  class MsgFileioReadDirReq < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sequence = @_io.read_u4le
      @offset = @_io.read_u4le
      @dirname = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # Read sequence number
    attr_reader :sequence

    ##
    # The offset to skip the first n elements of the file list
    attr_reader :offset

    ##
    # Name of the directory to list
    attr_reader :dirname
  end

  ##
  # The file write message writes a certain length (up to 255 bytes) of data
  # to a file at a given offset. The message is a copy of the original
  # MSG_FILEIO_WRITE_REQ message to check integrity of the write. The
  # sequence number in the response is preserved from the request.
  class MsgFileioWriteResp < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sequence = @_io.read_u4le
      self
    end

    ##
    # Write sequence number
    attr_reader :sequence
  end

  ##
  # The read directory message lists the files in a directory on the
  # device's onboard flash file system. Message contains the directory
  # listings as a NULL delimited list. The listing is chunked over multiple
  # SBP packets and the end of the list is identified by an packet with no
  # entries. The sequence number in the response is preserved from the
  # request.
  class MsgFileioReadDirResp < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sequence = @_io.read_u4le
      @contents = []
      i = 0
      while not @_io.eof?
        @contents << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # Read sequence number
    attr_reader :sequence

    ##
    # Contents of read directory
    attr_reader :contents
  end

  ##
  # The file read message reads a certain length (up to 255 bytes) from a
  # given offset into a file, and returns the data in a MSG_FILEIO_READ_RESP
  # message where the message length field indicates how many bytes were
  # successfully read. The sequence number in the request will be returned
  # in the response. If the message is invalid, a followup MSG_PRINT message
  # will print "Invalid fileio read message". A device will only respond to
  # this message when it is received from sender ID 0x42.
  class MsgFileioReadReq < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sequence = @_io.read_u4le
      @offset = @_io.read_u4le
      @chunk_size = @_io.read_u1
      @filename = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # Read sequence number
    attr_reader :sequence

    ##
    # File offset
    attr_reader :offset

    ##
    # Chunk size to read
    attr_reader :chunk_size

    ##
    # Name of the file to read from
    attr_reader :filename
  end

  ##
  # The file read message reads a certain length (up to 255 bytes) from a
  # given offset into a file, and returns the data in a message where the
  # message length field indicates how many bytes were successfully read.
  # The sequence number in the response is preserved from the request.
  class MsgFileioReadResp < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sequence = @_io.read_u4le
      @contents = []
      i = 0
      while not @_io.eof?
        @contents << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # Read sequence number
    attr_reader :sequence

    ##
    # Contents of read file
    attr_reader :contents
  end
end
