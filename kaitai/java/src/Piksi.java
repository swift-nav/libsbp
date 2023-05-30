// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.util.ArrayList;
import java.nio.charset.Charset;

public class Piksi extends KaitaiStruct {
    public static Piksi fromFile(String fileName) throws IOException {
        return new Piksi(new ByteBufferKaitaiStream(fileName));
    }

    public Piksi(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Piksi(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Piksi(KaitaiStream _io, KaitaiStruct _parent, Piksi _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * The state of a network interface on the Piksi. Data is made to reflect
     * output of ifaddrs struct returned by getifaddrs in c.
     */
    public static class MsgNetworkStateResp extends KaitaiStruct {
        public static MsgNetworkStateResp fromFile(String fileName) throws IOException {
            return new MsgNetworkStateResp(new ByteBufferKaitaiStream(fileName));
        }

        public MsgNetworkStateResp(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgNetworkStateResp(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgNetworkStateResp(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.ipv4Address = new ArrayList<Integer>();
            for (int i = 0; i < 4; i++) {
                this.ipv4Address.add(this._io.readU1());
            }
            this.ipv4MaskSize = this._io.readU1();
            this.ipv6Address = new ArrayList<Integer>();
            for (int i = 0; i < 16; i++) {
                this.ipv6Address.add(this._io.readU1());
            }
            this.ipv6MaskSize = this._io.readU1();
            this.rxBytes = this._io.readU4le();
            this.txBytes = this._io.readU4le();
            this.interfaceName = new String(this._io.readBytesFull(), Charset.forName("ascii"));
            this.flags = this._io.readU4le();
        }
        private ArrayList<Integer> ipv4Address;
        private int ipv4MaskSize;
        private ArrayList<Integer> ipv6Address;
        private int ipv6MaskSize;
        private long rxBytes;
        private long txBytes;
        private String interfaceName;
        private long flags;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * IPv4 address (all zero when unavailable)
         */
        public ArrayList<Integer> ipv4Address() { return ipv4Address; }

        /**
         * IPv4 netmask CIDR notation
         */
        public int ipv4MaskSize() { return ipv4MaskSize; }

        /**
         * IPv6 address (all zero when unavailable)
         */
        public ArrayList<Integer> ipv6Address() { return ipv6Address; }

        /**
         * IPv6 netmask CIDR notation
         */
        public int ipv6MaskSize() { return ipv6MaskSize; }

        /**
         * Number of Rx bytes
         */
        public long rxBytes() { return rxBytes; }

        /**
         * Number of Tx bytes
         */
        public long txBytes() { return txBytes; }

        /**
         * Interface Name
         */
        public String interfaceName() { return interfaceName; }

        /**
         * Interface flags from SIOCGIFFLAGS
         */
        public long flags() { return flags; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The bandwidth usage for each interface can be reported within this
     * struct and utilize multiple fields to fully specify the type of traffic
     * that is being tracked. As either the interval of collection or the
     * collection time may vary, both a timestamp and period field is provided,
     * though may not necessarily be populated with a value.
     */
    public static class NetworkUsage extends KaitaiStruct {
        public static NetworkUsage fromFile(String fileName) throws IOException {
            return new NetworkUsage(new ByteBufferKaitaiStream(fileName));
        }

        public NetworkUsage(KaitaiStream _io) {
            this(_io, null, null);
        }

        public NetworkUsage(KaitaiStream _io, Piksi.MsgNetworkBandwidthUsage _parent) {
            this(_io, _parent, null);
        }

        public NetworkUsage(KaitaiStream _io, Piksi.MsgNetworkBandwidthUsage _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.duration = this._io.readU8le();
            this.totalBytes = this._io.readU8le();
            this.rxBytes = this._io.readU4le();
            this.txBytes = this._io.readU4le();
            this.interfaceName = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private long duration;
        private long totalBytes;
        private long rxBytes;
        private long txBytes;
        private String interfaceName;
        private Piksi _root;
        private Piksi.MsgNetworkBandwidthUsage _parent;

        /**
         * Duration over which the measurement was collected
         */
        public long duration() { return duration; }

        /**
         * Number of bytes handled in total within period
         */
        public long totalBytes() { return totalBytes; }

        /**
         * Number of bytes transmitted within period
         */
        public long rxBytes() { return rxBytes; }

        /**
         * Number of bytes received within period
         */
        public long txBytes() { return txBytes; }

        /**
         * Interface Name
         */
        public String interfaceName() { return interfaceName; }
        public Piksi _root() { return _root; }
        public Piksi.MsgNetworkBandwidthUsage _parent() { return _parent; }
    }

    /**
     * The response to MSG_COMMAND_REQ with the return code of the command.  A
     * return code of zero indicates success.
     */
    public static class MsgCommandResp extends KaitaiStruct {
        public static MsgCommandResp fromFile(String fileName) throws IOException {
            return new MsgCommandResp(new ByteBufferKaitaiStream(fileName));
        }

        public MsgCommandResp(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgCommandResp(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgCommandResp(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sequence = this._io.readU4le();
            this.code = this._io.readS4le();
        }
        private long sequence;
        private int code;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * Sequence number
         */
        public long sequence() { return sequence; }

        /**
         * Exit code
         */
        public int code() { return code; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Returns the standard output and standard error of the command requested
     * by MSG_COMMAND_REQ. The sequence number can be used to filter for
     * filtering the correct command.
     */
    public static class MsgCommandOutput extends KaitaiStruct {
        public static MsgCommandOutput fromFile(String fileName) throws IOException {
            return new MsgCommandOutput(new ByteBufferKaitaiStream(fileName));
        }

        public MsgCommandOutput(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgCommandOutput(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgCommandOutput(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sequence = this._io.readU4le();
            this.line = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private long sequence;
        private String line;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * Sequence number
         */
        public long sequence() { return sequence; }

        /**
         * Line of standard output or standard error
         */
        public String line() { return line; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Statistics on the latency of observations received from the base
     * station. As observation packets are received their GPS time is compared
     * to the current GPS time calculated locally by the receiver to give a
     * precise measurement of the end-to-end communication latency in the
     * system.
     */
    public static class Latency extends KaitaiStruct {
        public static Latency fromFile(String fileName) throws IOException {
            return new Latency(new ByteBufferKaitaiStream(fileName));
        }

        public Latency(KaitaiStream _io) {
            this(_io, null, null);
        }

        public Latency(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public Latency(KaitaiStream _io, KaitaiStruct _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.avg = this._io.readS4le();
            this.lmin = this._io.readS4le();
            this.lmax = this._io.readS4le();
            this.current = this._io.readS4le();
        }
        private int avg;
        private int lmin;
        private int lmax;
        private int current;
        private Piksi _root;
        private KaitaiStruct _parent;

        /**
         * Average latency
         */
        public int avg() { return avg; }

        /**
         * Minimum latency
         */
        public int lmin() { return lmin; }

        /**
         * Maximum latency
         */
        public int lmax() { return lmax; }

        /**
         * Smoothed estimate of the current latency
         */
        public int current() { return current; }
        public Piksi _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * The thread usage message from the device reports real-time operating
     * system (RTOS) thread usage statistics for the named thread. The reported
     * percentage values must be normalized.
     */
    public static class MsgThreadState extends KaitaiStruct {
        public static MsgThreadState fromFile(String fileName) throws IOException {
            return new MsgThreadState(new ByteBufferKaitaiStream(fileName));
        }

        public MsgThreadState(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgThreadState(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgThreadState(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.name = new String(this._io.readBytesFull(), Charset.forName("ascii"));
            this.cpu = this._io.readU2le();
            this.stackFree = this._io.readU4le();
        }
        private String name;
        private int cpu;
        private long stackFree;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * Thread name (NULL terminated)
         */
        public String name() { return name; }

        /**
         * Percentage cpu use for this thread. Values range from 0 - 1000 and
         * needs to be renormalized to 100
         */
        public int cpu() { return cpu; }

        /**
         * Free stack space for this thread
         */
        public long stackFree() { return stackFree; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated
     */
    public static class MsgUartStateDepa extends KaitaiStruct {
        public static MsgUartStateDepa fromFile(String fileName) throws IOException {
            return new MsgUartStateDepa(new ByteBufferKaitaiStream(fileName));
        }

        public MsgUartStateDepa(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgUartStateDepa(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgUartStateDepa(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.uartA = new UartChannel(this._io, this, _root);
            this.uartB = new UartChannel(this._io, this, _root);
            this.uartFtdi = new UartChannel(this._io, this, _root);
            this.latency = new Latency(this._io, this, _root);
        }
        private UartChannel uartA;
        private UartChannel uartB;
        private UartChannel uartFtdi;
        private Latency latency;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * State of UART A
         */
        public UartChannel uartA() { return uartA; }

        /**
         * State of UART B
         */
        public UartChannel uartB() { return uartB; }

        /**
         * State of UART FTDI (USB logger)
         */
        public UartChannel uartFtdi() { return uartFtdi; }

        /**
         * UART communication latency
         */
        public Latency latency() { return latency; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Request state of Piksi network interfaces. Output will be sent in
     * MSG_NETWORK_STATE_RESP messages.
     */
    public static class MsgNetworkStateReq extends KaitaiStruct {
        public static MsgNetworkStateReq fromFile(String fileName) throws IOException {
            return new MsgNetworkStateReq(new ByteBufferKaitaiStream(fileName));
        }

        public MsgNetworkStateReq(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgNetworkStateReq(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgNetworkStateReq(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
        }
        private Piksi _root;
        private Sbp.Message _parent;
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message contains temperature and voltage level measurements from
     * the processor's monitoring system and the RF frontend die temperature if
     * available.
     */
    public static class MsgDeviceMonitor extends KaitaiStruct {
        public static MsgDeviceMonitor fromFile(String fileName) throws IOException {
            return new MsgDeviceMonitor(new ByteBufferKaitaiStream(fileName));
        }

        public MsgDeviceMonitor(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgDeviceMonitor(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgDeviceMonitor(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.devVin = this._io.readS2le();
            this.cpuVint = this._io.readS2le();
            this.cpuVaux = this._io.readS2le();
            this.cpuTemperature = this._io.readS2le();
            this.feTemperature = this._io.readS2le();
        }
        private short devVin;
        private short cpuVint;
        private short cpuVaux;
        private short cpuTemperature;
        private short feTemperature;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * Device V_in
         */
        public short devVin() { return devVin; }

        /**
         * Processor V_int
         */
        public short cpuVint() { return cpuVint; }

        /**
         * Processor V_aux
         */
        public short cpuVaux() { return cpuVaux; }

        /**
         * Processor temperature
         */
        public short cpuTemperature() { return cpuTemperature; }

        /**
         * Frontend temperature (if available)
         */
        public short feTemperature() { return feTemperature; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class MsgMaskSatelliteDep extends KaitaiStruct {
        public static MsgMaskSatelliteDep fromFile(String fileName) throws IOException {
            return new MsgMaskSatelliteDep(new ByteBufferKaitaiStream(fileName));
        }

        public MsgMaskSatelliteDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgMaskSatelliteDep(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgMaskSatelliteDep(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.mask = this._io.readU1();
            this.sid = new Gnss.GnssSignalDep(this._io, this, _root);
        }
        private int mask;
        private Gnss.GnssSignalDep sid;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * Mask of systems that should ignore this satellite.
         */
        public int mask() { return mask; }

        /**
         * GNSS signal for which the mask is applied
         */
        public Gnss.GnssSignalDep sid() { return sid; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

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
    public static class MsgUartState extends KaitaiStruct {
        public static MsgUartState fromFile(String fileName) throws IOException {
            return new MsgUartState(new ByteBufferKaitaiStream(fileName));
        }

        public MsgUartState(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgUartState(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgUartState(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.uartA = new UartChannel(this._io, this, _root);
            this.uartB = new UartChannel(this._io, this, _root);
            this.uartFtdi = new UartChannel(this._io, this, _root);
            this.latency = new Latency(this._io, this, _root);
            this.obsPeriod = new Period(this._io, this, _root);
        }
        private UartChannel uartA;
        private UartChannel uartB;
        private UartChannel uartFtdi;
        private Latency latency;
        private Period obsPeriod;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * State of UART A
         */
        public UartChannel uartA() { return uartA; }

        /**
         * State of UART B
         */
        public UartChannel uartB() { return uartB; }

        /**
         * State of UART FTDI (USB logger)
         */
        public UartChannel uartFtdi() { return uartFtdi; }

        /**
         * UART communication latency
         */
        public Latency latency() { return latency; }

        /**
         * Observation receipt period
         */
        public Period obsPeriod() { return obsPeriod; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Spectrum analyzer packet.
     */
    public static class MsgSpecan extends KaitaiStruct {
        public static MsgSpecan fromFile(String fileName) throws IOException {
            return new MsgSpecan(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSpecan(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSpecan(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSpecan(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.channelTag = this._io.readU2le();
            this.t = new Gnss.GpsTime(this._io, this, _root);
            this.freqRef = this._io.readF4le();
            this.freqStep = this._io.readF4le();
            this.amplitudeRef = this._io.readF4le();
            this.amplitudeUnit = this._io.readF4le();
            this.amplitudeValue = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.amplitudeValue.add(this._io.readU1());
                    i++;
                }
            }
        }
        private int channelTag;
        private Gnss.GpsTime t;
        private float freqRef;
        private float freqStep;
        private float amplitudeRef;
        private float amplitudeUnit;
        private ArrayList<Integer> amplitudeValue;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * Channel ID
         */
        public int channelTag() { return channelTag; }

        /**
         * Receiver time of this observation
         */
        public Gnss.GpsTime t() { return t; }

        /**
         * Reference frequency of this packet
         */
        public float freqRef() { return freqRef; }

        /**
         * Frequency step of points in this packet
         */
        public float freqStep() { return freqStep; }

        /**
         * Reference amplitude of this packet
         */
        public float amplitudeRef() { return amplitudeRef; }

        /**
         * Amplitude unit value of points in this packet
         */
        public float amplitudeUnit() { return amplitudeUnit; }

        /**
         * Amplitude values (in the above units) of points in this packet
         */
        public ArrayList<Integer> amplitudeValue() { return amplitudeValue; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the state of the Integer Ambiguity Resolution (IAR)
     * process, which resolves unknown integer ambiguities from double-
     * differenced carrier-phase measurements from satellite observations.
     */
    public static class MsgIarState extends KaitaiStruct {
        public static MsgIarState fromFile(String fileName) throws IOException {
            return new MsgIarState(new ByteBufferKaitaiStream(fileName));
        }

        public MsgIarState(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgIarState(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgIarState(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.numHyps = this._io.readU4le();
        }
        private long numHyps;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * Number of integer ambiguity hypotheses remaining
         */
        public long numHyps() { return numHyps; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This is a legacy message for sending and loading a satellite alamanac
     * onto the Piksi's flash memory from the host.
     */
    public static class MsgAlmanac extends KaitaiStruct {
        public static MsgAlmanac fromFile(String fileName) throws IOException {
            return new MsgAlmanac(new ByteBufferKaitaiStream(fileName));
        }

        public MsgAlmanac(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgAlmanac(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgAlmanac(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
        }
        private Piksi _root;
        private Sbp.Message _parent;
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message resets either the DGNSS Kalman filters or Integer Ambiguity
     * Resolution (IAR) process.
     */
    public static class MsgResetFilters extends KaitaiStruct {
        public static MsgResetFilters fromFile(String fileName) throws IOException {
            return new MsgResetFilters(new ByteBufferKaitaiStream(fileName));
        }

        public MsgResetFilters(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgResetFilters(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgResetFilters(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.filter = this._io.readU1();
        }
        private int filter;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * Filter flags
         */
        public int filter() { return filter; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Throughput, utilization, and error counts on the RX/TX buffers of this
     * UART channel. The reported percentage values must be normalized.
     */
    public static class UartChannel extends KaitaiStruct {
        public static UartChannel fromFile(String fileName) throws IOException {
            return new UartChannel(new ByteBufferKaitaiStream(fileName));
        }

        public UartChannel(KaitaiStream _io) {
            this(_io, null, null);
        }

        public UartChannel(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public UartChannel(KaitaiStream _io, KaitaiStruct _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.txThroughput = this._io.readF4le();
            this.rxThroughput = this._io.readF4le();
            this.crcErrorCount = this._io.readU2le();
            this.ioErrorCount = this._io.readU2le();
            this.txBufferLevel = this._io.readU1();
            this.rxBufferLevel = this._io.readU1();
        }
        private float txThroughput;
        private float rxThroughput;
        private int crcErrorCount;
        private int ioErrorCount;
        private int txBufferLevel;
        private int rxBufferLevel;
        private Piksi _root;
        private KaitaiStruct _parent;

        /**
         * UART transmit throughput
         */
        public float txThroughput() { return txThroughput; }

        /**
         * UART receive throughput
         */
        public float rxThroughput() { return rxThroughput; }

        /**
         * UART CRC error count
         */
        public int crcErrorCount() { return crcErrorCount; }

        /**
         * UART IO error count
         */
        public int ioErrorCount() { return ioErrorCount; }

        /**
         * UART transmit buffer percentage utilization (ranges from 0 to 255)
         */
        public int txBufferLevel() { return txBufferLevel; }

        /**
         * UART receive buffer percentage utilization (ranges from 0 to 255)
         */
        public int rxBufferLevel() { return rxBufferLevel; }
        public Piksi _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * Request the recipient to execute an command. Output will be sent in
     * MSG_LOG messages, and the exit code will be returned with
     * MSG_COMMAND_RESP.
     */
    public static class MsgCommandReq extends KaitaiStruct {
        public static MsgCommandReq fromFile(String fileName) throws IOException {
            return new MsgCommandReq(new ByteBufferKaitaiStream(fileName));
        }

        public MsgCommandReq(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgCommandReq(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgCommandReq(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sequence = this._io.readU4le();
            this.command = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private long sequence;
        private String command;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * Sequence number
         */
        public long sequence() { return sequence; }

        /**
         * Command line to execute
         */
        public String command() { return command; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message allows setting a mask to prevent a particular satellite
     * from being used in various Piksi subsystems.
     */
    public static class MsgMaskSatellite extends KaitaiStruct {
        public static MsgMaskSatellite fromFile(String fileName) throws IOException {
            return new MsgMaskSatellite(new ByteBufferKaitaiStream(fileName));
        }

        public MsgMaskSatellite(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgMaskSatellite(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgMaskSatellite(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.mask = this._io.readU1();
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
        }
        private int mask;
        private Gnss.GnssSignal sid;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * Mask of systems that should ignore this satellite.
         */
        public int mask() { return mask; }

        /**
         * GNSS signal for which the mask is applied
         */
        public Gnss.GnssSignal sid() { return sid; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The bandwidth usage, a list of usage by interface.
     */
    public static class MsgNetworkBandwidthUsage extends KaitaiStruct {
        public static MsgNetworkBandwidthUsage fromFile(String fileName) throws IOException {
            return new MsgNetworkBandwidthUsage(new ByteBufferKaitaiStream(fileName));
        }

        public MsgNetworkBandwidthUsage(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgNetworkBandwidthUsage(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgNetworkBandwidthUsage(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.interfaces = new ArrayList<NetworkUsage>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.interfaces.add(new NetworkUsage(this._io, this, _root));
                    i++;
                }
            }
        }
        private ArrayList<NetworkUsage> interfaces;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * Usage measurement array
         */
        public ArrayList<NetworkUsage> interfaces() { return interfaces; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message from the host resets the Piksi back into the bootloader.
     */
    public static class MsgReset extends KaitaiStruct {
        public static MsgReset fromFile(String fileName) throws IOException {
            return new MsgReset(new ByteBufferKaitaiStream(fileName));
        }

        public MsgReset(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgReset(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgReset(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.flags = this._io.readU4le();
        }
        private long flags;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * Reset flags
         */
        public long flags() { return flags; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * If a cell modem is present on a piksi device, this message will be send
     * periodically to update the host on the status of the modem and its
     * various parameters.
     */
    public static class MsgCellModemStatus extends KaitaiStruct {
        public static MsgCellModemStatus fromFile(String fileName) throws IOException {
            return new MsgCellModemStatus(new ByteBufferKaitaiStream(fileName));
        }

        public MsgCellModemStatus(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgCellModemStatus(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgCellModemStatus(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.signalStrength = this._io.readS1();
            this.signalErrorRate = this._io.readF4le();
            this.reserved = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.reserved.add(this._io.readU1());
                    i++;
                }
            }
        }
        private byte signalStrength;
        private float signalErrorRate;
        private ArrayList<Integer> reserved;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * Received cell signal strength in dBm, zero translates to unknown
         */
        public byte signalStrength() { return signalStrength; }

        /**
         * BER as reported by the modem, zero translates to unknown
         */
        public float signalErrorRate() { return signalErrorRate; }

        /**
         * Unspecified data TBD for this schema
         */
        public ArrayList<Integer> reserved() { return reserved; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

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
    public static class MsgFrontEndGain extends KaitaiStruct {
        public static MsgFrontEndGain fromFile(String fileName) throws IOException {
            return new MsgFrontEndGain(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFrontEndGain(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFrontEndGain(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFrontEndGain(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.rfGain = new ArrayList<Byte>();
            for (int i = 0; i < 8; i++) {
                this.rfGain.add(this._io.readS1());
            }
            this.ifGain = new ArrayList<Byte>();
            for (int i = 0; i < 8; i++) {
                this.ifGain.add(this._io.readS1());
            }
        }
        private ArrayList<Byte> rfGain;
        private ArrayList<Byte> ifGain;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * RF gain for each frontend channel
         */
        public ArrayList<Byte> rfGain() { return rfGain; }

        /**
         * Intermediate frequency gain for each frontend channel
         */
        public ArrayList<Byte> ifGain() { return ifGain; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message from the host resets the Piksi back into the bootloader.
     */
    public static class MsgResetDep extends KaitaiStruct {
        public static MsgResetDep fromFile(String fileName) throws IOException {
            return new MsgResetDep(new ByteBufferKaitaiStream(fileName));
        }

        public MsgResetDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgResetDep(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgResetDep(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
        }
        private Piksi _root;
        private Sbp.Message _parent;
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message sets up timing functionality using a coarse GPS time
     * estimate sent by the host.
     */
    public static class MsgSetTime extends KaitaiStruct {
        public static MsgSetTime fromFile(String fileName) throws IOException {
            return new MsgSetTime(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSetTime(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSetTime(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSetTime(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
        }
        private Piksi _root;
        private Sbp.Message _parent;
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This is an unused legacy message for result reporting from the CW
     * interference channel on the SwiftNAP. This message will be removed in a
     * future release.
     */
    public static class MsgCwResults extends KaitaiStruct {
        public static MsgCwResults fromFile(String fileName) throws IOException {
            return new MsgCwResults(new ByteBufferKaitaiStream(fileName));
        }

        public MsgCwResults(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgCwResults(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgCwResults(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
        }
        private Piksi _root;
        private Sbp.Message _parent;
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class MsgSpecanDep extends KaitaiStruct {
        public static MsgSpecanDep fromFile(String fileName) throws IOException {
            return new MsgSpecanDep(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSpecanDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSpecanDep(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSpecanDep(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.channelTag = this._io.readU2le();
            this.t = new Gnss.GpsTimeDep(this._io, this, _root);
            this.freqRef = this._io.readF4le();
            this.freqStep = this._io.readF4le();
            this.amplitudeRef = this._io.readF4le();
            this.amplitudeUnit = this._io.readF4le();
            this.amplitudeValue = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.amplitudeValue.add(this._io.readU1());
                    i++;
                }
            }
        }
        private int channelTag;
        private Gnss.GpsTimeDep t;
        private float freqRef;
        private float freqStep;
        private float amplitudeRef;
        private float amplitudeUnit;
        private ArrayList<Integer> amplitudeValue;
        private Piksi _root;
        private Sbp.Message _parent;

        /**
         * Channel ID
         */
        public int channelTag() { return channelTag; }

        /**
         * Receiver time of this observation
         */
        public Gnss.GpsTimeDep t() { return t; }

        /**
         * Reference frequency of this packet
         */
        public float freqRef() { return freqRef; }

        /**
         * Frequency step of points in this packet
         */
        public float freqStep() { return freqStep; }

        /**
         * Reference amplitude of this packet
         */
        public float amplitudeRef() { return amplitudeRef; }

        /**
         * Amplitude unit value of points in this packet
         */
        public float amplitudeUnit() { return amplitudeUnit; }

        /**
         * Amplitude values (in the above units) of points in this packet
         */
        public ArrayList<Integer> amplitudeValue() { return amplitudeValue; }
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated
     */
    public static class MsgInitBaseDep extends KaitaiStruct {
        public static MsgInitBaseDep fromFile(String fileName) throws IOException {
            return new MsgInitBaseDep(new ByteBufferKaitaiStream(fileName));
        }

        public MsgInitBaseDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgInitBaseDep(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgInitBaseDep(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
        }
        private Piksi _root;
        private Sbp.Message _parent;
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Statistics on the period of observations received from the base station.
     * As complete observation sets are received, their time of reception is
     * compared with the prior set''s time of reception. This measurement
     * provides a proxy for link quality as incomplete or missing sets will
     * increase the period.  Long periods can cause momentary RTK solution
     * outages.
     */
    public static class Period extends KaitaiStruct {
        public static Period fromFile(String fileName) throws IOException {
            return new Period(new ByteBufferKaitaiStream(fileName));
        }

        public Period(KaitaiStream _io) {
            this(_io, null, null);
        }

        public Period(KaitaiStream _io, Piksi.MsgUartState _parent) {
            this(_io, _parent, null);
        }

        public Period(KaitaiStream _io, Piksi.MsgUartState _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.avg = this._io.readS4le();
            this.pmin = this._io.readS4le();
            this.pmax = this._io.readS4le();
            this.current = this._io.readS4le();
        }
        private int avg;
        private int pmin;
        private int pmax;
        private int current;
        private Piksi _root;
        private Piksi.MsgUartState _parent;

        /**
         * Average period
         */
        public int avg() { return avg; }

        /**
         * Minimum period
         */
        public int pmin() { return pmin; }

        /**
         * Maximum period
         */
        public int pmax() { return pmax; }

        /**
         * Smoothed estimate of the current period
         */
        public int current() { return current; }
        public Piksi _root() { return _root; }
        public Piksi.MsgUartState _parent() { return _parent; }
    }

    /**
     * This is an unused legacy message from the host for starting the CW
     * interference channel on the SwiftNAP. This message will be removed in a
     * future release.
     */
    public static class MsgCwStart extends KaitaiStruct {
        public static MsgCwStart fromFile(String fileName) throws IOException {
            return new MsgCwStart(new ByteBufferKaitaiStream(fileName));
        }

        public MsgCwStart(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgCwStart(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgCwStart(KaitaiStream _io, Sbp.Message _parent, Piksi _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
        }
        private Piksi _root;
        private Sbp.Message _parent;
        public Piksi _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Piksi _root;
    private KaitaiStruct _parent;
    public Piksi _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
