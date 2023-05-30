# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Ndb < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # This message is sent out when an object is stored into NDB. If needed
  # message could also be sent out when fetching an object from NDB.
  class MsgNdbEvent < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @recv_time = @_io.read_u8le
      @event = @_io.read_u1
      @object_type = @_io.read_u1
      @result = @_io.read_u1
      @data_source = @_io.read_u1
      @object_sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @src_sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @original_sender = @_io.read_u2le
      self
    end

    ##
    # HW time in milliseconds.
    attr_reader :recv_time

    ##
    # Event type.
    attr_reader :event

    ##
    # Event object type.
    attr_reader :object_type

    ##
    # Event result.
    attr_reader :result

    ##
    # Data source for STORE event, reserved for other events.
    attr_reader :data_source

    ##
    # GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid
    # indicates for which signal the object belongs to. Reserved in other
    # cases.
    attr_reader :object_sid

    ##
    # GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono
    # OR L2C capabilities AND data_source is NDB_DS_RECEIVER sid indicates
    # from which SV data was decoded. Reserved in other cases.
    attr_reader :src_sid

    ##
    # A unique identifier of the sending hardware. For v1.0, set to the 2
    # least significant bytes of the device serial number, valid only if
    # data_source is NDB_DS_SBP. Reserved in case of other data_source.
    attr_reader :original_sender
  end
end
