# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Linux < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # Summaries the socket usage across the system.
  class MsgLinuxSocketUsage < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @avg_queue_depth = @_io.read_u4le
      @max_queue_depth = @_io.read_u4le
      @socket_state_counts = []
      (16).times { |i|
        @socket_state_counts << @_io.read_u2le
      }
      @socket_type_counts = []
      (16).times { |i|
        @socket_type_counts << @_io.read_u2le
      }
      self
    end

    ##
    # average socket queue depths across all sockets on the system
    attr_reader :avg_queue_depth

    ##
    # the max queue depth seen within the reporting period
    attr_reader :max_queue_depth

    ##
    # A count for each socket type reported in the `socket_types_reported`
    # field, the first entry corresponds to the first enabled bit in
    # `types_reported`.
    attr_reader :socket_state_counts

    ##
    # A count for each socket type reported in the `socket_types_reported`
    # field, the first entry corresponds to the first enabled bit in
    # `types_reported`.
    attr_reader :socket_type_counts
  end

  ##
  # This presents a summary of CPU and memory utilization, including a
  # timestamp.
  class MsgLinuxSysState < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @mem_total = @_io.read_u2le
      @pcpu = @_io.read_u1
      @pmem = @_io.read_u1
      @procs_starting = @_io.read_u2le
      @procs_stopping = @_io.read_u2le
      @pid_count = @_io.read_u2le
      @time = @_io.read_u4le
      @flags = @_io.read_u1
      self
    end

    ##
    # total system memory, in MiB
    attr_reader :mem_total

    ##
    # percent of CPU used, expressed as a fraction of 256
    attr_reader :pcpu

    ##
    # percent of memory used, expressed as a fraction of 256
    attr_reader :pmem

    ##
    # number of processes that started during collection phase
    attr_reader :procs_starting

    ##
    # number of processes that stopped during collection phase
    attr_reader :procs_stopping

    ##
    # the count of processes on the system
    attr_reader :pid_count

    ##
    # timestamp of message, refer to flags field for how to interpret
    attr_reader :time

    ##
    # flags
    attr_reader :flags
  end

  ##
  # Deprecated.
  class MsgLinuxCpuStateDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @index = @_io.read_u1
      @pid = @_io.read_u2le
      @pcpu = @_io.read_u1
      @tname = (@_io.read_bytes(15)).force_encoding("ascii")
      @cmdline = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # sequence of this status message, values from 0-9
    attr_reader :index

    ##
    # the PID of the process
    attr_reader :pid

    ##
    # percent of cpu used, expressed as a fraction of 256
    attr_reader :pcpu

    ##
    # fixed length string representing the thread name
    attr_reader :tname

    ##
    # the command line (as much as it fits in the remaining packet)
    attr_reader :cmdline
  end

  ##
  # This message indicates the process state of the top 10 heaviest
  # consumers of memory on the system, including a timestamp.
  class MsgLinuxMemState < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @index = @_io.read_u1
      @pid = @_io.read_u2le
      @pmem = @_io.read_u1
      @time = @_io.read_u4le
      @flags = @_io.read_u1
      @tname = (@_io.read_bytes(15)).force_encoding("ascii")
      @cmdline = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # sequence of this status message, values from 0-9
    attr_reader :index

    ##
    # the PID of the process
    attr_reader :pid

    ##
    # percent of memory used, expressed as a fraction of 256
    attr_reader :pmem

    ##
    # timestamp of message, refer to flags field for how to interpret
    attr_reader :time

    ##
    # flags
    attr_reader :flags

    ##
    # fixed length string representing the thread name
    attr_reader :tname

    ##
    # the command line (as much as it fits in the remaining packet)
    attr_reader :cmdline
  end

  ##
  # Top 10 list of processes with a large number of open file descriptors.
  class MsgLinuxProcessFdCount < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @index = @_io.read_u1
      @pid = @_io.read_u2le
      @fd_count = @_io.read_u2le
      @cmdline = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # sequence of this status message, values from 0-9
    attr_reader :index

    ##
    # the PID of the process in question
    attr_reader :pid

    ##
    # a count of the number of file descriptors opened by the process
    attr_reader :fd_count

    ##
    # the command line of the process in question
    attr_reader :cmdline
  end

  ##
  # Deprecated.
  class MsgLinuxMemStateDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @index = @_io.read_u1
      @pid = @_io.read_u2le
      @pmem = @_io.read_u1
      @tname = (@_io.read_bytes(15)).force_encoding("ascii")
      @cmdline = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # sequence of this status message, values from 0-9
    attr_reader :index

    ##
    # the PID of the process
    attr_reader :pid

    ##
    # percent of memory used, expressed as a fraction of 256
    attr_reader :pmem

    ##
    # fixed length string representing the thread name
    attr_reader :tname

    ##
    # the command line (as much as it fits in the remaining packet)
    attr_reader :cmdline
  end

  ##
  # Top 10 list of sockets with deep queues.
  class MsgLinuxProcessSocketQueues < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @index = @_io.read_u1
      @pid = @_io.read_u2le
      @recv_queued = @_io.read_u2le
      @send_queued = @_io.read_u2le
      @socket_types = @_io.read_u2le
      @socket_states = @_io.read_u2le
      @address_of_largest = (@_io.read_bytes(64)).force_encoding("ascii")
      @cmdline = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # sequence of this status message, values from 0-9
    attr_reader :index

    ##
    # the PID of the process in question
    attr_reader :pid

    ##
    # the total amount of receive data queued for this process
    attr_reader :recv_queued

    ##
    # the total amount of send data queued for this process
    attr_reader :send_queued

    ##
    # A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
    # 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
    # (unknown)
    attr_reader :socket_types

    ##
    # A bitfield indicating the socket states: 0x1 (established), 0x2
    # (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
    # 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
    # ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
    # 0x8000 (unknown)
    attr_reader :socket_states

    ##
    # Address of the largest queue, remote or local depending on the
    # directionality of the connection.
    attr_reader :address_of_largest

    ##
    # the command line of the process in question
    attr_reader :cmdline
  end

  ##
  # Deprecated.
  class MsgLinuxSysStateDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @mem_total = @_io.read_u2le
      @pcpu = @_io.read_u1
      @pmem = @_io.read_u1
      @procs_starting = @_io.read_u2le
      @procs_stopping = @_io.read_u2le
      @pid_count = @_io.read_u2le
      self
    end

    ##
    # total system memory
    attr_reader :mem_total

    ##
    # percent of total cpu currently utilized
    attr_reader :pcpu

    ##
    # percent of total memory currently utilized
    attr_reader :pmem

    ##
    # number of processes that started during collection phase
    attr_reader :procs_starting

    ##
    # number of processes that stopped during collection phase
    attr_reader :procs_stopping

    ##
    # the count of processes on the system
    attr_reader :pid_count
  end

  ##
  # Summary of open file descriptors on the system.
  class MsgLinuxProcessFdSummary < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sys_fd_count = @_io.read_u4le
      @most_opened = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # count of total FDs open on the system
    attr_reader :sys_fd_count

    ##
    # A null delimited list of strings which alternates between a string
    # representation of the process count and the file name whose count it
    # being reported.  That is, in C string syntax
    # "32\0/var/log/syslog\012\0/tmp/foo\0" with the end of the list being
    # 2 NULL terminators in a row.
    attr_reader :most_opened
  end

  ##
  # This message indicates the process state of the top 10 heaviest
  # consumers of CPU on the system, including a timestamp.
  class MsgLinuxCpuState < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @index = @_io.read_u1
      @pid = @_io.read_u2le
      @pcpu = @_io.read_u1
      @time = @_io.read_u4le
      @flags = @_io.read_u1
      @tname = (@_io.read_bytes(15)).force_encoding("ascii")
      @cmdline = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # sequence of this status message, values from 0-9
    attr_reader :index

    ##
    # the PID of the process
    attr_reader :pid

    ##
    # percent of CPU used, expressed as a fraction of 256
    attr_reader :pcpu

    ##
    # timestamp of message, refer to flags field for how to interpret
    attr_reader :time

    ##
    # flags
    attr_reader :flags

    ##
    # fixed length string representing the thread name
    attr_reader :tname

    ##
    # the command line (as much as it fits in the remaining packet)
    attr_reader :cmdline
  end

  ##
  # Top 10 list of processes with high socket counts.
  class MsgLinuxProcessSocketCounts < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @index = @_io.read_u1
      @pid = @_io.read_u2le
      @socket_count = @_io.read_u2le
      @socket_types = @_io.read_u2le
      @socket_states = @_io.read_u2le
      @cmdline = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # sequence of this status message, values from 0-9
    attr_reader :index

    ##
    # the PID of the process in question
    attr_reader :pid

    ##
    # the number of sockets the process is using
    attr_reader :socket_count

    ##
    # A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
    # 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
    # (unknown)
    attr_reader :socket_types

    ##
    # A bitfield indicating the socket states: 0x1 (established), 0x2
    # (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
    # 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
    # ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
    # 0x8000 (unknown)
    attr_reader :socket_states

    ##
    # the command line of the process in question
    attr_reader :cmdline
  end
end
