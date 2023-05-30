// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Piksi = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Piksi = (function() {
  function Piksi(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Piksi.prototype._read = function() {
  }

  /**
   * The state of a network interface on the Piksi. Data is made to reflect
   * output of ifaddrs struct returned by getifaddrs in c.
   */

  var MsgNetworkStateResp = Piksi.MsgNetworkStateResp = (function() {
    function MsgNetworkStateResp(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgNetworkStateResp.prototype._read = function() {
      this.ipv4Address = [];
      for (var i = 0; i < 4; i++) {
        this.ipv4Address.push(this._io.readU1());
      }
      this.ipv4MaskSize = this._io.readU1();
      this.ipv6Address = [];
      for (var i = 0; i < 16; i++) {
        this.ipv6Address.push(this._io.readU1());
      }
      this.ipv6MaskSize = this._io.readU1();
      this.rxBytes = this._io.readU4le();
      this.txBytes = this._io.readU4le();
      this.interfaceName = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
      this.flags = this._io.readU4le();
    }

    /**
     * IPv4 address (all zero when unavailable)
     */

    /**
     * IPv4 netmask CIDR notation
     */

    /**
     * IPv6 address (all zero when unavailable)
     */

    /**
     * IPv6 netmask CIDR notation
     */

    /**
     * Number of Rx bytes
     */

    /**
     * Number of Tx bytes
     */

    /**
     * Interface Name
     */

    /**
     * Interface flags from SIOCGIFFLAGS
     */

    return MsgNetworkStateResp;
  })();

  /**
   * The bandwidth usage for each interface can be reported within this
   * struct and utilize multiple fields to fully specify the type of traffic
   * that is being tracked. As either the interval of collection or the
   * collection time may vary, both a timestamp and period field is provided,
   * though may not necessarily be populated with a value.
   */

  var NetworkUsage = Piksi.NetworkUsage = (function() {
    function NetworkUsage(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    NetworkUsage.prototype._read = function() {
      this.duration = this._io.readU8le();
      this.totalBytes = this._io.readU8le();
      this.rxBytes = this._io.readU4le();
      this.txBytes = this._io.readU4le();
      this.interfaceName = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * Duration over which the measurement was collected
     */

    /**
     * Number of bytes handled in total within period
     */

    /**
     * Number of bytes transmitted within period
     */

    /**
     * Number of bytes received within period
     */

    /**
     * Interface Name
     */

    return NetworkUsage;
  })();

  /**
   * The response to MSG_COMMAND_REQ with the return code of the command.  A
   * return code of zero indicates success.
   */

  var MsgCommandResp = Piksi.MsgCommandResp = (function() {
    function MsgCommandResp(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgCommandResp.prototype._read = function() {
      this.sequence = this._io.readU4le();
      this.code = this._io.readS4le();
    }

    /**
     * Sequence number
     */

    /**
     * Exit code
     */

    return MsgCommandResp;
  })();

  /**
   * Returns the standard output and standard error of the command requested
   * by MSG_COMMAND_REQ. The sequence number can be used to filter for
   * filtering the correct command.
   */

  var MsgCommandOutput = Piksi.MsgCommandOutput = (function() {
    function MsgCommandOutput(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgCommandOutput.prototype._read = function() {
      this.sequence = this._io.readU4le();
      this.line = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * Sequence number
     */

    /**
     * Line of standard output or standard error
     */

    return MsgCommandOutput;
  })();

  /**
   * Statistics on the latency of observations received from the base
   * station. As observation packets are received their GPS time is compared
   * to the current GPS time calculated locally by the receiver to give a
   * precise measurement of the end-to-end communication latency in the
   * system.
   */

  var Latency = Piksi.Latency = (function() {
    function Latency(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    Latency.prototype._read = function() {
      this.avg = this._io.readS4le();
      this.lmin = this._io.readS4le();
      this.lmax = this._io.readS4le();
      this.current = this._io.readS4le();
    }

    /**
     * Average latency
     */

    /**
     * Minimum latency
     */

    /**
     * Maximum latency
     */

    /**
     * Smoothed estimate of the current latency
     */

    return Latency;
  })();

  /**
   * The thread usage message from the device reports real-time operating
   * system (RTOS) thread usage statistics for the named thread. The reported
   * percentage values must be normalized.
   */

  var MsgThreadState = Piksi.MsgThreadState = (function() {
    function MsgThreadState(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgThreadState.prototype._read = function() {
      this.name = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
      this.cpu = this._io.readU2le();
      this.stackFree = this._io.readU4le();
    }

    /**
     * Thread name (NULL terminated)
     */

    /**
     * Percentage cpu use for this thread. Values range from 0 - 1000 and
     * needs to be renormalized to 100
     */

    /**
     * Free stack space for this thread
     */

    return MsgThreadState;
  })();

  /**
   * Deprecated
   */

  var MsgUartStateDepa = Piksi.MsgUartStateDepa = (function() {
    function MsgUartStateDepa(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgUartStateDepa.prototype._read = function() {
      this.uartA = new UartChannel(this._io, this, this._root);
      this.uartB = new UartChannel(this._io, this, this._root);
      this.uartFtdi = new UartChannel(this._io, this, this._root);
      this.latency = new Latency(this._io, this, this._root);
    }

    /**
     * State of UART A
     */

    /**
     * State of UART B
     */

    /**
     * State of UART FTDI (USB logger)
     */

    /**
     * UART communication latency
     */

    return MsgUartStateDepa;
  })();

  /**
   * Request state of Piksi network interfaces. Output will be sent in
   * MSG_NETWORK_STATE_RESP messages.
   */

  var MsgNetworkStateReq = Piksi.MsgNetworkStateReq = (function() {
    function MsgNetworkStateReq(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgNetworkStateReq.prototype._read = function() {
    }

    return MsgNetworkStateReq;
  })();

  /**
   * This message contains temperature and voltage level measurements from
   * the processor's monitoring system and the RF frontend die temperature if
   * available.
   */

  var MsgDeviceMonitor = Piksi.MsgDeviceMonitor = (function() {
    function MsgDeviceMonitor(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgDeviceMonitor.prototype._read = function() {
      this.devVin = this._io.readS2le();
      this.cpuVint = this._io.readS2le();
      this.cpuVaux = this._io.readS2le();
      this.cpuTemperature = this._io.readS2le();
      this.feTemperature = this._io.readS2le();
    }

    /**
     * Device V_in
     */

    /**
     * Processor V_int
     */

    /**
     * Processor V_aux
     */

    /**
     * Processor temperature
     */

    /**
     * Frontend temperature (if available)
     */

    return MsgDeviceMonitor;
  })();

  /**
   * Deprecated.
   */

  var MsgMaskSatelliteDep = Piksi.MsgMaskSatelliteDep = (function() {
    function MsgMaskSatelliteDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgMaskSatelliteDep.prototype._read = function() {
      this.mask = this._io.readU1();
      this.sid = new Gnss.GnssSignalDep(this._io, this, this._root);
    }

    /**
     * Mask of systems that should ignore this satellite.
     */

    /**
     * GNSS signal for which the mask is applied
     */

    return MsgMaskSatelliteDep;
  })();

  /**
   * The UART message reports data latency and throughput of the UART
   * channels providing SBP I/O. On the default Piksi configuration, UARTs A
   * and B are used for telemetry radios, but can also be host access ports
   * for embedded hosts, or other interfaces in future. The reported
   * percentage values must be normalized. Observations latency and period
   * can be used to assess the health of the differential corrections link.
   * Latency provides the timeliness of received base observations while the
   * period indicates their likelihood of transmission.
   */

  var MsgUartState = Piksi.MsgUartState = (function() {
    function MsgUartState(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgUartState.prototype._read = function() {
      this.uartA = new UartChannel(this._io, this, this._root);
      this.uartB = new UartChannel(this._io, this, this._root);
      this.uartFtdi = new UartChannel(this._io, this, this._root);
      this.latency = new Latency(this._io, this, this._root);
      this.obsPeriod = new Period(this._io, this, this._root);
    }

    /**
     * State of UART A
     */

    /**
     * State of UART B
     */

    /**
     * State of UART FTDI (USB logger)
     */

    /**
     * UART communication latency
     */

    /**
     * Observation receipt period
     */

    return MsgUartState;
  })();

  /**
   * Spectrum analyzer packet.
   */

  var MsgSpecan = Piksi.MsgSpecan = (function() {
    function MsgSpecan(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSpecan.prototype._read = function() {
      this.channelTag = this._io.readU2le();
      this.t = new Gnss.GpsTime(this._io, this, this._root);
      this.freqRef = this._io.readF4le();
      this.freqStep = this._io.readF4le();
      this.amplitudeRef = this._io.readF4le();
      this.amplitudeUnit = this._io.readF4le();
      this.amplitudeValue = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.amplitudeValue.push(this._io.readU1());
        i++;
      }
    }

    /**
     * Channel ID
     */

    /**
     * Receiver time of this observation
     */

    /**
     * Reference frequency of this packet
     */

    /**
     * Frequency step of points in this packet
     */

    /**
     * Reference amplitude of this packet
     */

    /**
     * Amplitude unit value of points in this packet
     */

    /**
     * Amplitude values (in the above units) of points in this packet
     */

    return MsgSpecan;
  })();

  /**
   * This message reports the state of the Integer Ambiguity Resolution (IAR)
   * process, which resolves unknown integer ambiguities from double-
   * differenced carrier-phase measurements from satellite observations.
   */

  var MsgIarState = Piksi.MsgIarState = (function() {
    function MsgIarState(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgIarState.prototype._read = function() {
      this.numHyps = this._io.readU4le();
    }

    /**
     * Number of integer ambiguity hypotheses remaining
     */

    return MsgIarState;
  })();

  /**
   * This is a legacy message for sending and loading a satellite alamanac
   * onto the Piksi's flash memory from the host.
   */

  var MsgAlmanac = Piksi.MsgAlmanac = (function() {
    function MsgAlmanac(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgAlmanac.prototype._read = function() {
    }

    return MsgAlmanac;
  })();

  /**
   * This message resets either the DGNSS Kalman filters or Integer Ambiguity
   * Resolution (IAR) process.
   */

  var MsgResetFilters = Piksi.MsgResetFilters = (function() {
    function MsgResetFilters(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgResetFilters.prototype._read = function() {
      this.filter = this._io.readU1();
    }

    /**
     * Filter flags
     */

    return MsgResetFilters;
  })();

  /**
   * Throughput, utilization, and error counts on the RX/TX buffers of this
   * UART channel. The reported percentage values must be normalized.
   */

  var UartChannel = Piksi.UartChannel = (function() {
    function UartChannel(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    UartChannel.prototype._read = function() {
      this.txThroughput = this._io.readF4le();
      this.rxThroughput = this._io.readF4le();
      this.crcErrorCount = this._io.readU2le();
      this.ioErrorCount = this._io.readU2le();
      this.txBufferLevel = this._io.readU1();
      this.rxBufferLevel = this._io.readU1();
    }

    /**
     * UART transmit throughput
     */

    /**
     * UART receive throughput
     */

    /**
     * UART CRC error count
     */

    /**
     * UART IO error count
     */

    /**
     * UART transmit buffer percentage utilization (ranges from 0 to 255)
     */

    /**
     * UART receive buffer percentage utilization (ranges from 0 to 255)
     */

    return UartChannel;
  })();

  /**
   * Request the recipient to execute an command. Output will be sent in
   * MSG_LOG messages, and the exit code will be returned with
   * MSG_COMMAND_RESP.
   */

  var MsgCommandReq = Piksi.MsgCommandReq = (function() {
    function MsgCommandReq(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgCommandReq.prototype._read = function() {
      this.sequence = this._io.readU4le();
      this.command = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * Sequence number
     */

    /**
     * Command line to execute
     */

    return MsgCommandReq;
  })();

  /**
   * This message allows setting a mask to prevent a particular satellite
   * from being used in various Piksi subsystems.
   */

  var MsgMaskSatellite = Piksi.MsgMaskSatellite = (function() {
    function MsgMaskSatellite(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgMaskSatellite.prototype._read = function() {
      this.mask = this._io.readU1();
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
    }

    /**
     * Mask of systems that should ignore this satellite.
     */

    /**
     * GNSS signal for which the mask is applied
     */

    return MsgMaskSatellite;
  })();

  /**
   * The bandwidth usage, a list of usage by interface.
   */

  var MsgNetworkBandwidthUsage = Piksi.MsgNetworkBandwidthUsage = (function() {
    function MsgNetworkBandwidthUsage(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgNetworkBandwidthUsage.prototype._read = function() {
      this.interfaces = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.interfaces.push(new NetworkUsage(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Usage measurement array
     */

    return MsgNetworkBandwidthUsage;
  })();

  /**
   * This message from the host resets the Piksi back into the bootloader.
   */

  var MsgReset = Piksi.MsgReset = (function() {
    function MsgReset(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgReset.prototype._read = function() {
      this.flags = this._io.readU4le();
    }

    /**
     * Reset flags
     */

    return MsgReset;
  })();

  /**
   * If a cell modem is present on a piksi device, this message will be send
   * periodically to update the host on the status of the modem and its
   * various parameters.
   */

  var MsgCellModemStatus = Piksi.MsgCellModemStatus = (function() {
    function MsgCellModemStatus(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgCellModemStatus.prototype._read = function() {
      this.signalStrength = this._io.readS1();
      this.signalErrorRate = this._io.readF4le();
      this.reserved = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.reserved.push(this._io.readU1());
        i++;
      }
    }

    /**
     * Received cell signal strength in dBm, zero translates to unknown
     */

    /**
     * BER as reported by the modem, zero translates to unknown
     */

    /**
     * Unspecified data TBD for this schema
     */

    return MsgCellModemStatus;
  })();

  /**
   * This message describes the gain of each channel in the receiver
   * frontend. Each gain is encoded as a non-dimensional percentage relative
   * to the maximum range possible for the gain stage of the frontend. By
   * convention, each gain array has 8 entries and the index of the array
   * corresponding to the index of the rf channel in the frontend. A gain of
   * 127 percent encodes that rf channel is not present in the hardware. A
   * negative value implies an error for the particular gain stage as
   * reported by the frontend.
   */

  var MsgFrontEndGain = Piksi.MsgFrontEndGain = (function() {
    function MsgFrontEndGain(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFrontEndGain.prototype._read = function() {
      this.rfGain = [];
      for (var i = 0; i < 8; i++) {
        this.rfGain.push(this._io.readS1());
      }
      this.ifGain = [];
      for (var i = 0; i < 8; i++) {
        this.ifGain.push(this._io.readS1());
      }
    }

    /**
     * RF gain for each frontend channel
     */

    /**
     * Intermediate frequency gain for each frontend channel
     */

    return MsgFrontEndGain;
  })();

  /**
   * This message from the host resets the Piksi back into the bootloader.
   */

  var MsgResetDep = Piksi.MsgResetDep = (function() {
    function MsgResetDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgResetDep.prototype._read = function() {
    }

    return MsgResetDep;
  })();

  /**
   * This message sets up timing functionality using a coarse GPS time
   * estimate sent by the host.
   */

  var MsgSetTime = Piksi.MsgSetTime = (function() {
    function MsgSetTime(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSetTime.prototype._read = function() {
    }

    return MsgSetTime;
  })();

  /**
   * This is an unused legacy message for result reporting from the CW
   * interference channel on the SwiftNAP. This message will be removed in a
   * future release.
   */

  var MsgCwResults = Piksi.MsgCwResults = (function() {
    function MsgCwResults(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgCwResults.prototype._read = function() {
    }

    return MsgCwResults;
  })();

  /**
   * Deprecated.
   */

  var MsgSpecanDep = Piksi.MsgSpecanDep = (function() {
    function MsgSpecanDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSpecanDep.prototype._read = function() {
      this.channelTag = this._io.readU2le();
      this.t = new Gnss.GpsTimeDep(this._io, this, this._root);
      this.freqRef = this._io.readF4le();
      this.freqStep = this._io.readF4le();
      this.amplitudeRef = this._io.readF4le();
      this.amplitudeUnit = this._io.readF4le();
      this.amplitudeValue = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.amplitudeValue.push(this._io.readU1());
        i++;
      }
    }

    /**
     * Channel ID
     */

    /**
     * Receiver time of this observation
     */

    /**
     * Reference frequency of this packet
     */

    /**
     * Frequency step of points in this packet
     */

    /**
     * Reference amplitude of this packet
     */

    /**
     * Amplitude unit value of points in this packet
     */

    /**
     * Amplitude values (in the above units) of points in this packet
     */

    return MsgSpecanDep;
  })();

  /**
   * Deprecated
   */

  var MsgInitBaseDep = Piksi.MsgInitBaseDep = (function() {
    function MsgInitBaseDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgInitBaseDep.prototype._read = function() {
    }

    return MsgInitBaseDep;
  })();

  /**
   * Statistics on the period of observations received from the base station.
   * As complete observation sets are received, their time of reception is
   * compared with the prior set''s time of reception. This measurement
   * provides a proxy for link quality as incomplete or missing sets will
   * increase the period.  Long periods can cause momentary RTK solution
   * outages.
   */

  var Period = Piksi.Period = (function() {
    function Period(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    Period.prototype._read = function() {
      this.avg = this._io.readS4le();
      this.pmin = this._io.readS4le();
      this.pmax = this._io.readS4le();
      this.current = this._io.readS4le();
    }

    /**
     * Average period
     */

    /**
     * Minimum period
     */

    /**
     * Maximum period
     */

    /**
     * Smoothed estimate of the current period
     */

    return Period;
  })();

  /**
   * This is an unused legacy message from the host for starting the CW
   * interference channel on the SwiftNAP. This message will be removed in a
   * future release.
   */

  var MsgCwStart = Piksi.MsgCwStart = (function() {
    function MsgCwStart(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgCwStart.prototype._read = function() {
    }

    return MsgCwStart;
  })();

  return Piksi;
})();
return Piksi;
}));
