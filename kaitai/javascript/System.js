// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.System = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var System = (function() {
  function System(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  System.prototype._read = function() {
  }

  /**
   * The heartbeat message is sent periodically to inform the host or other
   * attached devices that the system is running. It is used to monitor
   * system malfunctions. It also contains status flags that indicate to the
   * host the status of the system and whether it is operating correctly.
   * Currently, the expected heartbeat interval is 1 sec.
   * 
   * The system error flag is used to indicate that an error has occurred in
   * the system. To determine the source of the error, the remaining error
   * flags should be inspected.
   */

  var MsgHeartbeat = System.MsgHeartbeat = (function() {
    function MsgHeartbeat(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgHeartbeat.prototype._read = function() {
      this.flags = this._io.readU4le();
    }

    /**
     * Status flags
     */

    return MsgHeartbeat;
  })();

  /**
   * The status journal message contains past status reports (see
   * MSG_STATUS_REPORT) and functions as a error/event storage for telemetry
   * purposes.
   */

  var MsgStatusJournal = System.MsgStatusJournal = (function() {
    function MsgStatusJournal(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgStatusJournal.prototype._read = function() {
      this.reportingSystem = this._io.readU2le();
      this.sbpVersion = this._io.readU2le();
      this.totalStatusReports = this._io.readU4le();
      this.sequenceDescriptor = this._io.readU1();
      this.journal = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.journal.push(new StatusJournalItem(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Identity of reporting system
     */

    /**
     * SBP protocol version
     */

    /**
     * Total number of status reports sent since system startup
     */

    /**
     * Index and number of messages in this sequence. First nibble is the
     * size of the sequence (n), second nibble is the zero-indexed counter
     * (ith packet of n)
     */

    /**
     * Status journal
     */

    return MsgStatusJournal;
  })();

  /**
   * The INS status message describes the state of the operation and
   * initialization of the inertial navigation system.
   */

  var MsgInsStatus = System.MsgInsStatus = (function() {
    function MsgInsStatus(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgInsStatus.prototype._read = function() {
      this.flags = this._io.readU4le();
    }

    /**
     * Status flags
     */

    return MsgInsStatus;
  })();

  /**
   * The GNSS time offset message contains the information that is needed to
   * translate messages tagged with a local timestamp (e.g. IMU or wheeltick
   * messages) to GNSS time for the sender producing this message.
   */

  var MsgGnssTimeOffset = System.MsgGnssTimeOffset = (function() {
    function MsgGnssTimeOffset(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgGnssTimeOffset.prototype._read = function() {
      this.weeks = this._io.readS2le();
      this.milliseconds = this._io.readS4le();
      this.microseconds = this._io.readS2le();
      this.flags = this._io.readU1();
    }

    /**
     * Weeks portion of the time offset
     */

    /**
     * Milliseconds portion of the time offset
     */

    /**
     * Microseconds portion of the time offset
     */

    /**
     * Status flags (reserved)
     */

    return MsgGnssTimeOffset;
  })();

  /**
   * The CSAC telemetry message has an implementation defined telemetry
   * string from a device. It is not produced or available on general Swift
   * Products. It is intended to be a low rate message for status purposes.
   */

  var MsgCsacTelemetry = System.MsgCsacTelemetry = (function() {
    function MsgCsacTelemetry(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgCsacTelemetry.prototype._read = function() {
      this.id = this._io.readU1();
      this.telemetry = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * Index representing the type of telemetry in use.  It is
     * implementation defined.
     */

    /**
     * Comma separated list of values as defined by the index
     */

    return MsgCsacTelemetry;
  })();

  /**
   * The PPS time message contains the value of the sender's local time in
   * microseconds at the moment a pulse is detected on the PPS input. This is
   * to be used for syncronisation of sensor data sampled with a local
   * timestamp (e.g. IMU or wheeltick messages) where GNSS time is unknown to
   * the sender.
   * 
   * The local time used to timestamp the PPS pulse must be generated by the
   * same clock which is used to timestamp the IMU/wheel sensor data and
   * should follow the same roll-over rules.  A separate MSG_PPS_TIME message
   * should be sent for each source of sensor data which uses PPS-relative
   * timestamping.  The sender ID for each of these MSG_PPS_TIME messages
   * should match the sender ID of the respective sensor data.
   */

  var MsgPpsTime = System.MsgPpsTime = (function() {
    function MsgPpsTime(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgPpsTime.prototype._read = function() {
      this.time = this._io.readU8le();
      this.flags = this._io.readU1();
    }

    /**
     * Local time in microseconds
     */

    /**
     * Status flags
     */

    return MsgPpsTime;
  })();

  /**
   * The INS update status message contains information about executed and
   * rejected INS updates. This message is expected to be extended in the
   * future as new types of measurements are being added.
   */

  var MsgInsUpdates = System.MsgInsUpdates = (function() {
    function MsgInsUpdates(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgInsUpdates.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.gnsspos = this._io.readU1();
      this.gnssvel = this._io.readU1();
      this.wheelticks = this._io.readU1();
      this.speed = this._io.readU1();
      this.nhc = this._io.readU1();
      this.zerovel = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * GNSS position update status flags
     */

    /**
     * GNSS velocity update status flags
     */

    /**
     * Wheelticks update status flags
     */

    /**
     * Wheelticks update status flags
     */

    /**
     * NHC update status flags
     */

    /**
     * Zero velocity update status flags
     */

    return MsgInsUpdates;
  })();

  /**
   * This message provides information about the receipt of Differential
   * corrections.  It is expected to be sent with each receipt of a complete
   * corrections packet.
   */

  var MsgDgnssStatus = System.MsgDgnssStatus = (function() {
    function MsgDgnssStatus(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgDgnssStatus.prototype._read = function() {
      this.flags = this._io.readU1();
      this.latency = this._io.readU2le();
      this.numSignals = this._io.readU1();
      this.source = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * Status flags
     */

    /**
     * Latency of observation receipt
     */

    /**
     * Number of signals from base station
     */

    /**
     * Corrections source string
     */

    return MsgDgnssStatus;
  })();

  /**
   * The CSAC telemetry message provides labels for each member of the string
   * produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a
   * lower rate than the MSG_CSAC_TELEMETRY.
   */

  var MsgCsacTelemetryLabels = System.MsgCsacTelemetryLabels = (function() {
    function MsgCsacTelemetryLabels(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgCsacTelemetryLabels.prototype._read = function() {
      this.id = this._io.readU1();
      this.telemetryLabels = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * Index representing the type of telemetry in use.  It is
     * implementation defined.
     */

    /**
     * Comma separated list of telemetry field values
     */

    return MsgCsacTelemetryLabels;
  })();

  /**
   * The system start-up message is sent once on system start-up. It notifies
   * the host or other attached devices that the system has started and is
   * now ready to respond to commands or configuration requests.
   */

  var MsgStartup = System.MsgStartup = (function() {
    function MsgStartup(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgStartup.prototype._read = function() {
      this.cause = this._io.readU1();
      this.startupType = this._io.readU1();
      this.reserved = this._io.readU2le();
    }

    /**
     * Cause of startup
     */

    /**
     * Startup type
     */

    /**
     * Reserved
     */

    return MsgStartup;
  })();

  /**
   * This leading message lists the time metadata of the Solution Group. It
   * also lists the atomic contents (i.e. types of messages included) of the
   * Solution Group.
   */

  var MsgGroupMeta = System.MsgGroupMeta = (function() {
    function MsgGroupMeta(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgGroupMeta.prototype._read = function() {
      this.groupId = this._io.readU1();
      this.flags = this._io.readU1();
      this.nGroupMsgs = this._io.readU1();
      this.groupMsgs = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.groupMsgs.push(this._io.readU2le());
        i++;
      }
    }

    /**
     * Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss
     */

    /**
     * Status flags (reserved)
     */

    /**
     * Size of list group_msgs
     */

    /**
     * An in-order list of message types included in the Solution Group,
     * including GROUP_META itself
     */

    return MsgGroupMeta;
  })();

  /**
   * This diagnostic message contains state and update status information for
   * all sensors that are being used by the fusion engine. This message will
   * be generated asynchronously to the solution messages and will be emitted
   * anytime a sensor update is being processed.
   */

  var MsgSensorAidEvent = System.MsgSensorAidEvent = (function() {
    function MsgSensorAidEvent(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSensorAidEvent.prototype._read = function() {
      this.time = this._io.readU4le();
      this.sensorType = this._io.readU1();
      this.sensorId = this._io.readU2le();
      this.sensorState = this._io.readU1();
      this.nAvailableMeas = this._io.readU1();
      this.nAttemptedMeas = this._io.readU1();
      this.nAcceptedMeas = this._io.readU1();
      this.flags = this._io.readU4le();
    }

    /**
     * Update timestamp in milliseconds.
     */

    /**
     * Sensor type
     */

    /**
     * Sensor identifier
     */

    /**
     * Reserved for future use
     */

    /**
     * Number of available measurements in this epoch
     */

    /**
     * Number of attempted measurements in this epoch
     */

    /**
     * Number of accepted measurements in this epoch
     */

    /**
     * Reserved for future use
     */

    return MsgSensorAidEvent;
  })();

  /**
   * Report the general and specific state of a subsystem.  If the generic
   * state is reported as initializing, the specific state should be ignored.
   */

  var SubSystemReport = System.SubSystemReport = (function() {
    function SubSystemReport(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    SubSystemReport.prototype._read = function() {
      this.component = this._io.readU2le();
      this.generic = this._io.readU1();
      this.specific = this._io.readU1();
    }

    /**
     * Identity of reporting subsystem
     */

    /**
     * Generic form status report
     */

    /**
     * Subsystem specific status code
     */

    return SubSystemReport;
  })();

  /**
   * The status report is sent periodically to inform the host or other
   * attached devices that the system is running. It is used to monitor
   * system malfunctions. It contains status reports that indicate to the
   * host the status of each subsystem and whether it is operating correctly.
   * 
   * Interpretation of the subsystem specific status code is product
   * dependent, but if the generic status code is initializing, it should be
   * ignored.  Refer to product documentation for details.
   */

  var MsgStatusReport = System.MsgStatusReport = (function() {
    function MsgStatusReport(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgStatusReport.prototype._read = function() {
      this.reportingSystem = this._io.readU2le();
      this.sbpVersion = this._io.readU2le();
      this.sequence = this._io.readU4le();
      this.uptime = this._io.readU4le();
      this.status = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.status.push(new SubSystemReport(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Identity of reporting system
     */

    /**
     * SBP protocol version
     */

    /**
     * Increments on each status report sent
     */

    /**
     * Number of seconds since system start-up
     */

    /**
     * Reported status of individual subsystems
     */

    return MsgStatusReport;
  })();

  /**
   * Reports the uptime and the state of a subsystem via generic and specific
   * status codes.  If the generic state is reported as initializing, the
   * specific state should be ignored.
   */

  var StatusJournalItem = System.StatusJournalItem = (function() {
    function StatusJournalItem(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    StatusJournalItem.prototype._read = function() {
      this.uptime = this._io.readU4le();
      this.report = new SubSystemReport(this._io, this, this._root);
    }

    /**
     * Milliseconds since system startup
     */

    return StatusJournalItem;
  })();

  return System;
})();
return System;
}));
