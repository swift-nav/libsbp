// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.util.ArrayList;
import java.nio.charset.Charset;

public class System extends KaitaiStruct {
    public static System fromFile(String fileName) throws IOException {
        return new System(new ByteBufferKaitaiStream(fileName));
    }

    public System(KaitaiStream _io) {
        this(_io, null, null);
    }

    public System(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public System(KaitaiStream _io, KaitaiStruct _parent, System _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
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
    public static class MsgHeartbeat extends KaitaiStruct {
        public static MsgHeartbeat fromFile(String fileName) throws IOException {
            return new MsgHeartbeat(new ByteBufferKaitaiStream(fileName));
        }

        public MsgHeartbeat(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgHeartbeat(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgHeartbeat(KaitaiStream _io, Sbp.Message _parent, System _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.flags = this._io.readU4le();
        }
        private long flags;
        private System _root;
        private Sbp.Message _parent;

        /**
         * Status flags
         */
        public long flags() { return flags; }
        public System _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The status journal message contains past status reports (see
     * MSG_STATUS_REPORT) and functions as a error/event storage for telemetry
     * purposes.
     */
    public static class MsgStatusJournal extends KaitaiStruct {
        public static MsgStatusJournal fromFile(String fileName) throws IOException {
            return new MsgStatusJournal(new ByteBufferKaitaiStream(fileName));
        }

        public MsgStatusJournal(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgStatusJournal(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgStatusJournal(KaitaiStream _io, Sbp.Message _parent, System _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.reportingSystem = this._io.readU2le();
            this.sbpVersion = this._io.readU2le();
            this.totalStatusReports = this._io.readU4le();
            this.sequenceDescriptor = this._io.readU1();
            this.journal = new ArrayList<StatusJournalItem>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.journal.add(new StatusJournalItem(this._io, this, _root));
                    i++;
                }
            }
        }
        private int reportingSystem;
        private int sbpVersion;
        private long totalStatusReports;
        private int sequenceDescriptor;
        private ArrayList<StatusJournalItem> journal;
        private System _root;
        private Sbp.Message _parent;

        /**
         * Identity of reporting system
         */
        public int reportingSystem() { return reportingSystem; }

        /**
         * SBP protocol version
         */
        public int sbpVersion() { return sbpVersion; }

        /**
         * Total number of status reports sent since system startup
         */
        public long totalStatusReports() { return totalStatusReports; }

        /**
         * Index and number of messages in this sequence. First nibble is the
         * size of the sequence (n), second nibble is the zero-indexed counter
         * (ith packet of n)
         */
        public int sequenceDescriptor() { return sequenceDescriptor; }

        /**
         * Status journal
         */
        public ArrayList<StatusJournalItem> journal() { return journal; }
        public System _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The INS status message describes the state of the operation and
     * initialization of the inertial navigation system.
     */
    public static class MsgInsStatus extends KaitaiStruct {
        public static MsgInsStatus fromFile(String fileName) throws IOException {
            return new MsgInsStatus(new ByteBufferKaitaiStream(fileName));
        }

        public MsgInsStatus(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgInsStatus(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgInsStatus(KaitaiStream _io, Sbp.Message _parent, System _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.flags = this._io.readU4le();
        }
        private long flags;
        private System _root;
        private Sbp.Message _parent;

        /**
         * Status flags
         */
        public long flags() { return flags; }
        public System _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The GNSS time offset message contains the information that is needed to
     * translate messages tagged with a local timestamp (e.g. IMU or wheeltick
     * messages) to GNSS time for the sender producing this message.
     */
    public static class MsgGnssTimeOffset extends KaitaiStruct {
        public static MsgGnssTimeOffset fromFile(String fileName) throws IOException {
            return new MsgGnssTimeOffset(new ByteBufferKaitaiStream(fileName));
        }

        public MsgGnssTimeOffset(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgGnssTimeOffset(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgGnssTimeOffset(KaitaiStream _io, Sbp.Message _parent, System _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.weeks = this._io.readS2le();
            this.milliseconds = this._io.readS4le();
            this.microseconds = this._io.readS2le();
            this.flags = this._io.readU1();
        }
        private short weeks;
        private int milliseconds;
        private short microseconds;
        private int flags;
        private System _root;
        private Sbp.Message _parent;

        /**
         * Weeks portion of the time offset
         */
        public short weeks() { return weeks; }

        /**
         * Milliseconds portion of the time offset
         */
        public int milliseconds() { return milliseconds; }

        /**
         * Microseconds portion of the time offset
         */
        public short microseconds() { return microseconds; }

        /**
         * Status flags (reserved)
         */
        public int flags() { return flags; }
        public System _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The CSAC telemetry message has an implementation defined telemetry
     * string from a device. It is not produced or available on general Swift
     * Products. It is intended to be a low rate message for status purposes.
     */
    public static class MsgCsacTelemetry extends KaitaiStruct {
        public static MsgCsacTelemetry fromFile(String fileName) throws IOException {
            return new MsgCsacTelemetry(new ByteBufferKaitaiStream(fileName));
        }

        public MsgCsacTelemetry(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgCsacTelemetry(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgCsacTelemetry(KaitaiStream _io, Sbp.Message _parent, System _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.id = this._io.readU1();
            this.telemetry = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private int id;
        private String telemetry;
        private System _root;
        private Sbp.Message _parent;

        /**
         * Index representing the type of telemetry in use.  It is
         * implementation defined.
         */
        public int id() { return id; }

        /**
         * Comma separated list of values as defined by the index
         */
        public String telemetry() { return telemetry; }
        public System _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

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
    public static class MsgPpsTime extends KaitaiStruct {
        public static MsgPpsTime fromFile(String fileName) throws IOException {
            return new MsgPpsTime(new ByteBufferKaitaiStream(fileName));
        }

        public MsgPpsTime(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgPpsTime(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgPpsTime(KaitaiStream _io, Sbp.Message _parent, System _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.time = this._io.readU8le();
            this.flags = this._io.readU1();
        }
        private long time;
        private int flags;
        private System _root;
        private Sbp.Message _parent;

        /**
         * Local time in microseconds
         */
        public long time() { return time; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public System _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The INS update status message contains information about executed and
     * rejected INS updates. This message is expected to be extended in the
     * future as new types of measurements are being added.
     */
    public static class MsgInsUpdates extends KaitaiStruct {
        public static MsgInsUpdates fromFile(String fileName) throws IOException {
            return new MsgInsUpdates(new ByteBufferKaitaiStream(fileName));
        }

        public MsgInsUpdates(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgInsUpdates(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgInsUpdates(KaitaiStream _io, Sbp.Message _parent, System _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.gnsspos = this._io.readU1();
            this.gnssvel = this._io.readU1();
            this.wheelticks = this._io.readU1();
            this.speed = this._io.readU1();
            this.nhc = this._io.readU1();
            this.zerovel = this._io.readU1();
        }
        private long tow;
        private int gnsspos;
        private int gnssvel;
        private int wheelticks;
        private int speed;
        private int nhc;
        private int zerovel;
        private System _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * GNSS position update status flags
         */
        public int gnsspos() { return gnsspos; }

        /**
         * GNSS velocity update status flags
         */
        public int gnssvel() { return gnssvel; }

        /**
         * Wheelticks update status flags
         */
        public int wheelticks() { return wheelticks; }

        /**
         * Wheelticks update status flags
         */
        public int speed() { return speed; }

        /**
         * NHC update status flags
         */
        public int nhc() { return nhc; }

        /**
         * Zero velocity update status flags
         */
        public int zerovel() { return zerovel; }
        public System _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message provides information about the receipt of Differential
     * corrections.  It is expected to be sent with each receipt of a complete
     * corrections packet.
     */
    public static class MsgDgnssStatus extends KaitaiStruct {
        public static MsgDgnssStatus fromFile(String fileName) throws IOException {
            return new MsgDgnssStatus(new ByteBufferKaitaiStream(fileName));
        }

        public MsgDgnssStatus(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgDgnssStatus(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgDgnssStatus(KaitaiStream _io, Sbp.Message _parent, System _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.flags = this._io.readU1();
            this.latency = this._io.readU2le();
            this.numSignals = this._io.readU1();
            this.source = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private int flags;
        private int latency;
        private int numSignals;
        private String source;
        private System _root;
        private Sbp.Message _parent;

        /**
         * Status flags
         */
        public int flags() { return flags; }

        /**
         * Latency of observation receipt
         */
        public int latency() { return latency; }

        /**
         * Number of signals from base station
         */
        public int numSignals() { return numSignals; }

        /**
         * Corrections source string
         */
        public String source() { return source; }
        public System _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The CSAC telemetry message provides labels for each member of the string
     * produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a
     * lower rate than the MSG_CSAC_TELEMETRY.
     */
    public static class MsgCsacTelemetryLabels extends KaitaiStruct {
        public static MsgCsacTelemetryLabels fromFile(String fileName) throws IOException {
            return new MsgCsacTelemetryLabels(new ByteBufferKaitaiStream(fileName));
        }

        public MsgCsacTelemetryLabels(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgCsacTelemetryLabels(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgCsacTelemetryLabels(KaitaiStream _io, Sbp.Message _parent, System _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.id = this._io.readU1();
            this.telemetryLabels = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private int id;
        private String telemetryLabels;
        private System _root;
        private Sbp.Message _parent;

        /**
         * Index representing the type of telemetry in use.  It is
         * implementation defined.
         */
        public int id() { return id; }

        /**
         * Comma separated list of telemetry field values
         */
        public String telemetryLabels() { return telemetryLabels; }
        public System _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The system start-up message is sent once on system start-up. It notifies
     * the host or other attached devices that the system has started and is
     * now ready to respond to commands or configuration requests.
     */
    public static class MsgStartup extends KaitaiStruct {
        public static MsgStartup fromFile(String fileName) throws IOException {
            return new MsgStartup(new ByteBufferKaitaiStream(fileName));
        }

        public MsgStartup(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgStartup(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgStartup(KaitaiStream _io, Sbp.Message _parent, System _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.cause = this._io.readU1();
            this.startupType = this._io.readU1();
            this.reserved = this._io.readU2le();
        }
        private int cause;
        private int startupType;
        private int reserved;
        private System _root;
        private Sbp.Message _parent;

        /**
         * Cause of startup
         */
        public int cause() { return cause; }

        /**
         * Startup type
         */
        public int startupType() { return startupType; }

        /**
         * Reserved
         */
        public int reserved() { return reserved; }
        public System _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This leading message lists the time metadata of the Solution Group. It
     * also lists the atomic contents (i.e. types of messages included) of the
     * Solution Group.
     */
    public static class MsgGroupMeta extends KaitaiStruct {
        public static MsgGroupMeta fromFile(String fileName) throws IOException {
            return new MsgGroupMeta(new ByteBufferKaitaiStream(fileName));
        }

        public MsgGroupMeta(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgGroupMeta(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgGroupMeta(KaitaiStream _io, Sbp.Message _parent, System _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.groupId = this._io.readU1();
            this.flags = this._io.readU1();
            this.nGroupMsgs = this._io.readU1();
            this.groupMsgs = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.groupMsgs.add(this._io.readU2le());
                    i++;
                }
            }
        }
        private int groupId;
        private int flags;
        private int nGroupMsgs;
        private ArrayList<Integer> groupMsgs;
        private System _root;
        private Sbp.Message _parent;

        /**
         * Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss
         */
        public int groupId() { return groupId; }

        /**
         * Status flags (reserved)
         */
        public int flags() { return flags; }

        /**
         * Size of list group_msgs
         */
        public int nGroupMsgs() { return nGroupMsgs; }

        /**
         * An in-order list of message types included in the Solution Group,
         * including GROUP_META itself
         */
        public ArrayList<Integer> groupMsgs() { return groupMsgs; }
        public System _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This diagnostic message contains state and update status information for
     * all sensors that are being used by the fusion engine. This message will
     * be generated asynchronously to the solution messages and will be emitted
     * anytime a sensor update is being processed.
     */
    public static class MsgSensorAidEvent extends KaitaiStruct {
        public static MsgSensorAidEvent fromFile(String fileName) throws IOException {
            return new MsgSensorAidEvent(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSensorAidEvent(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSensorAidEvent(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSensorAidEvent(KaitaiStream _io, Sbp.Message _parent, System _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.time = this._io.readU4le();
            this.sensorType = this._io.readU1();
            this.sensorId = this._io.readU2le();
            this.sensorState = this._io.readU1();
            this.nAvailableMeas = this._io.readU1();
            this.nAttemptedMeas = this._io.readU1();
            this.nAcceptedMeas = this._io.readU1();
            this.flags = this._io.readU4le();
        }
        private long time;
        private int sensorType;
        private int sensorId;
        private int sensorState;
        private int nAvailableMeas;
        private int nAttemptedMeas;
        private int nAcceptedMeas;
        private long flags;
        private System _root;
        private Sbp.Message _parent;

        /**
         * Update timestamp in milliseconds.
         */
        public long time() { return time; }

        /**
         * Sensor type
         */
        public int sensorType() { return sensorType; }

        /**
         * Sensor identifier
         */
        public int sensorId() { return sensorId; }

        /**
         * Reserved for future use
         */
        public int sensorState() { return sensorState; }

        /**
         * Number of available measurements in this epoch
         */
        public int nAvailableMeas() { return nAvailableMeas; }

        /**
         * Number of attempted measurements in this epoch
         */
        public int nAttemptedMeas() { return nAttemptedMeas; }

        /**
         * Number of accepted measurements in this epoch
         */
        public int nAcceptedMeas() { return nAcceptedMeas; }

        /**
         * Reserved for future use
         */
        public long flags() { return flags; }
        public System _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Report the general and specific state of a subsystem.  If the generic
     * state is reported as initializing, the specific state should be ignored.
     */
    public static class SubSystemReport extends KaitaiStruct {
        public static SubSystemReport fromFile(String fileName) throws IOException {
            return new SubSystemReport(new ByteBufferKaitaiStream(fileName));
        }

        public SubSystemReport(KaitaiStream _io) {
            this(_io, null, null);
        }

        public SubSystemReport(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public SubSystemReport(KaitaiStream _io, KaitaiStruct _parent, System _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.component = this._io.readU2le();
            this.generic = this._io.readU1();
            this.specific = this._io.readU1();
        }
        private int component;
        private int generic;
        private int specific;
        private System _root;
        private KaitaiStruct _parent;

        /**
         * Identity of reporting subsystem
         */
        public int component() { return component; }

        /**
         * Generic form status report
         */
        public int generic() { return generic; }

        /**
         * Subsystem specific status code
         */
        public int specific() { return specific; }
        public System _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

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
    public static class MsgStatusReport extends KaitaiStruct {
        public static MsgStatusReport fromFile(String fileName) throws IOException {
            return new MsgStatusReport(new ByteBufferKaitaiStream(fileName));
        }

        public MsgStatusReport(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgStatusReport(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgStatusReport(KaitaiStream _io, Sbp.Message _parent, System _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.reportingSystem = this._io.readU2le();
            this.sbpVersion = this._io.readU2le();
            this.sequence = this._io.readU4le();
            this.uptime = this._io.readU4le();
            this.status = new ArrayList<SubSystemReport>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.status.add(new SubSystemReport(this._io, this, _root));
                    i++;
                }
            }
        }
        private int reportingSystem;
        private int sbpVersion;
        private long sequence;
        private long uptime;
        private ArrayList<SubSystemReport> status;
        private System _root;
        private Sbp.Message _parent;

        /**
         * Identity of reporting system
         */
        public int reportingSystem() { return reportingSystem; }

        /**
         * SBP protocol version
         */
        public int sbpVersion() { return sbpVersion; }

        /**
         * Increments on each status report sent
         */
        public long sequence() { return sequence; }

        /**
         * Number of seconds since system start-up
         */
        public long uptime() { return uptime; }

        /**
         * Reported status of individual subsystems
         */
        public ArrayList<SubSystemReport> status() { return status; }
        public System _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Reports the uptime and the state of a subsystem via generic and specific
     * status codes.  If the generic state is reported as initializing, the
     * specific state should be ignored.
     */
    public static class StatusJournalItem extends KaitaiStruct {
        public static StatusJournalItem fromFile(String fileName) throws IOException {
            return new StatusJournalItem(new ByteBufferKaitaiStream(fileName));
        }

        public StatusJournalItem(KaitaiStream _io) {
            this(_io, null, null);
        }

        public StatusJournalItem(KaitaiStream _io, System.MsgStatusJournal _parent) {
            this(_io, _parent, null);
        }

        public StatusJournalItem(KaitaiStream _io, System.MsgStatusJournal _parent, System _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.uptime = this._io.readU4le();
            this.report = new SubSystemReport(this._io, this, _root);
        }
        private long uptime;
        private SubSystemReport report;
        private System _root;
        private System.MsgStatusJournal _parent;

        /**
         * Milliseconds since system startup
         */
        public long uptime() { return uptime; }
        public SubSystemReport report() { return report; }
        public System _root() { return _root; }
        public System.MsgStatusJournal _parent() { return _parent; }
    }
    private System _root;
    private KaitaiStruct _parent;
    public System _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
