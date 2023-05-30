// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Linux = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Linux = (function() {
  function Linux(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Linux.prototype._read = function() {
  }

  /**
   * Summaries the socket usage across the system.
   */

  var MsgLinuxSocketUsage = Linux.MsgLinuxSocketUsage = (function() {
    function MsgLinuxSocketUsage(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgLinuxSocketUsage.prototype._read = function() {
      this.avgQueueDepth = this._io.readU4le();
      this.maxQueueDepth = this._io.readU4le();
      this.socketStateCounts = [];
      for (var i = 0; i < 16; i++) {
        this.socketStateCounts.push(this._io.readU2le());
      }
      this.socketTypeCounts = [];
      for (var i = 0; i < 16; i++) {
        this.socketTypeCounts.push(this._io.readU2le());
      }
    }

    /**
     * average socket queue depths across all sockets on the system
     */

    /**
     * the max queue depth seen within the reporting period
     */

    /**
     * A count for each socket type reported in the `socket_types_reported`
     * field, the first entry corresponds to the first enabled bit in
     * `types_reported`.
     */

    /**
     * A count for each socket type reported in the `socket_types_reported`
     * field, the first entry corresponds to the first enabled bit in
     * `types_reported`.
     */

    return MsgLinuxSocketUsage;
  })();

  /**
   * This presents a summary of CPU and memory utilization, including a
   * timestamp.
   */

  var MsgLinuxSysState = Linux.MsgLinuxSysState = (function() {
    function MsgLinuxSysState(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgLinuxSysState.prototype._read = function() {
      this.memTotal = this._io.readU2le();
      this.pcpu = this._io.readU1();
      this.pmem = this._io.readU1();
      this.procsStarting = this._io.readU2le();
      this.procsStopping = this._io.readU2le();
      this.pidCount = this._io.readU2le();
      this.time = this._io.readU4le();
      this.flags = this._io.readU1();
    }

    /**
     * total system memory, in MiB
     */

    /**
     * percent of CPU used, expressed as a fraction of 256
     */

    /**
     * percent of memory used, expressed as a fraction of 256
     */

    /**
     * number of processes that started during collection phase
     */

    /**
     * number of processes that stopped during collection phase
     */

    /**
     * the count of processes on the system
     */

    /**
     * timestamp of message, refer to flags field for how to interpret
     */

    /**
     * flags
     */

    return MsgLinuxSysState;
  })();

  /**
   * This message indicates the process state of the top 10 heaviest
   * consumers of CPU on the system.
   */

  var MsgLinuxCpuStateDepA = Linux.MsgLinuxCpuStateDepA = (function() {
    function MsgLinuxCpuStateDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgLinuxCpuStateDepA.prototype._read = function() {
      this.index = this._io.readU1();
      this.pid = this._io.readU2le();
      this.pcpu = this._io.readU1();
      this.tname = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
      this.cmdline = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * sequence of this status message, values from 0-9
     */

    /**
     * the PID of the process
     */

    /**
     * percent of cpu used, expressed as a fraction of 256
     */

    /**
     * fixed length string representing the thread name
     */

    /**
     * the command line (as much as it fits in the remaining packet)
     */

    return MsgLinuxCpuStateDepA;
  })();

  /**
   * This message indicates the process state of the top 10 heaviest
   * consumers of memory on the system, including a timestamp.
   */

  var MsgLinuxMemState = Linux.MsgLinuxMemState = (function() {
    function MsgLinuxMemState(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgLinuxMemState.prototype._read = function() {
      this.index = this._io.readU1();
      this.pid = this._io.readU2le();
      this.pmem = this._io.readU1();
      this.time = this._io.readU4le();
      this.flags = this._io.readU1();
      this.tname = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
      this.cmdline = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * sequence of this status message, values from 0-9
     */

    /**
     * the PID of the process
     */

    /**
     * percent of memory used, expressed as a fraction of 256
     */

    /**
     * timestamp of message, refer to flags field for how to interpret
     */

    /**
     * flags
     */

    /**
     * fixed length string representing the thread name
     */

    /**
     * the command line (as much as it fits in the remaining packet)
     */

    return MsgLinuxMemState;
  })();

  /**
   * Top 10 list of processes with a large number of open file descriptors.
   */

  var MsgLinuxProcessFdCount = Linux.MsgLinuxProcessFdCount = (function() {
    function MsgLinuxProcessFdCount(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgLinuxProcessFdCount.prototype._read = function() {
      this.index = this._io.readU1();
      this.pid = this._io.readU2le();
      this.fdCount = this._io.readU2le();
      this.cmdline = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * sequence of this status message, values from 0-9
     */

    /**
     * the PID of the process in question
     */

    /**
     * a count of the number of file descriptors opened by the process
     */

    /**
     * the command line of the process in question
     */

    return MsgLinuxProcessFdCount;
  })();

  /**
   * This message indicates the process state of the top 10 heaviest
   * consumers of memory on the system.
   */

  var MsgLinuxMemStateDepA = Linux.MsgLinuxMemStateDepA = (function() {
    function MsgLinuxMemStateDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgLinuxMemStateDepA.prototype._read = function() {
      this.index = this._io.readU1();
      this.pid = this._io.readU2le();
      this.pmem = this._io.readU1();
      this.tname = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
      this.cmdline = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * sequence of this status message, values from 0-9
     */

    /**
     * the PID of the process
     */

    /**
     * percent of memory used, expressed as a fraction of 256
     */

    /**
     * fixed length string representing the thread name
     */

    /**
     * the command line (as much as it fits in the remaining packet)
     */

    return MsgLinuxMemStateDepA;
  })();

  /**
   * Top 10 list of sockets with deep queues.
   */

  var MsgLinuxProcessSocketQueues = Linux.MsgLinuxProcessSocketQueues = (function() {
    function MsgLinuxProcessSocketQueues(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgLinuxProcessSocketQueues.prototype._read = function() {
      this.index = this._io.readU1();
      this.pid = this._io.readU2le();
      this.recvQueued = this._io.readU2le();
      this.sendQueued = this._io.readU2le();
      this.socketTypes = this._io.readU2le();
      this.socketStates = this._io.readU2le();
      this.addressOfLargest = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
      this.cmdline = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * sequence of this status message, values from 0-9
     */

    /**
     * the PID of the process in question
     */

    /**
     * the total amount of receive data queued for this process
     */

    /**
     * the total amount of send data queued for this process
     */

    /**
     * A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
     * 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
     * (unknown)
     */

    /**
     * A bitfield indicating the socket states: 0x1 (established), 0x2
     * (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
     * 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
     * ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
     * 0x8000 (unknown)
     */

    /**
     * Address of the largest queue, remote or local depending on the
     * directionality of the connection.
     */

    /**
     * the command line of the process in question
     */

    return MsgLinuxProcessSocketQueues;
  })();

  /**
   * This presents a summary of CPU and memory utilization.
   */

  var MsgLinuxSysStateDepA = Linux.MsgLinuxSysStateDepA = (function() {
    function MsgLinuxSysStateDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgLinuxSysStateDepA.prototype._read = function() {
      this.memTotal = this._io.readU2le();
      this.pcpu = this._io.readU1();
      this.pmem = this._io.readU1();
      this.procsStarting = this._io.readU2le();
      this.procsStopping = this._io.readU2le();
      this.pidCount = this._io.readU2le();
    }

    /**
     * total system memory
     */

    /**
     * percent of total cpu currently utilized
     */

    /**
     * percent of total memory currently utilized
     */

    /**
     * number of processes that started during collection phase
     */

    /**
     * number of processes that stopped during collection phase
     */

    /**
     * the count of processes on the system
     */

    return MsgLinuxSysStateDepA;
  })();

  /**
   * Summary of open file descriptors on the system.
   */

  var MsgLinuxProcessFdSummary = Linux.MsgLinuxProcessFdSummary = (function() {
    function MsgLinuxProcessFdSummary(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgLinuxProcessFdSummary.prototype._read = function() {
      this.sysFdCount = this._io.readU4le();
      this.mostOpened = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * count of total FDs open on the system
     */

    /**
     * A null delimited list of strings which alternates between a string
     * representation of the process count and the file name whose count it
     * being reported.  That is, in C string syntax
     * "32\0/var/log/syslog\012\0/tmp/foo\0" with the end of the list being
     * 2 NULL terminators in a row.
     */

    return MsgLinuxProcessFdSummary;
  })();

  /**
   * This message indicates the process state of the top 10 heaviest
   * consumers of CPU on the system, including a timestamp.
   */

  var MsgLinuxCpuState = Linux.MsgLinuxCpuState = (function() {
    function MsgLinuxCpuState(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgLinuxCpuState.prototype._read = function() {
      this.index = this._io.readU1();
      this.pid = this._io.readU2le();
      this.pcpu = this._io.readU1();
      this.time = this._io.readU4le();
      this.flags = this._io.readU1();
      this.tname = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
      this.cmdline = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * sequence of this status message, values from 0-9
     */

    /**
     * the PID of the process
     */

    /**
     * percent of CPU used, expressed as a fraction of 256
     */

    /**
     * timestamp of message, refer to flags field for how to interpret
     */

    /**
     * flags
     */

    /**
     * fixed length string representing the thread name
     */

    /**
     * the command line (as much as it fits in the remaining packet)
     */

    return MsgLinuxCpuState;
  })();

  /**
   * Top 10 list of processes with high socket counts.
   */

  var MsgLinuxProcessSocketCounts = Linux.MsgLinuxProcessSocketCounts = (function() {
    function MsgLinuxProcessSocketCounts(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgLinuxProcessSocketCounts.prototype._read = function() {
      this.index = this._io.readU1();
      this.pid = this._io.readU2le();
      this.socketCount = this._io.readU2le();
      this.socketTypes = this._io.readU2le();
      this.socketStates = this._io.readU2le();
      this.cmdline = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * sequence of this status message, values from 0-9
     */

    /**
     * the PID of the process in question
     */

    /**
     * the number of sockets the process is using
     */

    /**
     * A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
     * 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
     * (unknown)
     */

    /**
     * A bitfield indicating the socket states: 0x1 (established), 0x2
     * (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
     * 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
     * ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
     * 0x8000 (unknown)
     */

    /**
     * the command line of the process in question
     */

    return MsgLinuxProcessSocketCounts;
  })();

  return Linux;
})();
return Linux;
}));
