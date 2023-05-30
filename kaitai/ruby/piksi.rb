# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Piksi < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # The state of a network interface on the Piksi. Data is made to reflect
  # output of ifaddrs struct returned by getifaddrs in c.
  class MsgNetworkStateResp < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @ipv4_address = []
      (4).times { |i|
        @ipv4_address << @_io.read_u1
      }
      @ipv4_mask_size = @_io.read_u1
      @ipv6_address = []
      (16).times { |i|
        @ipv6_address << @_io.read_u1
      }
      @ipv6_mask_size = @_io.read_u1
      @rx_bytes = @_io.read_u4le
      @tx_bytes = @_io.read_u4le
      @interface_name = (@_io.read_bytes(16)).force_encoding("ascii")
      @flags = @_io.read_u4le
      self
    end

    ##
    # IPv4 address (all zero when unavailable)
    attr_reader :ipv4_address

    ##
    # IPv4 netmask CIDR notation
    attr_reader :ipv4_mask_size

    ##
    # IPv6 address (all zero when unavailable)
    attr_reader :ipv6_address

    ##
    # IPv6 netmask CIDR notation
    attr_reader :ipv6_mask_size

    ##
    # Number of Rx bytes
    attr_reader :rx_bytes

    ##
    # Number of Tx bytes
    attr_reader :tx_bytes

    ##
    # Interface Name
    attr_reader :interface_name

    ##
    # Interface flags from SIOCGIFFLAGS
    attr_reader :flags
  end

  ##
  # The bandwidth usage for each interface can be reported within this
  # struct and utilize multiple fields to fully specify the type of traffic
  # that is being tracked. As either the interval of collection or the
  # collection time may vary, both a timestamp and period field is provided,
  # though may not necessarily be populated with a value.
  class NetworkUsage < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @duration = @_io.read_u8le
      @total_bytes = @_io.read_u8le
      @rx_bytes = @_io.read_u4le
      @tx_bytes = @_io.read_u4le
      @interface_name = (@_io.read_bytes(16)).force_encoding("ascii")
      self
    end

    ##
    # Duration over which the measurement was collected
    attr_reader :duration

    ##
    # Number of bytes handled in total within period
    attr_reader :total_bytes

    ##
    # Number of bytes transmitted within period
    attr_reader :rx_bytes

    ##
    # Number of bytes received within period
    attr_reader :tx_bytes

    ##
    # Interface Name
    attr_reader :interface_name
  end

  ##
  # The response to MSG_COMMAND_REQ with the return code of the command.  A
  # return code of zero indicates success.
  class MsgCommandResp < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sequence = @_io.read_u4le
      @code = @_io.read_s4le
      self
    end

    ##
    # Sequence number
    attr_reader :sequence

    ##
    # Exit code
    attr_reader :code
  end

  ##
  # Returns the standard output and standard error of the command requested
  # by MSG_COMMAND_REQ. The sequence number can be used to filter for
  # filtering the correct command.
  class MsgCommandOutput < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sequence = @_io.read_u4le
      @line = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # Sequence number
    attr_reader :sequence

    ##
    # Line of standard output or standard error
    attr_reader :line
  end

  ##
  # Statistics on the latency of observations received from the base
  # station. As observation packets are received their GPS time is compared
  # to the current GPS time calculated locally by the receiver to give a
  # precise measurement of the end-to-end communication latency in the
  # system.
  class Latency < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @avg = @_io.read_s4le
      @lmin = @_io.read_s4le
      @lmax = @_io.read_s4le
      @current = @_io.read_s4le
      self
    end

    ##
    # Average latency
    attr_reader :avg

    ##
    # Minimum latency
    attr_reader :lmin

    ##
    # Maximum latency
    attr_reader :lmax

    ##
    # Smoothed estimate of the current latency
    attr_reader :current
  end

  ##
  # The thread usage message from the device reports real-time operating
  # system (RTOS) thread usage statistics for the named thread. The reported
  # percentage values must be normalized.
  class MsgThreadState < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @name = (@_io.read_bytes(20)).force_encoding("ascii")
      @cpu = @_io.read_u2le
      @stack_free = @_io.read_u4le
      self
    end

    ##
    # Thread name (NULL terminated)
    attr_reader :name

    ##
    # Percentage cpu use for this thread. Values range from 0 - 1000 and
    # needs to be renormalized to 100
    attr_reader :cpu

    ##
    # Free stack space for this thread
    attr_reader :stack_free
  end

  ##
  # Deprecated
  class MsgUartStateDepa < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @uart_a = UartChannel.new(@_io, self, @_root)
      @uart_b = UartChannel.new(@_io, self, @_root)
      @uart_ftdi = UartChannel.new(@_io, self, @_root)
      @latency = Latency.new(@_io, self, @_root)
      self
    end

    ##
    # State of UART A
    attr_reader :uart_a

    ##
    # State of UART B
    attr_reader :uart_b

    ##
    # State of UART FTDI (USB logger)
    attr_reader :uart_ftdi

    ##
    # UART communication latency
    attr_reader :latency
  end

  ##
  # Request state of Piksi network interfaces. Output will be sent in
  # MSG_NETWORK_STATE_RESP messages.
  class MsgNetworkStateReq < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      self
    end
  end

  ##
  # This message contains temperature and voltage level measurements from
  # the processor's monitoring system and the RF frontend die temperature if
  # available.
  class MsgDeviceMonitor < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @dev_vin = @_io.read_s2le
      @cpu_vint = @_io.read_s2le
      @cpu_vaux = @_io.read_s2le
      @cpu_temperature = @_io.read_s2le
      @fe_temperature = @_io.read_s2le
      self
    end

    ##
    # Device V_in
    attr_reader :dev_vin

    ##
    # Processor V_int
    attr_reader :cpu_vint

    ##
    # Processor V_aux
    attr_reader :cpu_vaux

    ##
    # Processor temperature
    attr_reader :cpu_temperature

    ##
    # Frontend temperature (if available)
    attr_reader :fe_temperature
  end

  ##
  # Deprecated.
  class MsgMaskSatelliteDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @mask = @_io.read_u1
      @sid = Gnss::GnssSignalDep.new(@_io, self, @_root)
      self
    end

    ##
    # Mask of systems that should ignore this satellite.
    attr_reader :mask

    ##
    # GNSS signal for which the mask is applied
    attr_reader :sid
  end

  ##
  # The UART message reports data latency and throughput of the UART
  # channels providing SBP I/O. On the default Piksi configuration, UARTs A
  # and B are used for telemetry radios, but can also be host access ports
  # for embedded hosts, or other interfaces in future. The reported
  # percentage values must be normalized. Observations latency and period
  # can be used to assess the health of the differential corrections link.
  # Latency provides the timeliness of received base observations while the
  # period indicates their likelihood of transmission.
  class MsgUartState < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @uart_a = UartChannel.new(@_io, self, @_root)
      @uart_b = UartChannel.new(@_io, self, @_root)
      @uart_ftdi = UartChannel.new(@_io, self, @_root)
      @latency = Latency.new(@_io, self, @_root)
      @obs_period = Period.new(@_io, self, @_root)
      self
    end

    ##
    # State of UART A
    attr_reader :uart_a

    ##
    # State of UART B
    attr_reader :uart_b

    ##
    # State of UART FTDI (USB logger)
    attr_reader :uart_ftdi

    ##
    # UART communication latency
    attr_reader :latency

    ##
    # Observation receipt period
    attr_reader :obs_period
  end

  ##
  # Spectrum analyzer packet.
  class MsgSpecan < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @channel_tag = @_io.read_u2le
      @t = Gnss::GpsTime.new(@_io, self, @_root)
      @freq_ref = @_io.read_f4le
      @freq_step = @_io.read_f4le
      @amplitude_ref = @_io.read_f4le
      @amplitude_unit = @_io.read_f4le
      @amplitude_value = []
      i = 0
      while not @_io.eof?
        @amplitude_value << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # Channel ID
    attr_reader :channel_tag

    ##
    # Receiver time of this observation
    attr_reader :t

    ##
    # Reference frequency of this packet
    attr_reader :freq_ref

    ##
    # Frequency step of points in this packet
    attr_reader :freq_step

    ##
    # Reference amplitude of this packet
    attr_reader :amplitude_ref

    ##
    # Amplitude unit value of points in this packet
    attr_reader :amplitude_unit

    ##
    # Amplitude values (in the above units) of points in this packet
    attr_reader :amplitude_value
  end

  ##
  # This message reports the state of the Integer Ambiguity Resolution (IAR)
  # process, which resolves unknown integer ambiguities from double-
  # differenced carrier-phase measurements from satellite observations.
  class MsgIarState < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @num_hyps = @_io.read_u4le
      self
    end

    ##
    # Number of integer ambiguity hypotheses remaining
    attr_reader :num_hyps
  end

  ##
  # This is a legacy message for sending and loading a satellite alamanac
  # onto the Piksi's flash memory from the host.
  class MsgAlmanac < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      self
    end
  end

  ##
  # This message resets either the DGNSS Kalman filters or Integer Ambiguity
  # Resolution (IAR) process.
  class MsgResetFilters < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @filter = @_io.read_u1
      self
    end

    ##
    # Filter flags
    attr_reader :filter
  end

  ##
  # Throughput, utilization, and error counts on the RX/TX buffers of this
  # UART channel. The reported percentage values must be normalized.
  class UartChannel < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tx_throughput = @_io.read_f4le
      @rx_throughput = @_io.read_f4le
      @crc_error_count = @_io.read_u2le
      @io_error_count = @_io.read_u2le
      @tx_buffer_level = @_io.read_u1
      @rx_buffer_level = @_io.read_u1
      self
    end

    ##
    # UART transmit throughput
    attr_reader :tx_throughput

    ##
    # UART receive throughput
    attr_reader :rx_throughput

    ##
    # UART CRC error count
    attr_reader :crc_error_count

    ##
    # UART IO error count
    attr_reader :io_error_count

    ##
    # UART transmit buffer percentage utilization (ranges from 0 to 255)
    attr_reader :tx_buffer_level

    ##
    # UART receive buffer percentage utilization (ranges from 0 to 255)
    attr_reader :rx_buffer_level
  end

  ##
  # Request the recipient to execute an command. Output will be sent in
  # MSG_LOG messages, and the exit code will be returned with
  # MSG_COMMAND_RESP.
  class MsgCommandReq < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sequence = @_io.read_u4le
      @command = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # Sequence number
    attr_reader :sequence

    ##
    # Command line to execute
    attr_reader :command
  end

  ##
  # This message allows setting a mask to prevent a particular satellite
  # from being used in various Piksi subsystems.
  class MsgMaskSatellite < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @mask = @_io.read_u1
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      self
    end

    ##
    # Mask of systems that should ignore this satellite.
    attr_reader :mask

    ##
    # GNSS signal for which the mask is applied
    attr_reader :sid
  end

  ##
  # The bandwidth usage, a list of usage by interface.
  class MsgNetworkBandwidthUsage < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @interfaces = []
      i = 0
      while not @_io.eof?
        @interfaces << NetworkUsage.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Usage measurement array
    attr_reader :interfaces
  end

  ##
  # This message from the host resets the Piksi back into the bootloader.
  class MsgReset < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @flags = @_io.read_u4le
      self
    end

    ##
    # Reset flags
    attr_reader :flags
  end

  ##
  # If a cell modem is present on a piksi device, this message will be send
  # periodically to update the host on the status of the modem and its
  # various parameters.
  class MsgCellModemStatus < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @signal_strength = @_io.read_s1
      @signal_error_rate = @_io.read_f4le
      @reserved = []
      i = 0
      while not @_io.eof?
        @reserved << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # Received cell signal strength in dBm, zero translates to unknown
    attr_reader :signal_strength

    ##
    # BER as reported by the modem, zero translates to unknown
    attr_reader :signal_error_rate

    ##
    # Unspecified data TBD for this schema
    attr_reader :reserved
  end

  ##
  # This message describes the gain of each channel in the receiver
  # frontend. Each gain is encoded as a non-dimensional percentage relative
  # to the maximum range possible for the gain stage of the frontend. By
  # convention, each gain array has 8 entries and the index of the array
  # corresponding to the index of the rf channel in the frontend. A gain of
  # 127 percent encodes that rf channel is not present in the hardware. A
  # negative value implies an error for the particular gain stage as
  # reported by the frontend.
  class MsgFrontEndGain < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @rf_gain = []
      (8).times { |i|
        @rf_gain << @_io.read_s1
      }
      @if_gain = []
      (8).times { |i|
        @if_gain << @_io.read_s1
      }
      self
    end

    ##
    # RF gain for each frontend channel
    attr_reader :rf_gain

    ##
    # Intermediate frequency gain for each frontend channel
    attr_reader :if_gain
  end

  ##
  # This message from the host resets the Piksi back into the bootloader.
  class MsgResetDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      self
    end
  end

  ##
  # This message sets up timing functionality using a coarse GPS time
  # estimate sent by the host.
  class MsgSetTime < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      self
    end
  end

  ##
  # This is an unused legacy message for result reporting from the CW
  # interference channel on the SwiftNAP. This message will be removed in a
  # future release.
  class MsgCwResults < Kaitai::Struct::Struct
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
  class MsgSpecanDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @channel_tag = @_io.read_u2le
      @t = Gnss::GpsTimeDep.new(@_io, self, @_root)
      @freq_ref = @_io.read_f4le
      @freq_step = @_io.read_f4le
      @amplitude_ref = @_io.read_f4le
      @amplitude_unit = @_io.read_f4le
      @amplitude_value = []
      i = 0
      while not @_io.eof?
        @amplitude_value << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # Channel ID
    attr_reader :channel_tag

    ##
    # Receiver time of this observation
    attr_reader :t

    ##
    # Reference frequency of this packet
    attr_reader :freq_ref

    ##
    # Frequency step of points in this packet
    attr_reader :freq_step

    ##
    # Reference amplitude of this packet
    attr_reader :amplitude_ref

    ##
    # Amplitude unit value of points in this packet
    attr_reader :amplitude_unit

    ##
    # Amplitude values (in the above units) of points in this packet
    attr_reader :amplitude_value
  end

  ##
  # Deprecated
  class MsgInitBaseDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      self
    end
  end

  ##
  # Statistics on the period of observations received from the base station.
  # As complete observation sets are received, their time of reception is
  # compared with the prior set''s time of reception. This measurement
  # provides a proxy for link quality as incomplete or missing sets will
  # increase the period.  Long periods can cause momentary RTK solution
  # outages.
  class Period < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @avg = @_io.read_s4le
      @pmin = @_io.read_s4le
      @pmax = @_io.read_s4le
      @current = @_io.read_s4le
      self
    end

    ##
    # Average period
    attr_reader :avg

    ##
    # Minimum period
    attr_reader :pmin

    ##
    # Maximum period
    attr_reader :pmax

    ##
    # Smoothed estimate of the current period
    attr_reader :current
  end

  ##
  # This is an unused legacy message from the host for starting the CW
  # interference channel on the SwiftNAP. This message will be removed in a
  # future release.
  class MsgCwStart < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      self
    end
  end
end
