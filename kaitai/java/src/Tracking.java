// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.util.ArrayList;

public class Tracking extends KaitaiStruct {
    public static Tracking fromFile(String fileName) throws IOException {
        return new Tracking(new ByteBufferKaitaiStream(fileName));
    }

    public Tracking(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Tracking(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Tracking(KaitaiStream _io, KaitaiStruct _parent, Tracking _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * Deprecated.
     */
    public static class MsgTrackingStateDetailedDep extends KaitaiStruct {
        public static MsgTrackingStateDetailedDep fromFile(String fileName) throws IOException {
            return new MsgTrackingStateDetailedDep(new ByteBufferKaitaiStream(fileName));
        }

        public MsgTrackingStateDetailedDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgTrackingStateDetailedDep(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgTrackingStateDetailedDep(KaitaiStream _io, Sbp.Message _parent, Tracking _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.recvTime = this._io.readU8le();
            this.tot = new Gnss.GpsTimeDep(this._io, this, _root);
            this.p = this._io.readU4le();
            this.pStd = this._io.readU2le();
            this.l = new Gnss.CarrierPhase(this._io, this, _root);
            this.cn0 = this._io.readU1();
            this.lock = this._io.readU2le();
            this.sid = new Gnss.GnssSignalDep(this._io, this, _root);
            this.doppler = this._io.readS4le();
            this.dopplerStd = this._io.readU2le();
            this.uptime = this._io.readU4le();
            this.clockOffset = this._io.readS2le();
            this.clockDrift = this._io.readS2le();
            this.corrSpacing = this._io.readU2le();
            this.acceleration = this._io.readS1();
            this.syncFlags = this._io.readU1();
            this.towFlags = this._io.readU1();
            this.trackFlags = this._io.readU1();
            this.navFlags = this._io.readU1();
            this.psetFlags = this._io.readU1();
            this.miscFlags = this._io.readU1();
        }
        private long recvTime;
        private Gnss.GpsTimeDep tot;
        private long p;
        private int pStd;
        private Gnss.CarrierPhase l;
        private int cn0;
        private int lock;
        private Gnss.GnssSignalDep sid;
        private int doppler;
        private int dopplerStd;
        private long uptime;
        private short clockOffset;
        private short clockDrift;
        private int corrSpacing;
        private byte acceleration;
        private int syncFlags;
        private int towFlags;
        private int trackFlags;
        private int navFlags;
        private int psetFlags;
        private int miscFlags;
        private Tracking _root;
        private Sbp.Message _parent;

        /**
         * Receiver clock time.
         */
        public long recvTime() { return recvTime; }

        /**
         * Time of transmission of signal from satellite. TOW only valid when
         * TOW status is decoded or propagated. WN only valid when week number
         * valid flag is set.
         */
        public Gnss.GpsTimeDep tot() { return tot; }

        /**
         * Pseudorange observation. Valid only when pseudorange valid flag is
         * set.
         */
        public long p() { return p; }

        /**
         * Pseudorange observation standard deviation. Valid only when
         * pseudorange valid flag is set.
         */
        public int pStd() { return pStd; }

        /**
         * Carrier phase observation with typical sign convention. Valid only
         * when PLL pessimistic lock is achieved.
         */
        public Gnss.CarrierPhase l() { return l; }

        /**
         * Carrier-to-Noise density
         */
        public int cn0() { return cn0; }

        /**
         * Lock time. It is encoded according to DF402 from the RTCM 10403.2
         * Amendment 2 specification. Valid values range from 0 to 15.
         */
        public int lock() { return lock; }

        /**
         * GNSS signal identifier.
         */
        public Gnss.GnssSignalDep sid() { return sid; }

        /**
         * Carrier Doppler frequency.
         */
        public int doppler() { return doppler; }

        /**
         * Carrier Doppler frequency standard deviation.
         */
        public int dopplerStd() { return dopplerStd; }

        /**
         * Number of seconds of continuous tracking. Specifies how much time
         * signal is in continuous track.
         */
        public long uptime() { return uptime; }

        /**
         * TCXO clock offset. Valid only when valid clock valid flag is set.
         */
        public short clockOffset() { return clockOffset; }

        /**
         * TCXO clock drift. Valid only when valid clock valid flag is set.
         */
        public short clockDrift() { return clockDrift; }

        /**
         * Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
         */
        public int corrSpacing() { return corrSpacing; }

        /**
         * Acceleration. Valid only when acceleration valid flag is set.
         */
        public byte acceleration() { return acceleration; }

        /**
         * Synchronization status flags.
         */
        public int syncFlags() { return syncFlags; }

        /**
         * TOW status flags.
         */
        public int towFlags() { return towFlags; }

        /**
         * Tracking loop status flags.
         */
        public int trackFlags() { return trackFlags; }

        /**
         * Navigation data status flags.
         */
        public int navFlags() { return navFlags; }

        /**
         * Parameters sets flags.
         */
        public int psetFlags() { return psetFlags; }

        /**
         * Miscellaneous flags.
         */
        public int miscFlags() { return miscFlags; }
        public Tracking _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class TrackingChannelStateDepB extends KaitaiStruct {
        public static TrackingChannelStateDepB fromFile(String fileName) throws IOException {
            return new TrackingChannelStateDepB(new ByteBufferKaitaiStream(fileName));
        }

        public TrackingChannelStateDepB(KaitaiStream _io) {
            this(_io, null, null);
        }

        public TrackingChannelStateDepB(KaitaiStream _io, Tracking.MsgTrackingStateDepB _parent) {
            this(_io, _parent, null);
        }

        public TrackingChannelStateDepB(KaitaiStream _io, Tracking.MsgTrackingStateDepB _parent, Tracking _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.state = this._io.readU1();
            this.sid = new Gnss.GnssSignalDep(this._io, this, _root);
            this.cn0 = this._io.readF4le();
        }
        private int state;
        private Gnss.GnssSignalDep sid;
        private float cn0;
        private Tracking _root;
        private Tracking.MsgTrackingStateDepB _parent;

        /**
         * Status of tracking channel
         */
        public int state() { return state; }

        /**
         * GNSS signal being tracked
         */
        public Gnss.GnssSignalDep sid() { return sid; }

        /**
         * Carrier-to-noise density
         */
        public float cn0() { return cn0; }
        public Tracking _root() { return _root; }
        public Tracking.MsgTrackingStateDepB _parent() { return _parent; }
    }

    /**
     * Tracking channel state for a specific satellite signal and measured
     * signal power.
     */
    public static class TrackingChannelState extends KaitaiStruct {
        public static TrackingChannelState fromFile(String fileName) throws IOException {
            return new TrackingChannelState(new ByteBufferKaitaiStream(fileName));
        }

        public TrackingChannelState(KaitaiStream _io) {
            this(_io, null, null);
        }

        public TrackingChannelState(KaitaiStream _io, Tracking.MsgTrackingState _parent) {
            this(_io, _parent, null);
        }

        public TrackingChannelState(KaitaiStream _io, Tracking.MsgTrackingState _parent, Tracking _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.fcn = this._io.readU1();
            this.cn0 = this._io.readU1();
        }
        private Gnss.GnssSignal sid;
        private int fcn;
        private int cn0;
        private Tracking _root;
        private Tracking.MsgTrackingState _parent;

        /**
         * GNSS signal being tracked
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * Frequency channel number (GLONASS only)
         */
        public int fcn() { return fcn; }

        /**
         * Carrier-to-Noise density.  Zero implies invalid cn0.
         */
        public int cn0() { return cn0; }
        public Tracking _root() { return _root; }
        public Tracking.MsgTrackingState _parent() { return _parent; }
    }

    /**
     * The tracking message returns a variable-length array of tracking channel
     * states. It reports status and carrier-to-noise density measurements for
     * all tracked satellites.
     */
    public static class MsgTrackingState extends KaitaiStruct {
        public static MsgTrackingState fromFile(String fileName) throws IOException {
            return new MsgTrackingState(new ByteBufferKaitaiStream(fileName));
        }

        public MsgTrackingState(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgTrackingState(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgTrackingState(KaitaiStream _io, Sbp.Message _parent, Tracking _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.states = new ArrayList<TrackingChannelState>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.states.add(new TrackingChannelState(this._io, this, _root));
                    i++;
                }
            }
        }
        private ArrayList<TrackingChannelState> states;
        private Tracking _root;
        private Sbp.Message _parent;

        /**
         * Signal tracking channel state
         */
        public ArrayList<TrackingChannelState> states() { return states; }
        public Tracking _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class TrackingChannelStateDepA extends KaitaiStruct {
        public static TrackingChannelStateDepA fromFile(String fileName) throws IOException {
            return new TrackingChannelStateDepA(new ByteBufferKaitaiStream(fileName));
        }

        public TrackingChannelStateDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public TrackingChannelStateDepA(KaitaiStream _io, Tracking.MsgTrackingStateDepA _parent) {
            this(_io, _parent, null);
        }

        public TrackingChannelStateDepA(KaitaiStream _io, Tracking.MsgTrackingStateDepA _parent, Tracking _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.state = this._io.readU1();
            this.prn = this._io.readU1();
            this.cn0 = this._io.readF4le();
        }
        private int state;
        private int prn;
        private float cn0;
        private Tracking _root;
        private Tracking.MsgTrackingStateDepA _parent;

        /**
         * Status of tracking channel
         */
        public int state() { return state; }

        /**
         * PRN-1 being tracked
         */
        public int prn() { return prn; }

        /**
         * Carrier-to-noise density
         */
        public float cn0() { return cn0; }
        public Tracking _root() { return _root; }
        public Tracking.MsgTrackingStateDepA _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class MsgTrackingIqDepA extends KaitaiStruct {
        public static MsgTrackingIqDepA fromFile(String fileName) throws IOException {
            return new MsgTrackingIqDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgTrackingIqDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgTrackingIqDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgTrackingIqDepA(KaitaiStream _io, Sbp.Message _parent, Tracking _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.channel = this._io.readU1();
            this.sid = new Gnss.GnssSignalDep(this._io, this, _root);
            this.corrs = new ArrayList<Long>();
            for (int i = 0; i < 3; i++) {
                this.corrs.add(this._io.readU8le());
            }
        }
        private int channel;
        private Gnss.GnssSignalDep sid;
        private ArrayList<Long> corrs;
        private Tracking _root;
        private Sbp.Message _parent;

        /**
         * Tracking channel of origin
         */
        public int channel() { return channel; }

        /**
         * GNSS signal identifier
         */
        public Gnss.GnssSignalDep sid() { return sid; }

        /**
         * Early, Prompt and Late correlations
         */
        public ArrayList<Long> corrs() { return corrs; }
        public Tracking _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Structure containing in-phase and quadrature correlation components.
     */
    public static class TrackingChannelCorrelationDep extends KaitaiStruct {
        public static TrackingChannelCorrelationDep fromFile(String fileName) throws IOException {
            return new TrackingChannelCorrelationDep(new ByteBufferKaitaiStream(fileName));
        }

        public TrackingChannelCorrelationDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public TrackingChannelCorrelationDep(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public TrackingChannelCorrelationDep(KaitaiStream _io, KaitaiStruct _parent, Tracking _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.i = this._io.readS4le();
            this.q = this._io.readS4le();
        }
        private int i;
        private int q;
        private Tracking _root;
        private KaitaiStruct _parent;

        /**
         * In-phase correlation
         */
        public int i() { return i; }

        /**
         * Quadrature correlation
         */
        public int q() { return q; }
        public Tracking _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class MsgTrackingStateDepA extends KaitaiStruct {
        public static MsgTrackingStateDepA fromFile(String fileName) throws IOException {
            return new MsgTrackingStateDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgTrackingStateDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgTrackingStateDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgTrackingStateDepA(KaitaiStream _io, Sbp.Message _parent, Tracking _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.states = new ArrayList<TrackingChannelStateDepA>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.states.add(new TrackingChannelStateDepA(this._io, this, _root));
                    i++;
                }
            }
        }
        private ArrayList<TrackingChannelStateDepA> states;
        private Tracking _root;
        private Sbp.Message _parent;

        /**
         * Satellite tracking channel state
         */
        public ArrayList<TrackingChannelStateDepA> states() { return states; }
        public Tracking _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The tracking message returns a variable-length array of tracking channel
     * states. It reports status and carrier-to-noise density measurements for
     * all tracked satellites.
     */
    public static class MsgMeasurementState extends KaitaiStruct {
        public static MsgMeasurementState fromFile(String fileName) throws IOException {
            return new MsgMeasurementState(new ByteBufferKaitaiStream(fileName));
        }

        public MsgMeasurementState(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgMeasurementState(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgMeasurementState(KaitaiStream _io, Sbp.Message _parent, Tracking _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.states = new ArrayList<MeasurementState>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.states.add(new MeasurementState(this._io, this, _root));
                    i++;
                }
            }
        }
        private ArrayList<MeasurementState> states;
        private Tracking _root;
        private Sbp.Message _parent;

        /**
         * ME signal tracking channel state
         */
        public ArrayList<MeasurementState> states() { return states; }
        public Tracking _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Structure containing in-phase and quadrature correlation components.
     */
    public static class TrackingChannelCorrelation extends KaitaiStruct {
        public static TrackingChannelCorrelation fromFile(String fileName) throws IOException {
            return new TrackingChannelCorrelation(new ByteBufferKaitaiStream(fileName));
        }

        public TrackingChannelCorrelation(KaitaiStream _io) {
            this(_io, null, null);
        }

        public TrackingChannelCorrelation(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public TrackingChannelCorrelation(KaitaiStream _io, KaitaiStruct _parent, Tracking _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.i = this._io.readS2le();
            this.q = this._io.readS2le();
        }
        private short i;
        private short q;
        private Tracking _root;
        private KaitaiStruct _parent;

        /**
         * In-phase correlation
         */
        public short i() { return i; }

        /**
         * Quadrature correlation
         */
        public short q() { return q; }
        public Tracking _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * When enabled, a tracking channel can output the correlations at each
     * update interval.
     */
    public static class MsgTrackingIq extends KaitaiStruct {
        public static MsgTrackingIq fromFile(String fileName) throws IOException {
            return new MsgTrackingIq(new ByteBufferKaitaiStream(fileName));
        }

        public MsgTrackingIq(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgTrackingIq(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgTrackingIq(KaitaiStream _io, Sbp.Message _parent, Tracking _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.channel = this._io.readU1();
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.corrs = new ArrayList<Long>();
            for (int i = 0; i < 3; i++) {
                this.corrs.add(this._io.readU8le());
            }
        }
        private int channel;
        private Gnss.GnssSignal sid;
        private ArrayList<Long> corrs;
        private Tracking _root;
        private Sbp.Message _parent;

        /**
         * Tracking channel of origin
         */
        public int channel() { return channel; }

        /**
         * GNSS signal identifier
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * Early, Prompt and Late correlations
         */
        public ArrayList<Long> corrs() { return corrs; }
        public Tracking _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The tracking message returns a set tracking channel parameters for a
     * single tracking channel useful for debugging issues.
     */
    public static class MsgTrackingStateDetailedDepA extends KaitaiStruct {
        public static MsgTrackingStateDetailedDepA fromFile(String fileName) throws IOException {
            return new MsgTrackingStateDetailedDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgTrackingStateDetailedDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgTrackingStateDetailedDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgTrackingStateDetailedDepA(KaitaiStream _io, Sbp.Message _parent, Tracking _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.recvTime = this._io.readU8le();
            this.tot = new Gnss.GpsTime(this._io, this, _root);
            this.p = this._io.readU4le();
            this.pStd = this._io.readU2le();
            this.l = new Gnss.CarrierPhase(this._io, this, _root);
            this.cn0 = this._io.readU1();
            this.lock = this._io.readU2le();
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.doppler = this._io.readS4le();
            this.dopplerStd = this._io.readU2le();
            this.uptime = this._io.readU4le();
            this.clockOffset = this._io.readS2le();
            this.clockDrift = this._io.readS2le();
            this.corrSpacing = this._io.readU2le();
            this.acceleration = this._io.readS1();
            this.syncFlags = this._io.readU1();
            this.towFlags = this._io.readU1();
            this.trackFlags = this._io.readU1();
            this.navFlags = this._io.readU1();
            this.psetFlags = this._io.readU1();
            this.miscFlags = this._io.readU1();
        }
        private long recvTime;
        private Gnss.GpsTime tot;
        private long p;
        private int pStd;
        private Gnss.CarrierPhase l;
        private int cn0;
        private int lock;
        private Gnss.GnssSignal sid;
        private int doppler;
        private int dopplerStd;
        private long uptime;
        private short clockOffset;
        private short clockDrift;
        private int corrSpacing;
        private byte acceleration;
        private int syncFlags;
        private int towFlags;
        private int trackFlags;
        private int navFlags;
        private int psetFlags;
        private int miscFlags;
        private Tracking _root;
        private Sbp.Message _parent;

        /**
         * Receiver clock time.
         */
        public long recvTime() { return recvTime; }

        /**
         * Time of transmission of signal from satellite. TOW only valid when
         * TOW status is decoded or propagated. WN only valid when week number
         * valid flag is set.
         */
        public Gnss.GpsTime tot() { return tot; }

        /**
         * Pseudorange observation. Valid only when pseudorange valid flag is
         * set.
         */
        public long p() { return p; }

        /**
         * Pseudorange observation standard deviation. Valid only when
         * pseudorange valid flag is set.
         */
        public int pStd() { return pStd; }

        /**
         * Carrier phase observation with typical sign convention. Valid only
         * when PLL pessimistic lock is achieved.
         */
        public Gnss.CarrierPhase l() { return l; }

        /**
         * Carrier-to-Noise density
         */
        public int cn0() { return cn0; }

        /**
         * Lock time. It is encoded according to DF402 from the RTCM 10403.2
         * Amendment 2 specification. Valid values range from 0 to 15.
         */
        public int lock() { return lock; }

        /**
         * GNSS signal identifier.
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * Carrier Doppler frequency.
         */
        public int doppler() { return doppler; }

        /**
         * Carrier Doppler frequency standard deviation.
         */
        public int dopplerStd() { return dopplerStd; }

        /**
         * Number of seconds of continuous tracking. Specifies how much time
         * signal is in continuous track.
         */
        public long uptime() { return uptime; }

        /**
         * TCXO clock offset. Valid only when valid clock valid flag is set.
         */
        public short clockOffset() { return clockOffset; }

        /**
         * TCXO clock drift. Valid only when valid clock valid flag is set.
         */
        public short clockDrift() { return clockDrift; }

        /**
         * Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
         */
        public int corrSpacing() { return corrSpacing; }

        /**
         * Acceleration. Valid only when acceleration valid flag is set.
         */
        public byte acceleration() { return acceleration; }

        /**
         * Synchronization status flags.
         */
        public int syncFlags() { return syncFlags; }

        /**
         * TOW status flags.
         */
        public int towFlags() { return towFlags; }

        /**
         * Tracking loop status flags.
         */
        public int trackFlags() { return trackFlags; }

        /**
         * Navigation data status flags.
         */
        public int navFlags() { return navFlags; }

        /**
         * Parameters sets flags.
         */
        public int psetFlags() { return psetFlags; }

        /**
         * Miscellaneous flags.
         */
        public int miscFlags() { return miscFlags; }
        public Tracking _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class MsgTrackingStateDepB extends KaitaiStruct {
        public static MsgTrackingStateDepB fromFile(String fileName) throws IOException {
            return new MsgTrackingStateDepB(new ByteBufferKaitaiStream(fileName));
        }

        public MsgTrackingStateDepB(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgTrackingStateDepB(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgTrackingStateDepB(KaitaiStream _io, Sbp.Message _parent, Tracking _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.states = new ArrayList<TrackingChannelStateDepB>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.states.add(new TrackingChannelStateDepB(this._io, this, _root));
                    i++;
                }
            }
        }
        private ArrayList<TrackingChannelStateDepB> states;
        private Tracking _root;
        private Sbp.Message _parent;

        /**
         * Signal tracking channel state
         */
        public ArrayList<TrackingChannelStateDepB> states() { return states; }
        public Tracking _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Measurement Engine tracking channel state for a specific satellite
     * signal and measured signal power. The mesid field for Glonass can either
     * carry the FCN as 100 + FCN where FCN is in [-7, +6] or the Slot ID (from
     * 1 to 28).
     */
    public static class MeasurementState extends KaitaiStruct {
        public static MeasurementState fromFile(String fileName) throws IOException {
            return new MeasurementState(new ByteBufferKaitaiStream(fileName));
        }

        public MeasurementState(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MeasurementState(KaitaiStream _io, Tracking.MsgMeasurementState _parent) {
            this(_io, _parent, null);
        }

        public MeasurementState(KaitaiStream _io, Tracking.MsgMeasurementState _parent, Tracking _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.mesid = new Gnss.GnssSignal(this._io, this, _root);
            this.cn0 = this._io.readU1();
        }
        private Gnss.GnssSignal mesid;
        private int cn0;
        private Tracking _root;
        private Tracking.MsgMeasurementState _parent;

        /**
         * Measurement Engine GNSS signal being tracked (carries either Glonass
         * FCN or SLOT)
         */
        public Gnss.GnssSignal mesid() { return mesid; }

        /**
         * Carrier-to-Noise density.  Zero implies invalid cn0.
         */
        public int cn0() { return cn0; }
        public Tracking _root() { return _root; }
        public Tracking.MsgMeasurementState _parent() { return _parent; }
    }

    /**
     * When enabled, a tracking channel can output the correlations at each
     * update interval.
     */
    public static class MsgTrackingIqDepB extends KaitaiStruct {
        public static MsgTrackingIqDepB fromFile(String fileName) throws IOException {
            return new MsgTrackingIqDepB(new ByteBufferKaitaiStream(fileName));
        }

        public MsgTrackingIqDepB(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgTrackingIqDepB(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgTrackingIqDepB(KaitaiStream _io, Sbp.Message _parent, Tracking _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.channel = this._io.readU1();
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.corrs = new ArrayList<Long>();
            for (int i = 0; i < 3; i++) {
                this.corrs.add(this._io.readU8le());
            }
        }
        private int channel;
        private Gnss.GnssSignal sid;
        private ArrayList<Long> corrs;
        private Tracking _root;
        private Sbp.Message _parent;

        /**
         * Tracking channel of origin
         */
        public int channel() { return channel; }

        /**
         * GNSS signal identifier
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * Early, Prompt and Late correlations
         */
        public ArrayList<Long> corrs() { return corrs; }
        public Tracking _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Tracking _root;
    private KaitaiStruct _parent;
    public Tracking _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
