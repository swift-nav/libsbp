// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.util.ArrayList;

public class Observation extends KaitaiStruct {
    public static Observation fromFile(String fileName) throws IOException {
        return new Observation(new ByteBufferKaitaiStream(fileName));
    }

    public Observation(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Observation(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Observation(KaitaiStream _io, KaitaiStruct _parent, Observation _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * Azimuth and elevation angles of all the visible satellites that the
     * device does have ephemeris or almanac for.
     */
    public static class MsgSvAzEl extends KaitaiStruct {
        public static MsgSvAzEl fromFile(String fileName) throws IOException {
            return new MsgSvAzEl(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSvAzEl(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSvAzEl(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSvAzEl(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.azel = new ArrayList<SvAzEl>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.azel.add(new SvAzEl(this._io, this, _root));
                    i++;
                }
            }
        }
        private ArrayList<SvAzEl> azel;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Azimuth and elevation per satellite
         */
        public ArrayList<SvAzEl> azel() { return azel; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class GnssCapb extends KaitaiStruct {
        public static GnssCapb fromFile(String fileName) throws IOException {
            return new GnssCapb(new ByteBufferKaitaiStream(fileName));
        }

        public GnssCapb(KaitaiStream _io) {
            this(_io, null, null);
        }

        public GnssCapb(KaitaiStream _io, Observation.MsgGnssCapb _parent) {
            this(_io, _parent, null);
        }

        public GnssCapb(KaitaiStream _io, Observation.MsgGnssCapb _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.gpsActive = this._io.readU8le();
            this.gpsL2c = this._io.readU8le();
            this.gpsL5 = this._io.readU8le();
            this.gloActive = this._io.readU4le();
            this.gloL2of = this._io.readU4le();
            this.gloL3 = this._io.readU4le();
            this.sbasActive = this._io.readU8le();
            this.sbasL5 = this._io.readU8le();
            this.bdsActive = this._io.readU8le();
            this.bdsD2nav = this._io.readU8le();
            this.bdsB2 = this._io.readU8le();
            this.bdsB2a = this._io.readU8le();
            this.qzssActive = this._io.readU4le();
            this.galActive = this._io.readU8le();
            this.galE5 = this._io.readU8le();
        }
        private long gpsActive;
        private long gpsL2c;
        private long gpsL5;
        private long gloActive;
        private long gloL2of;
        private long gloL3;
        private long sbasActive;
        private long sbasL5;
        private long bdsActive;
        private long bdsD2nav;
        private long bdsB2;
        private long bdsB2a;
        private long qzssActive;
        private long galActive;
        private long galE5;
        private Observation _root;
        private Observation.MsgGnssCapb _parent;

        /**
         * GPS SV active mask
         */
        public long gpsActive() { return gpsActive; }

        /**
         * GPS L2C active mask
         */
        public long gpsL2c() { return gpsL2c; }

        /**
         * GPS L5 active mask
         */
        public long gpsL5() { return gpsL5; }

        /**
         * GLO active mask
         */
        public long gloActive() { return gloActive; }

        /**
         * GLO L2OF active mask
         */
        public long gloL2of() { return gloL2of; }

        /**
         * GLO L3 active mask
         */
        public long gloL3() { return gloL3; }

        /**
         * SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
         * https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
         */
        public long sbasActive() { return sbasActive; }

        /**
         * SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
         * https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
         */
        public long sbasL5() { return sbasL5; }

        /**
         * BDS active mask
         */
        public long bdsActive() { return bdsActive; }

        /**
         * BDS D2NAV active mask
         */
        public long bdsD2nav() { return bdsD2nav; }

        /**
         * BDS B2 active mask
         */
        public long bdsB2() { return bdsB2; }

        /**
         * BDS B2A active mask
         */
        public long bdsB2a() { return bdsB2a; }

        /**
         * QZSS active mask
         */
        public long qzssActive() { return qzssActive; }

        /**
         * GAL active mask
         */
        public long galActive() { return galActive; }

        /**
         * GAL E5 active mask
         */
        public long galE5() { return galE5; }
        public Observation _root() { return _root; }
        public Observation.MsgGnssCapb _parent() { return _parent; }
    }

    /**
     * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
     */
    public static class MsgGroupDelayDepB extends KaitaiStruct {
        public static MsgGroupDelayDepB fromFile(String fileName) throws IOException {
            return new MsgGroupDelayDepB(new ByteBufferKaitaiStream(fileName));
        }

        public MsgGroupDelayDepB(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgGroupDelayDepB(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgGroupDelayDepB(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tOp = new Gnss.GpsTimeSec(this._io, this, _root);
            this.sid = new Gnss.GnssSignalDep(this._io, this, _root);
            this.valid = this._io.readU1();
            this.tgd = this._io.readS2le();
            this.iscL1ca = this._io.readS2le();
            this.iscL2c = this._io.readS2le();
        }
        private Gnss.GpsTimeSec tOp;
        private Gnss.GnssSignalDep sid;
        private int valid;
        private short tgd;
        private short iscL1ca;
        private short iscL2c;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Data Predict Time of Week
         */
        public Gnss.GpsTimeSec tOp() { return tOp; }

        /**
         * GNSS signal identifier
         */
        public Gnss.GnssSignalDep sid() { return sid; }

        /**
         * bit-field indicating validity of the values, LSB indicating tgd
         * validity etc. 1 = value is valid, 0 = value is not valid.
         */
        public int valid() { return valid; }
        public short tgd() { return tgd; }
        public short iscL1ca() { return iscL1ca; }
        public short iscL2c() { return iscL2c; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Header of a GPS observation message.
     */
    public static class ObservationHeaderDep extends KaitaiStruct {
        public static ObservationHeaderDep fromFile(String fileName) throws IOException {
            return new ObservationHeaderDep(new ByteBufferKaitaiStream(fileName));
        }

        public ObservationHeaderDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public ObservationHeaderDep(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public ObservationHeaderDep(KaitaiStream _io, KaitaiStruct _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.t = new Gnss.GpsTimeDep(this._io, this, _root);
            this.nObs = this._io.readU1();
        }
        private Gnss.GpsTimeDep t;
        private int nObs;
        private Observation _root;
        private KaitaiStruct _parent;

        /**
         * GPS time of this observation
         */
        public Gnss.GpsTimeDep t() { return t; }

        /**
         * Total number of observations. First nibble is the size of the
         * sequence (n), second nibble is the zero-indexed counter (ith packet
         * of n)
         */
        public int nObs() { return nObs; }
        public Observation _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }
    public static class AlmanacCommonContentDep extends KaitaiStruct {
        public static AlmanacCommonContentDep fromFile(String fileName) throws IOException {
            return new AlmanacCommonContentDep(new ByteBufferKaitaiStream(fileName));
        }

        public AlmanacCommonContentDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public AlmanacCommonContentDep(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public AlmanacCommonContentDep(KaitaiStream _io, KaitaiStruct _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sid = new Gnss.GnssSignalDep(this._io, this, _root);
            this.toa = new Gnss.GpsTimeSec(this._io, this, _root);
            this.ura = this._io.readF8le();
            this.fitInterval = this._io.readU4le();
            this.valid = this._io.readU1();
            this.healthBits = this._io.readU1();
        }
        private Gnss.GnssSignalDep sid;
        private Gnss.GpsTimeSec toa;
        private double ura;
        private long fitInterval;
        private int valid;
        private int healthBits;
        private Observation _root;
        private KaitaiStruct _parent;

        /**
         * GNSS signal identifier
         */
        public Gnss.GnssSignalDep sid() { return sid; }

        /**
         * Reference time of almanac
         */
        public Gnss.GpsTimeSec toa() { return toa; }

        /**
         * User Range Accuracy
         */
        public double ura() { return ura; }

        /**
         * Curve fit interval
         */
        public long fitInterval() { return fitInterval; }

        /**
         * Status of almanac, 1 = valid, 0 = invalid
         */
        public int valid() { return valid; }

        /**
         * Satellite health status for GPS:
         *   - bits 5-7: NAV data health status. See IS-GPS-200H
         *     Table 20-VII: NAV Data Health Indications.
         *   - bits 0-4: Signal health status. See IS-GPS-200H
         *     Table 20-VIII. Codes for Health of SV Signal
         *     Components.
         * Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
         * details):
         *   - bit 0: C(n), "unhealthy" flag that is transmitted within
         *     non-immediate data and indicates overall constellation status
         *     at the moment of almanac uploading.
         *     '0' indicates malfunction of n-satellite.
         *     '1' indicates that n-satellite is operational.
         *   - bit 1: Bn(ln), '0' indicates the satellite is operational
         *     and suitable for navigation.
         */
        public int healthBits() { return healthBits; }
        public Observation _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }
    public static class EphemerisCommonContentDepA extends KaitaiStruct {
        public static EphemerisCommonContentDepA fromFile(String fileName) throws IOException {
            return new EphemerisCommonContentDepA(new ByteBufferKaitaiStream(fileName));
        }

        public EphemerisCommonContentDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public EphemerisCommonContentDepA(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public EphemerisCommonContentDepA(KaitaiStream _io, KaitaiStruct _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sid = new Gnss.GnssSignalDep(this._io, this, _root);
            this.toe = new Gnss.GpsTimeDep(this._io, this, _root);
            this.ura = this._io.readF8le();
            this.fitInterval = this._io.readU4le();
            this.valid = this._io.readU1();
            this.healthBits = this._io.readU1();
        }
        private Gnss.GnssSignalDep sid;
        private Gnss.GpsTimeDep toe;
        private double ura;
        private long fitInterval;
        private int valid;
        private int healthBits;
        private Observation _root;
        private KaitaiStruct _parent;

        /**
         * GNSS signal identifier
         */
        public Gnss.GnssSignalDep sid() { return sid; }

        /**
         * Time of Ephemerides
         */
        public Gnss.GpsTimeDep toe() { return toe; }

        /**
         * User Range Accuracy
         */
        public double ura() { return ura; }

        /**
         * Curve fit interval
         */
        public long fitInterval() { return fitInterval; }

        /**
         * Status of ephemeris, 1 = valid, 0 = invalid
         */
        public int valid() { return valid; }

        /**
         * Satellite health status.
         * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
         * SBAS: 0 = valid, non-zero = invalid
         * GLO: 0 = valid, non-zero = invalid
         */
        public int healthBits() { return healthBits; }
        public Observation _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }
    public static class EphemerisCommonContent extends KaitaiStruct {
        public static EphemerisCommonContent fromFile(String fileName) throws IOException {
            return new EphemerisCommonContent(new ByteBufferKaitaiStream(fileName));
        }

        public EphemerisCommonContent(KaitaiStream _io) {
            this(_io, null, null);
        }

        public EphemerisCommonContent(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public EphemerisCommonContent(KaitaiStream _io, KaitaiStruct _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.toe = new Gnss.GpsTimeSec(this._io, this, _root);
            this.ura = this._io.readF4le();
            this.fitInterval = this._io.readU4le();
            this.valid = this._io.readU1();
            this.healthBits = this._io.readU1();
        }
        private Gnss.GnssSignal sid;
        private Gnss.GpsTimeSec toe;
        private float ura;
        private long fitInterval;
        private int valid;
        private int healthBits;
        private Observation _root;
        private KaitaiStruct _parent;

        /**
         * GNSS signal identifier (16 bit)
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * Time of Ephemerides
         */
        public Gnss.GpsTimeSec toe() { return toe; }

        /**
         * User Range Accuracy
         */
        public float ura() { return ura; }

        /**
         * Curve fit interval
         */
        public long fitInterval() { return fitInterval; }

        /**
         * Status of ephemeris, 1 = valid, 0 = invalid
         */
        public int valid() { return valid; }

        /**
         * Satellite health status.
         * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
         * SBAS: 0 = valid, non-zero = invalid
         * GLO: 0 = valid, non-zero = invalid
         */
        public int healthBits() { return healthBits; }
        public Observation _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * Pseudorange and carrier phase observation for a satellite being tracked.
     * The observations are be interoperable with 3rd party receivers and
     * conform with typical RTCMv3 GNSS observations.
     */
    public static class PackedObsContentDepC extends KaitaiStruct {
        public static PackedObsContentDepC fromFile(String fileName) throws IOException {
            return new PackedObsContentDepC(new ByteBufferKaitaiStream(fileName));
        }

        public PackedObsContentDepC(KaitaiStream _io) {
            this(_io, null, null);
        }

        public PackedObsContentDepC(KaitaiStream _io, Observation.MsgObsDepC _parent) {
            this(_io, _parent, null);
        }

        public PackedObsContentDepC(KaitaiStream _io, Observation.MsgObsDepC _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.p = this._io.readU4le();
            this.l = new Gnss.CarrierPhase(this._io, this, _root);
            this.cn0 = this._io.readU1();
            this.lock = this._io.readU2le();
            this.sid = new Gnss.GnssSignalDep(this._io, this, _root);
        }
        private long p;
        private Gnss.CarrierPhase l;
        private int cn0;
        private int lock;
        private Gnss.GnssSignalDep sid;
        private Observation _root;
        private Observation.MsgObsDepC _parent;

        /**
         * Pseudorange observation
         */
        public long p() { return p; }

        /**
         * Carrier phase observation with typical sign convention.
         */
        public Gnss.CarrierPhase l() { return l; }

        /**
         * Carrier-to-Noise density
         */
        public int cn0() { return cn0; }

        /**
         * Lock indicator. This value changes whenever a satellite signal has
         * lost and regained lock, indicating that the carrier phase ambiguity
         * may have changed.
         */
        public int lock() { return lock; }

        /**
         * GNSS signal identifier
         */
        public Gnss.GnssSignalDep sid() { return sid; }
        public Observation _root() { return _root; }
        public Observation.MsgObsDepC _parent() { return _parent; }
    }

    /**
     * This observation message has been deprecated in favor of ephemeris
     * message using floats for size reduction.
     */
    public static class MsgEphemerisGloDepD extends KaitaiStruct {
        public static MsgEphemerisGloDepD fromFile(String fileName) throws IOException {
            return new MsgEphemerisGloDepD(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisGloDepD(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisGloDepD(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisGloDepD(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new EphemerisCommonContentDepB(this._io, this, _root);
            this.gamma = this._io.readF8le();
            this.tau = this._io.readF8le();
            this.dTau = this._io.readF8le();
            this.pos = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.pos.add(this._io.readF8le());
            }
            this.vel = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.vel.add(this._io.readF8le());
            }
            this.acc = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.acc.add(this._io.readF8le());
            }
            this.fcn = this._io.readU1();
            this.iod = this._io.readU1();
        }
        private EphemerisCommonContentDepB common;
        private double gamma;
        private double tau;
        private double dTau;
        private ArrayList<Double> pos;
        private ArrayList<Double> vel;
        private ArrayList<Double> acc;
        private int fcn;
        private int iod;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all ephemeris types
         */
        public EphemerisCommonContentDepB common() { return common; }

        /**
         * Relative deviation of predicted carrier frequency from nominal
         */
        public double gamma() { return gamma; }

        /**
         * Correction to the SV time
         */
        public double tau() { return tau; }

        /**
         * Equipment delay between L1 and L2
         */
        public double dTau() { return dTau; }

        /**
         * Position of the SV at tb in PZ-90.02 coordinates system
         */
        public ArrayList<Double> pos() { return pos; }

        /**
         * Velocity vector of the SV at tb in PZ-90.02 coordinates system
         */
        public ArrayList<Double> vel() { return vel; }

        /**
         * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
         */
        public ArrayList<Double> acc() { return acc; }

        /**
         * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
         */
        public int fcn() { return fcn; }

        /**
         * Issue of data. Equal to the 7 bits of the immediate data word t_b
         */
        public int iod() { return iod; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class MsgObsDepA extends KaitaiStruct {
        public static MsgObsDepA fromFile(String fileName) throws IOException {
            return new MsgObsDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgObsDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgObsDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgObsDepA(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new ObservationHeaderDep(this._io, this, _root);
            this.obs = new ArrayList<PackedObsContentDepA>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.obs.add(new PackedObsContentDepA(this._io, this, _root));
                    i++;
                }
            }
        }
        private ObservationHeaderDep header;
        private ArrayList<PackedObsContentDepA> obs;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Header of a GPS observation message
         */
        public ObservationHeaderDep header() { return header; }

        /**
         * Pseudorange and carrier phase observation for a satellite being
         * tracked.
         */
        public ArrayList<PackedObsContentDepA> obs() { return obs; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class MsgEphemerisDepB extends KaitaiStruct {
        public static MsgEphemerisDepB fromFile(String fileName) throws IOException {
            return new MsgEphemerisDepB(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisDepB(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisDepB(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisDepB(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tgd = this._io.readF8le();
            this.cRs = this._io.readF8le();
            this.cRc = this._io.readF8le();
            this.cUc = this._io.readF8le();
            this.cUs = this._io.readF8le();
            this.cIc = this._io.readF8le();
            this.cIs = this._io.readF8le();
            this.dn = this._io.readF8le();
            this.m0 = this._io.readF8le();
            this.ecc = this._io.readF8le();
            this.sqrta = this._io.readF8le();
            this.omega0 = this._io.readF8le();
            this.omegadot = this._io.readF8le();
            this.w = this._io.readF8le();
            this.inc = this._io.readF8le();
            this.incDot = this._io.readF8le();
            this.af0 = this._io.readF8le();
            this.af1 = this._io.readF8le();
            this.af2 = this._io.readF8le();
            this.toeTow = this._io.readF8le();
            this.toeWn = this._io.readU2le();
            this.tocTow = this._io.readF8le();
            this.tocWn = this._io.readU2le();
            this.valid = this._io.readU1();
            this.healthy = this._io.readU1();
            this.prn = this._io.readU1();
            this.iode = this._io.readU1();
        }
        private double tgd;
        private double cRs;
        private double cRc;
        private double cUc;
        private double cUs;
        private double cIc;
        private double cIs;
        private double dn;
        private double m0;
        private double ecc;
        private double sqrta;
        private double omega0;
        private double omegadot;
        private double w;
        private double inc;
        private double incDot;
        private double af0;
        private double af1;
        private double af2;
        private double toeTow;
        private int toeWn;
        private double tocTow;
        private int tocWn;
        private int valid;
        private int healthy;
        private int prn;
        private int iode;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Group delay differential between L1 and L2
         */
        public double tgd() { return tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public double cRs() { return cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public double cRc() { return cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public double cUc() { return cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public double cUs() { return cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public double cIc() { return cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public double cIs() { return cIs; }

        /**
         * Mean motion difference
         */
        public double dn() { return dn; }

        /**
         * Mean anomaly at reference time
         */
        public double m0() { return m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public double ecc() { return ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public double sqrta() { return sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public double omega0() { return omega0; }

        /**
         * Rate of right ascension
         */
        public double omegadot() { return omegadot; }

        /**
         * Argument of perigee
         */
        public double w() { return w; }

        /**
         * Inclination
         */
        public double inc() { return inc; }

        /**
         * Inclination first derivative
         */
        public double incDot() { return incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public double af0() { return af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public double af1() { return af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public double af2() { return af2; }

        /**
         * Time of week
         */
        public double toeTow() { return toeTow; }

        /**
         * Week number
         */
        public int toeWn() { return toeWn; }

        /**
         * Clock reference time of week
         */
        public double tocTow() { return tocTow; }

        /**
         * Clock reference week number
         */
        public int tocWn() { return tocWn; }

        /**
         * Is valid?
         */
        public int valid() { return valid; }

        /**
         * Satellite is healthy?
         */
        public int healthy() { return healthy; }

        /**
         * PRN being tracked
         */
        public int prn() { return prn; }

        /**
         * Issue of ephemeris data
         */
        public int iode() { return iode; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The GPS observations message reports all the raw pseudorange and carrier
     * phase observations for the satellites being tracked by the device.
     * Carrier phase observation here is represented as a 40-bit fixed point
     * number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
     * fractional cycles). The observations are be interoperable with 3rd party
     * receivers and conform with typical RTCMv3 GNSS observations.
     */
    public static class MsgObs extends KaitaiStruct {
        public static MsgObs fromFile(String fileName) throws IOException {
            return new MsgObs(new ByteBufferKaitaiStream(fileName));
        }

        public MsgObs(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgObs(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgObs(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new ObservationHeader(this._io, this, _root);
            this.obs = new ArrayList<PackedObsContent>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.obs.add(new PackedObsContent(this._io, this, _root));
                    i++;
                }
            }
        }
        private ObservationHeader header;
        private ArrayList<PackedObsContent> obs;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Header of a GPS observation message
         */
        public ObservationHeader header() { return header; }

        /**
         * Pseudorange and carrier phase observation for a satellite being
         * tracked.
         */
        public ArrayList<PackedObsContent> obs() { return obs; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Doppler measurement in Hz represented as a 24-bit fixed point number
     * with Q16.8 layout, i.e. 16-bits of whole doppler and 8-bits of
     * fractional doppler. This doppler is defined as positive for approaching
     * satellites.
     */
    public static class Doppler extends KaitaiStruct {
        public static Doppler fromFile(String fileName) throws IOException {
            return new Doppler(new ByteBufferKaitaiStream(fileName));
        }

        public Doppler(KaitaiStream _io) {
            this(_io, null, null);
        }

        public Doppler(KaitaiStream _io, Observation.PackedObsContent _parent) {
            this(_io, _parent, null);
        }

        public Doppler(KaitaiStream _io, Observation.PackedObsContent _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.i = this._io.readS2le();
            this.f = this._io.readU1();
        }
        private short i;
        private int f;
        private Observation _root;
        private Observation.PackedObsContent _parent;

        /**
         * Doppler whole Hz
         */
        public short i() { return i; }

        /**
         * Doppler fractional part
         */
        public int f() { return f; }
        public Observation _root() { return _root; }
        public Observation.PackedObsContent _parent() { return _parent; }
    }

    /**
     * The almanac message returns a set of satellite orbit parameters. Almanac
     * data is not very precise and is considered valid for up to several
     * months. Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate
     * information and almanac" for details.
     */
    public static class MsgAlmanacGloDep extends KaitaiStruct {
        public static MsgAlmanacGloDep fromFile(String fileName) throws IOException {
            return new MsgAlmanacGloDep(new ByteBufferKaitaiStream(fileName));
        }

        public MsgAlmanacGloDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgAlmanacGloDep(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgAlmanacGloDep(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new AlmanacCommonContentDep(this._io, this, _root);
            this.lambdaNa = this._io.readF8le();
            this.tLambdaNa = this._io.readF8le();
            this.i = this._io.readF8le();
            this.t = this._io.readF8le();
            this.tDot = this._io.readF8le();
            this.epsilon = this._io.readF8le();
            this.omega = this._io.readF8le();
        }
        private AlmanacCommonContentDep common;
        private double lambdaNa;
        private double tLambdaNa;
        private double i;
        private double t;
        private double tDot;
        private double epsilon;
        private double omega;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all almanac types
         */
        public AlmanacCommonContentDep common() { return common; }

        /**
         * Longitude of the first ascending node of the orbit in PZ-90.02
         * coordinate system
         */
        public double lambdaNa() { return lambdaNa; }

        /**
         * Time of the first ascending node passage
         */
        public double tLambdaNa() { return tLambdaNa; }

        /**
         * Value of inclination at instant of t_lambda
         */
        public double i() { return i; }

        /**
         * Value of Draconian period at instant of t_lambda
         */
        public double t() { return t; }

        /**
         * Rate of change of the Draconian period
         */
        public double tDot() { return tDot; }

        /**
         * Eccentricity at instant of t_lambda
         */
        public double epsilon() { return epsilon; }

        /**
         * Argument of perigee at instant of t_lambda
         */
        public double omega() { return omega; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The almanac message returns a set of satellite orbit parameters. Almanac
     * data is not very precise and is considered valid for up to several
     * months. Please see the Navstar GPS Space Segment/Navigation user
     * interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
     * details.
     */
    public static class MsgAlmanacGpsDep extends KaitaiStruct {
        public static MsgAlmanacGpsDep fromFile(String fileName) throws IOException {
            return new MsgAlmanacGpsDep(new ByteBufferKaitaiStream(fileName));
        }

        public MsgAlmanacGpsDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgAlmanacGpsDep(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgAlmanacGpsDep(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new AlmanacCommonContentDep(this._io, this, _root);
            this.m0 = this._io.readF8le();
            this.ecc = this._io.readF8le();
            this.sqrta = this._io.readF8le();
            this.omega0 = this._io.readF8le();
            this.omegadot = this._io.readF8le();
            this.w = this._io.readF8le();
            this.inc = this._io.readF8le();
            this.af0 = this._io.readF8le();
            this.af1 = this._io.readF8le();
        }
        private AlmanacCommonContentDep common;
        private double m0;
        private double ecc;
        private double sqrta;
        private double omega0;
        private double omegadot;
        private double w;
        private double inc;
        private double af0;
        private double af1;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all almanac types
         */
        public AlmanacCommonContentDep common() { return common; }

        /**
         * Mean anomaly at reference time
         */
        public double m0() { return m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public double ecc() { return ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public double sqrta() { return sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public double omega0() { return omega0; }

        /**
         * Rate of right ascension
         */
        public double omegadot() { return omegadot; }

        /**
         * Argument of perigee
         */
        public double w() { return w; }

        /**
         * Inclination
         */
        public double inc() { return inc; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public double af0() { return af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public double af1() { return af1; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Satellite azimuth and elevation.
     */
    public static class SvAzEl extends KaitaiStruct {
        public static SvAzEl fromFile(String fileName) throws IOException {
            return new SvAzEl(new ByteBufferKaitaiStream(fileName));
        }

        public SvAzEl(KaitaiStream _io) {
            this(_io, null, null);
        }

        public SvAzEl(KaitaiStream _io, Observation.MsgSvAzEl _parent) {
            this(_io, _parent, null);
        }

        public SvAzEl(KaitaiStream _io, Observation.MsgSvAzEl _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.az = this._io.readU1();
            this.el = this._io.readS1();
        }
        private Gnss.GnssSignal sid;
        private int az;
        private byte el;
        private Observation _root;
        private Observation.MsgSvAzEl _parent;

        /**
         * GNSS signal identifier
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * Azimuth angle (range 0..179)
         */
        public int az() { return az; }

        /**
         * Elevation angle (range -90..90)
         */
        public byte el() { return el; }
        public Observation _root() { return _root; }
        public Observation.MsgSvAzEl _parent() { return _parent; }
    }

    /**
     * The GLONASS L1/L2 Code-Phase biases allows to perform GPS+GLONASS
     * integer ambiguity resolution for baselines with mixed receiver types
     * (e.g. receiver of different manufacturers).
     */
    public static class MsgGloBiases extends KaitaiStruct {
        public static MsgGloBiases fromFile(String fileName) throws IOException {
            return new MsgGloBiases(new ByteBufferKaitaiStream(fileName));
        }

        public MsgGloBiases(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgGloBiases(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgGloBiases(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.mask = this._io.readU1();
            this.l1caBias = this._io.readS2le();
            this.l1pBias = this._io.readS2le();
            this.l2caBias = this._io.readS2le();
            this.l2pBias = this._io.readS2le();
        }
        private int mask;
        private short l1caBias;
        private short l1pBias;
        private short l2caBias;
        private short l2pBias;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * GLONASS FDMA signals mask
         */
        public int mask() { return mask; }

        /**
         * GLONASS L1 C/A Code-Phase Bias
         */
        public short l1caBias() { return l1caBias; }

        /**
         * GLONASS L1 P Code-Phase Bias
         */
        public short l1pBias() { return l1pBias; }

        /**
         * GLONASS L2 C/A Code-Phase Bias
         */
        public short l2caBias() { return l2caBias; }

        /**
         * GLONASS L2 P Code-Phase Bias
         */
        public short l2pBias() { return l2pBias; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This observation message has been deprecated in favor of ephemeris
     * message using floats for size reduction.
     */
    public static class MsgEphemerisSbasDepB extends KaitaiStruct {
        public static MsgEphemerisSbasDepB fromFile(String fileName) throws IOException {
            return new MsgEphemerisSbasDepB(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisSbasDepB(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisSbasDepB(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisSbasDepB(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new EphemerisCommonContentDepB(this._io, this, _root);
            this.pos = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.pos.add(this._io.readF8le());
            }
            this.vel = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.vel.add(this._io.readF8le());
            }
            this.acc = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.acc.add(this._io.readF8le());
            }
            this.aGf0 = this._io.readF8le();
            this.aGf1 = this._io.readF8le();
        }
        private EphemerisCommonContentDepB common;
        private ArrayList<Double> pos;
        private ArrayList<Double> vel;
        private ArrayList<Double> acc;
        private double aGf0;
        private double aGf1;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all ephemeris types
         */
        public EphemerisCommonContentDepB common() { return common; }

        /**
         * Position of the GEO at time toe
         */
        public ArrayList<Double> pos() { return pos; }

        /**
         * Velocity of the GEO at time toe
         */
        public ArrayList<Double> vel() { return vel; }

        /**
         * Acceleration of the GEO at time toe
         */
        public ArrayList<Double> acc() { return acc; }

        /**
         * Time offset of the GEO clock w.r.t. SBAS Network Time
         */
        public double aGf0() { return aGf0; }

        /**
         * Drift of the GEO clock w.r.t. SBAS Network Time
         */
        public double aGf1() { return aGf1; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate GPS satellite position, velocity, and clock offset.
     * Please see the Navstar GPS Space Segment/Navigation user interfaces
     * (ICD-GPS-200, Table 20-III) for more details.
     */
    public static class MsgEphemerisGpsDepE extends KaitaiStruct {
        public static MsgEphemerisGpsDepE fromFile(String fileName) throws IOException {
            return new MsgEphemerisGpsDepE(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisGpsDepE(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisGpsDepE(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisGpsDepE(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new EphemerisCommonContentDepA(this._io, this, _root);
            this.tgd = this._io.readF8le();
            this.cRs = this._io.readF8le();
            this.cRc = this._io.readF8le();
            this.cUc = this._io.readF8le();
            this.cUs = this._io.readF8le();
            this.cIc = this._io.readF8le();
            this.cIs = this._io.readF8le();
            this.dn = this._io.readF8le();
            this.m0 = this._io.readF8le();
            this.ecc = this._io.readF8le();
            this.sqrta = this._io.readF8le();
            this.omega0 = this._io.readF8le();
            this.omegadot = this._io.readF8le();
            this.w = this._io.readF8le();
            this.inc = this._io.readF8le();
            this.incDot = this._io.readF8le();
            this.af0 = this._io.readF8le();
            this.af1 = this._io.readF8le();
            this.af2 = this._io.readF8le();
            this.toc = new Gnss.GpsTimeDep(this._io, this, _root);
            this.iode = this._io.readU1();
            this.iodc = this._io.readU2le();
        }
        private EphemerisCommonContentDepA common;
        private double tgd;
        private double cRs;
        private double cRc;
        private double cUc;
        private double cUs;
        private double cIc;
        private double cIs;
        private double dn;
        private double m0;
        private double ecc;
        private double sqrta;
        private double omega0;
        private double omegadot;
        private double w;
        private double inc;
        private double incDot;
        private double af0;
        private double af1;
        private double af2;
        private Gnss.GpsTimeDep toc;
        private int iode;
        private int iodc;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all ephemeris types
         */
        public EphemerisCommonContentDepA common() { return common; }

        /**
         * Group delay differential between L1 and L2
         */
        public double tgd() { return tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public double cRs() { return cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public double cRc() { return cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public double cUc() { return cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public double cUs() { return cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public double cIc() { return cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public double cIs() { return cIs; }

        /**
         * Mean motion difference
         */
        public double dn() { return dn; }

        /**
         * Mean anomaly at reference time
         */
        public double m0() { return m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public double ecc() { return ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public double sqrta() { return sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public double omega0() { return omega0; }

        /**
         * Rate of right ascension
         */
        public double omegadot() { return omegadot; }

        /**
         * Argument of perigee
         */
        public double w() { return w; }

        /**
         * Inclination
         */
        public double inc() { return inc; }

        /**
         * Inclination first derivative
         */
        public double incDot() { return incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public double af0() { return af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public double af1() { return af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public double af2() { return af2; }

        /**
         * Clock reference
         */
        public Gnss.GpsTimeDep toc() { return toc; }

        /**
         * Issue of ephemeris data
         */
        public int iode() { return iode; }

        /**
         * Issue of clock data
         */
        public int iodc() { return iodc; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class MsgGnssCapb extends KaitaiStruct {
        public static MsgGnssCapb fromFile(String fileName) throws IOException {
            return new MsgGnssCapb(new ByteBufferKaitaiStream(fileName));
        }

        public MsgGnssCapb(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgGnssCapb(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgGnssCapb(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tNmct = new Gnss.GpsTimeSec(this._io, this, _root);
            this.gc = new GnssCapb(this._io, this, _root);
        }
        private Gnss.GpsTimeSec tNmct;
        private GnssCapb gc;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Navigation Message Correction Table Validity Time
         */
        public Gnss.GpsTimeSec tNmct() { return tNmct; }

        /**
         * GNSS capabilities masks
         */
        public GnssCapb gc() { return gc; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The almanac message returns a set of satellite orbit parameters. Almanac
     * data is not very precise and is considered valid for up to several
     * months. Please see the Navstar GPS Space Segment/Navigation user
     * interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
     * details.
     */
    public static class MsgAlmanacGps extends KaitaiStruct {
        public static MsgAlmanacGps fromFile(String fileName) throws IOException {
            return new MsgAlmanacGps(new ByteBufferKaitaiStream(fileName));
        }

        public MsgAlmanacGps(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgAlmanacGps(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgAlmanacGps(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new AlmanacCommonContent(this._io, this, _root);
            this.m0 = this._io.readF8le();
            this.ecc = this._io.readF8le();
            this.sqrta = this._io.readF8le();
            this.omega0 = this._io.readF8le();
            this.omegadot = this._io.readF8le();
            this.w = this._io.readF8le();
            this.inc = this._io.readF8le();
            this.af0 = this._io.readF8le();
            this.af1 = this._io.readF8le();
        }
        private AlmanacCommonContent common;
        private double m0;
        private double ecc;
        private double sqrta;
        private double omega0;
        private double omegadot;
        private double w;
        private double inc;
        private double af0;
        private double af1;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all almanac types
         */
        public AlmanacCommonContent common() { return common; }

        /**
         * Mean anomaly at reference time
         */
        public double m0() { return m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public double ecc() { return ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public double sqrta() { return sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public double omega0() { return omega0; }

        /**
         * Rate of right ascension
         */
        public double omegadot() { return omegadot; }

        /**
         * Argument of perigee
         */
        public double w() { return w; }

        /**
         * Inclination
         */
        public double inc() { return inc; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public double af0() { return af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public double af1() { return af1; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate QZSS satellite position, velocity, and clock
     * offset.
     */
    public static class MsgEphemerisQzss extends KaitaiStruct {
        public static MsgEphemerisQzss fromFile(String fileName) throws IOException {
            return new MsgEphemerisQzss(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisQzss(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisQzss(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisQzss(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new EphemerisCommonContent(this._io, this, _root);
            this.tgd = this._io.readF4le();
            this.cRs = this._io.readF4le();
            this.cRc = this._io.readF4le();
            this.cUc = this._io.readF4le();
            this.cUs = this._io.readF4le();
            this.cIc = this._io.readF4le();
            this.cIs = this._io.readF4le();
            this.dn = this._io.readF8le();
            this.m0 = this._io.readF8le();
            this.ecc = this._io.readF8le();
            this.sqrta = this._io.readF8le();
            this.omega0 = this._io.readF8le();
            this.omegadot = this._io.readF8le();
            this.w = this._io.readF8le();
            this.inc = this._io.readF8le();
            this.incDot = this._io.readF8le();
            this.af0 = this._io.readF4le();
            this.af1 = this._io.readF4le();
            this.af2 = this._io.readF4le();
            this.toc = new Gnss.GpsTimeSec(this._io, this, _root);
            this.iode = this._io.readU1();
            this.iodc = this._io.readU2le();
        }
        private EphemerisCommonContent common;
        private float tgd;
        private float cRs;
        private float cRc;
        private float cUc;
        private float cUs;
        private float cIc;
        private float cIs;
        private double dn;
        private double m0;
        private double ecc;
        private double sqrta;
        private double omega0;
        private double omegadot;
        private double w;
        private double inc;
        private double incDot;
        private float af0;
        private float af1;
        private float af2;
        private Gnss.GpsTimeSec toc;
        private int iode;
        private int iodc;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all ephemeris types
         */
        public EphemerisCommonContent common() { return common; }

        /**
         * Group delay differential between L1 and L2
         */
        public float tgd() { return tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public float cRs() { return cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public float cRc() { return cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public float cUc() { return cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public float cUs() { return cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public float cIc() { return cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public float cIs() { return cIs; }

        /**
         * Mean motion difference
         */
        public double dn() { return dn; }

        /**
         * Mean anomaly at reference time
         */
        public double m0() { return m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public double ecc() { return ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public double sqrta() { return sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public double omega0() { return omega0; }

        /**
         * Rate of right ascension
         */
        public double omegadot() { return omegadot; }

        /**
         * Argument of perigee
         */
        public double w() { return w; }

        /**
         * Inclination
         */
        public double inc() { return inc; }

        /**
         * Inclination first derivative
         */
        public double incDot() { return incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public float af0() { return af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public float af1() { return af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public float af2() { return af2; }

        /**
         * Clock reference
         */
        public Gnss.GpsTimeSec toc() { return toc; }

        /**
         * Issue of ephemeris data
         */
        public int iode() { return iode; }

        /**
         * Issue of clock data
         */
        public int iodc() { return iodc; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
     */
    public static class MsgGroupDelayDepA extends KaitaiStruct {
        public static MsgGroupDelayDepA fromFile(String fileName) throws IOException {
            return new MsgGroupDelayDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgGroupDelayDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgGroupDelayDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgGroupDelayDepA(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tOp = new Gnss.GpsTimeDep(this._io, this, _root);
            this.prn = this._io.readU1();
            this.valid = this._io.readU1();
            this.tgd = this._io.readS2le();
            this.iscL1ca = this._io.readS2le();
            this.iscL2c = this._io.readS2le();
        }
        private Gnss.GpsTimeDep tOp;
        private int prn;
        private int valid;
        private short tgd;
        private short iscL1ca;
        private short iscL2c;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Data Predict Time of Week
         */
        public Gnss.GpsTimeDep tOp() { return tOp; }

        /**
         * Satellite number
         */
        public int prn() { return prn; }

        /**
         * bit-field indicating validity of the values, LSB indicating tgd
         * validity etc. 1 = value is valid, 0 = value is not valid.
         */
        public int valid() { return valid; }
        public short tgd() { return tgd; }
        public short iscL1ca() { return iscL1ca; }
        public short iscL2c() { return iscL2c; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate GPS satellite position, velocity, and clock offset.
     * Please see the Navstar GPS Space Segment/Navigation user interfaces
     * (ICD-GPS-200, Table 20-III) for more details.
     */
    public static class MsgEphemerisDepC extends KaitaiStruct {
        public static MsgEphemerisDepC fromFile(String fileName) throws IOException {
            return new MsgEphemerisDepC(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisDepC(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisDepC(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisDepC(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tgd = this._io.readF8le();
            this.cRs = this._io.readF8le();
            this.cRc = this._io.readF8le();
            this.cUc = this._io.readF8le();
            this.cUs = this._io.readF8le();
            this.cIc = this._io.readF8le();
            this.cIs = this._io.readF8le();
            this.dn = this._io.readF8le();
            this.m0 = this._io.readF8le();
            this.ecc = this._io.readF8le();
            this.sqrta = this._io.readF8le();
            this.omega0 = this._io.readF8le();
            this.omegadot = this._io.readF8le();
            this.w = this._io.readF8le();
            this.inc = this._io.readF8le();
            this.incDot = this._io.readF8le();
            this.af0 = this._io.readF8le();
            this.af1 = this._io.readF8le();
            this.af2 = this._io.readF8le();
            this.toeTow = this._io.readF8le();
            this.toeWn = this._io.readU2le();
            this.tocTow = this._io.readF8le();
            this.tocWn = this._io.readU2le();
            this.valid = this._io.readU1();
            this.healthy = this._io.readU1();
            this.sid = new Gnss.GnssSignalDep(this._io, this, _root);
            this.iode = this._io.readU1();
            this.iodc = this._io.readU2le();
            this.reserved = this._io.readU4le();
        }
        private double tgd;
        private double cRs;
        private double cRc;
        private double cUc;
        private double cUs;
        private double cIc;
        private double cIs;
        private double dn;
        private double m0;
        private double ecc;
        private double sqrta;
        private double omega0;
        private double omegadot;
        private double w;
        private double inc;
        private double incDot;
        private double af0;
        private double af1;
        private double af2;
        private double toeTow;
        private int toeWn;
        private double tocTow;
        private int tocWn;
        private int valid;
        private int healthy;
        private Gnss.GnssSignalDep sid;
        private int iode;
        private int iodc;
        private long reserved;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Group delay differential between L1 and L2
         */
        public double tgd() { return tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public double cRs() { return cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public double cRc() { return cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public double cUc() { return cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public double cUs() { return cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public double cIc() { return cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public double cIs() { return cIs; }

        /**
         * Mean motion difference
         */
        public double dn() { return dn; }

        /**
         * Mean anomaly at reference time
         */
        public double m0() { return m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public double ecc() { return ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public double sqrta() { return sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public double omega0() { return omega0; }

        /**
         * Rate of right ascension
         */
        public double omegadot() { return omegadot; }

        /**
         * Argument of perigee
         */
        public double w() { return w; }

        /**
         * Inclination
         */
        public double inc() { return inc; }

        /**
         * Inclination first derivative
         */
        public double incDot() { return incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public double af0() { return af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public double af1() { return af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public double af2() { return af2; }

        /**
         * Time of week
         */
        public double toeTow() { return toeTow; }

        /**
         * Week number
         */
        public int toeWn() { return toeWn; }

        /**
         * Clock reference time of week
         */
        public double tocTow() { return tocTow; }

        /**
         * Clock reference week number
         */
        public int tocWn() { return tocWn; }

        /**
         * Is valid?
         */
        public int valid() { return valid; }

        /**
         * Satellite is healthy?
         */
        public int healthy() { return healthy; }

        /**
         * GNSS signal identifier
         */
        public Gnss.GnssSignalDep sid() { return sid; }

        /**
         * Issue of ephemeris data
         */
        public int iode() { return iode; }

        /**
         * Issue of clock data
         */
        public int iodc() { return iodc; }

        /**
         * Reserved field
         */
        public long reserved() { return reserved; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Carrier phase measurement in cycles represented as a 40-bit fixed point
     * number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
     * fractional cycles. This has the opposite sign convention than a typical
     * GPS receiver and the phase has the opposite sign as the pseudorange.
     */
    public static class CarrierPhaseDepA extends KaitaiStruct {
        public static CarrierPhaseDepA fromFile(String fileName) throws IOException {
            return new CarrierPhaseDepA(new ByteBufferKaitaiStream(fileName));
        }

        public CarrierPhaseDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public CarrierPhaseDepA(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public CarrierPhaseDepA(KaitaiStream _io, KaitaiStruct _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.i = this._io.readS4le();
            this.f = this._io.readU1();
        }
        private int i;
        private int f;
        private Observation _root;
        private KaitaiStruct _parent;

        /**
         * Carrier phase whole cycles
         */
        public int i() { return i; }

        /**
         * Carrier phase fractional part
         */
        public int f() { return f; }
        public Observation _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate Galileo satellite position, velocity, and clock
     * offset. Please see the Signal In Space ICD OS SIS ICD, Issue 1.3,
     * December 2016 for more details.
     */
    public static class MsgEphemerisGal extends KaitaiStruct {
        public static MsgEphemerisGal fromFile(String fileName) throws IOException {
            return new MsgEphemerisGal(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisGal(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisGal(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisGal(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new EphemerisCommonContent(this._io, this, _root);
            this.bgdE1e5a = this._io.readF4le();
            this.bgdE1e5b = this._io.readF4le();
            this.cRs = this._io.readF4le();
            this.cRc = this._io.readF4le();
            this.cUc = this._io.readF4le();
            this.cUs = this._io.readF4le();
            this.cIc = this._io.readF4le();
            this.cIs = this._io.readF4le();
            this.dn = this._io.readF8le();
            this.m0 = this._io.readF8le();
            this.ecc = this._io.readF8le();
            this.sqrta = this._io.readF8le();
            this.omega0 = this._io.readF8le();
            this.omegadot = this._io.readF8le();
            this.w = this._io.readF8le();
            this.inc = this._io.readF8le();
            this.incDot = this._io.readF8le();
            this.af0 = this._io.readF8le();
            this.af1 = this._io.readF8le();
            this.af2 = this._io.readF4le();
            this.toc = new Gnss.GpsTimeSec(this._io, this, _root);
            this.iode = this._io.readU2le();
            this.iodc = this._io.readU2le();
            this.source = this._io.readU1();
        }
        private EphemerisCommonContent common;
        private float bgdE1e5a;
        private float bgdE1e5b;
        private float cRs;
        private float cRc;
        private float cUc;
        private float cUs;
        private float cIc;
        private float cIs;
        private double dn;
        private double m0;
        private double ecc;
        private double sqrta;
        private double omega0;
        private double omegadot;
        private double w;
        private double inc;
        private double incDot;
        private double af0;
        private double af1;
        private float af2;
        private Gnss.GpsTimeSec toc;
        private int iode;
        private int iodc;
        private int source;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all ephemeris types
         */
        public EphemerisCommonContent common() { return common; }

        /**
         * E1-E5a Broadcast Group Delay
         */
        public float bgdE1e5a() { return bgdE1e5a; }

        /**
         * E1-E5b Broadcast Group Delay
         */
        public float bgdE1e5b() { return bgdE1e5b; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public float cRs() { return cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public float cRc() { return cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public float cUc() { return cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public float cUs() { return cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public float cIc() { return cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public float cIs() { return cIs; }

        /**
         * Mean motion difference
         */
        public double dn() { return dn; }

        /**
         * Mean anomaly at reference time
         */
        public double m0() { return m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public double ecc() { return ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public double sqrta() { return sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public double omega0() { return omega0; }

        /**
         * Rate of right ascension
         */
        public double omegadot() { return omegadot; }

        /**
         * Argument of perigee
         */
        public double w() { return w; }

        /**
         * Inclination
         */
        public double inc() { return inc; }

        /**
         * Inclination first derivative
         */
        public double incDot() { return incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public double af0() { return af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public double af1() { return af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public float af2() { return af2; }

        /**
         * Clock reference
         */
        public Gnss.GpsTimeSec toc() { return toc; }

        /**
         * Issue of data (IODnav)
         */
        public int iode() { return iode; }

        /**
         * Issue of data (IODnav). Always equal to iode
         */
        public int iodc() { return iodc; }

        /**
         * 0=I/NAV, 1=F/NAV
         */
        public int source() { return source; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Pseudorange and carrier phase network corrections for a satellite
     * signal.
     */
    public static class PackedOsrContent extends KaitaiStruct {
        public static PackedOsrContent fromFile(String fileName) throws IOException {
            return new PackedOsrContent(new ByteBufferKaitaiStream(fileName));
        }

        public PackedOsrContent(KaitaiStream _io) {
            this(_io, null, null);
        }

        public PackedOsrContent(KaitaiStream _io, Observation.MsgOsr _parent) {
            this(_io, _parent, null);
        }

        public PackedOsrContent(KaitaiStream _io, Observation.MsgOsr _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.p = this._io.readU4le();
            this.l = new Gnss.CarrierPhase(this._io, this, _root);
            this.lock = this._io.readU1();
            this.flags = this._io.readU1();
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.ionoStd = this._io.readU2le();
            this.tropoStd = this._io.readU2le();
            this.rangeStd = this._io.readU2le();
        }
        private long p;
        private Gnss.CarrierPhase l;
        private int lock;
        private int flags;
        private Gnss.GnssSignal sid;
        private int ionoStd;
        private int tropoStd;
        private int rangeStd;
        private Observation _root;
        private Observation.MsgOsr _parent;

        /**
         * Pseudorange observation
         */
        public long p() { return p; }

        /**
         * Carrier phase observation with typical sign convention.
         */
        public Gnss.CarrierPhase l() { return l; }

        /**
         * Lock timer. This value gives an indication of the time for which a
         * signal has maintained continuous phase lock. Whenever a signal has
         * lost and regained lock, this value is reset to zero. It is encoded
         * according to DF402 from the RTCM 10403.2 Amendment 2 specification.
         * Valid values range from 0 to 15 and the most significant nibble is
         * reserved for future use.
         */
        public int lock() { return lock; }

        /**
         * Correction flags.
         */
        public int flags() { return flags; }

        /**
         * GNSS signal identifier (16 bit)
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * Slant ionospheric correction standard deviation
         */
        public int ionoStd() { return ionoStd; }

        /**
         * Slant tropospheric correction standard deviation
         */
        public int tropoStd() { return tropoStd; }

        /**
         * Orbit/clock/bias correction projected on range standard deviation
         */
        public int rangeStd() { return rangeStd; }
        public Observation _root() { return _root; }
        public Observation.MsgOsr _parent() { return _parent; }
    }

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate BDS satellite position, velocity, and clock offset.
     * Please see the BeiDou Navigation Satellite System SIS-ICD Version 2.1,
     * Table 5-9 for more details.
     */
    public static class MsgEphemerisBds extends KaitaiStruct {
        public static MsgEphemerisBds fromFile(String fileName) throws IOException {
            return new MsgEphemerisBds(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisBds(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisBds(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisBds(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new EphemerisCommonContent(this._io, this, _root);
            this.tgd1 = this._io.readF4le();
            this.tgd2 = this._io.readF4le();
            this.cRs = this._io.readF4le();
            this.cRc = this._io.readF4le();
            this.cUc = this._io.readF4le();
            this.cUs = this._io.readF4le();
            this.cIc = this._io.readF4le();
            this.cIs = this._io.readF4le();
            this.dn = this._io.readF8le();
            this.m0 = this._io.readF8le();
            this.ecc = this._io.readF8le();
            this.sqrta = this._io.readF8le();
            this.omega0 = this._io.readF8le();
            this.omegadot = this._io.readF8le();
            this.w = this._io.readF8le();
            this.inc = this._io.readF8le();
            this.incDot = this._io.readF8le();
            this.af0 = this._io.readF8le();
            this.af1 = this._io.readF4le();
            this.af2 = this._io.readF4le();
            this.toc = new Gnss.GpsTimeSec(this._io, this, _root);
            this.iode = this._io.readU1();
            this.iodc = this._io.readU2le();
        }
        private EphemerisCommonContent common;
        private float tgd1;
        private float tgd2;
        private float cRs;
        private float cRc;
        private float cUc;
        private float cUs;
        private float cIc;
        private float cIs;
        private double dn;
        private double m0;
        private double ecc;
        private double sqrta;
        private double omega0;
        private double omegadot;
        private double w;
        private double inc;
        private double incDot;
        private double af0;
        private float af1;
        private float af2;
        private Gnss.GpsTimeSec toc;
        private int iode;
        private int iodc;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all ephemeris types
         */
        public EphemerisCommonContent common() { return common; }

        /**
         * Group delay differential for B1
         */
        public float tgd1() { return tgd1; }

        /**
         * Group delay differential for B2
         */
        public float tgd2() { return tgd2; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public float cRs() { return cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public float cRc() { return cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public float cUc() { return cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public float cUs() { return cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public float cIc() { return cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public float cIs() { return cIs; }

        /**
         * Mean motion difference
         */
        public double dn() { return dn; }

        /**
         * Mean anomaly at reference time
         */
        public double m0() { return m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public double ecc() { return ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public double sqrta() { return sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public double omega0() { return omega0; }

        /**
         * Rate of right ascension
         */
        public double omegadot() { return omegadot; }

        /**
         * Argument of perigee
         */
        public double w() { return w; }

        /**
         * Inclination
         */
        public double inc() { return inc; }

        /**
         * Inclination first derivative
         */
        public double incDot() { return incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public double af0() { return af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public float af1() { return af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public float af2() { return af2; }

        /**
         * Clock reference
         */
        public Gnss.GpsTimeSec toc() { return toc; }

        /**
         * Issue of ephemeris data
         * Calculated from the navigation data parameter t_oe per RTCM/CSNO
         * recommendation: IODE = mod (t_oe / 720, 240)
         */
        public int iode() { return iode; }

        /**
         * Issue of clock data
         * Calculated from the navigation data parameter t_oe per RTCM/CSNO
         * recommendation: IODE = mod (t_oc / 720, 240)
         */
        public int iodc() { return iodc; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This observation message has been deprecated in favor of ephemeris
     * message using floats for size reduction.
     */
    public static class MsgEphemerisGpsDepF extends KaitaiStruct {
        public static MsgEphemerisGpsDepF fromFile(String fileName) throws IOException {
            return new MsgEphemerisGpsDepF(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisGpsDepF(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisGpsDepF(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisGpsDepF(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new EphemerisCommonContentDepB(this._io, this, _root);
            this.tgd = this._io.readF8le();
            this.cRs = this._io.readF8le();
            this.cRc = this._io.readF8le();
            this.cUc = this._io.readF8le();
            this.cUs = this._io.readF8le();
            this.cIc = this._io.readF8le();
            this.cIs = this._io.readF8le();
            this.dn = this._io.readF8le();
            this.m0 = this._io.readF8le();
            this.ecc = this._io.readF8le();
            this.sqrta = this._io.readF8le();
            this.omega0 = this._io.readF8le();
            this.omegadot = this._io.readF8le();
            this.w = this._io.readF8le();
            this.inc = this._io.readF8le();
            this.incDot = this._io.readF8le();
            this.af0 = this._io.readF8le();
            this.af1 = this._io.readF8le();
            this.af2 = this._io.readF8le();
            this.toc = new Gnss.GpsTimeSec(this._io, this, _root);
            this.iode = this._io.readU1();
            this.iodc = this._io.readU2le();
        }
        private EphemerisCommonContentDepB common;
        private double tgd;
        private double cRs;
        private double cRc;
        private double cUc;
        private double cUs;
        private double cIc;
        private double cIs;
        private double dn;
        private double m0;
        private double ecc;
        private double sqrta;
        private double omega0;
        private double omegadot;
        private double w;
        private double inc;
        private double incDot;
        private double af0;
        private double af1;
        private double af2;
        private Gnss.GpsTimeSec toc;
        private int iode;
        private int iodc;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all ephemeris types
         */
        public EphemerisCommonContentDepB common() { return common; }

        /**
         * Group delay differential between L1 and L2
         */
        public double tgd() { return tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public double cRs() { return cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public double cRc() { return cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public double cUc() { return cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public double cUs() { return cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public double cIc() { return cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public double cIs() { return cIs; }

        /**
         * Mean motion difference
         */
        public double dn() { return dn; }

        /**
         * Mean anomaly at reference time
         */
        public double m0() { return m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public double ecc() { return ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public double sqrta() { return sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public double omega0() { return omega0; }

        /**
         * Rate of right ascension
         */
        public double omegadot() { return omegadot; }

        /**
         * Argument of perigee
         */
        public double w() { return w; }

        /**
         * Inclination
         */
        public double inc() { return inc; }

        /**
         * Inclination first derivative
         */
        public double incDot() { return incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public double af0() { return af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public double af1() { return af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public double af2() { return af2; }

        /**
         * Clock reference
         */
        public Gnss.GpsTimeSec toc() { return toc; }

        /**
         * Issue of ephemeris data
         */
        public int iode() { return iode; }

        /**
         * Issue of clock data
         */
        public int iodc() { return iodc; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Header of a GNSS observation message.
     */
    public static class ObservationHeader extends KaitaiStruct {
        public static ObservationHeader fromFile(String fileName) throws IOException {
            return new ObservationHeader(new ByteBufferKaitaiStream(fileName));
        }

        public ObservationHeader(KaitaiStream _io) {
            this(_io, null, null);
        }

        public ObservationHeader(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public ObservationHeader(KaitaiStream _io, KaitaiStruct _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.t = new Gnss.GpsTime(this._io, this, _root);
            this.nObs = this._io.readU1();
        }
        private Gnss.GpsTime t;
        private int nObs;
        private Observation _root;
        private KaitaiStruct _parent;

        /**
         * GNSS time of this observation
         */
        public Gnss.GpsTime t() { return t; }

        /**
         * Total number of observations. First nibble is the size of the
         * sequence (n), second nibble is the zero-indexed counter (ith packet
         * of n)
         */
        public int nObs() { return nObs; }
        public Observation _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }
    public static class MsgEphemerisSbasDepA extends KaitaiStruct {
        public static MsgEphemerisSbasDepA fromFile(String fileName) throws IOException {
            return new MsgEphemerisSbasDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisSbasDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisSbasDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisSbasDepA(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new EphemerisCommonContentDepA(this._io, this, _root);
            this.pos = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.pos.add(this._io.readF8le());
            }
            this.vel = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.vel.add(this._io.readF8le());
            }
            this.acc = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.acc.add(this._io.readF8le());
            }
            this.aGf0 = this._io.readF8le();
            this.aGf1 = this._io.readF8le();
        }
        private EphemerisCommonContentDepA common;
        private ArrayList<Double> pos;
        private ArrayList<Double> vel;
        private ArrayList<Double> acc;
        private double aGf0;
        private double aGf1;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all ephemeris types
         */
        public EphemerisCommonContentDepA common() { return common; }

        /**
         * Position of the GEO at time toe
         */
        public ArrayList<Double> pos() { return pos; }

        /**
         * Velocity of the GEO at time toe
         */
        public ArrayList<Double> vel() { return vel; }

        /**
         * Acceleration of the GEO at time toe
         */
        public ArrayList<Double> acc() { return acc; }

        /**
         * Time offset of the GEO clock w.r.t. SBAS Network Time
         */
        public double aGf0() { return aGf0; }

        /**
         * Drift of the GEO clock w.r.t. SBAS Network Time
         */
        public double aGf1() { return aGf1; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Pseudorange and carrier phase observation for a satellite being tracked.
     * The observations are interoperable with 3rd party receivers and conform
     * with typical RTCM 3.1 message GPS/GLO observations.
     * 
     * Carrier phase observations are not guaranteed to be aligned to the RINEX
     * 3 or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are
     * currently performed.
     */
    public static class PackedObsContent extends KaitaiStruct {
        public static PackedObsContent fromFile(String fileName) throws IOException {
            return new PackedObsContent(new ByteBufferKaitaiStream(fileName));
        }

        public PackedObsContent(KaitaiStream _io) {
            this(_io, null, null);
        }

        public PackedObsContent(KaitaiStream _io, Observation.MsgObs _parent) {
            this(_io, _parent, null);
        }

        public PackedObsContent(KaitaiStream _io, Observation.MsgObs _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.p = this._io.readU4le();
            this.l = new Gnss.CarrierPhase(this._io, this, _root);
            this.d = new Doppler(this._io, this, _root);
            this.cn0 = this._io.readU1();
            this.lock = this._io.readU1();
            this.flags = this._io.readU1();
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
        }
        private long p;
        private Gnss.CarrierPhase l;
        private Doppler d;
        private int cn0;
        private int lock;
        private int flags;
        private Gnss.GnssSignal sid;
        private Observation _root;
        private Observation.MsgObs _parent;

        /**
         * Pseudorange observation
         */
        public long p() { return p; }

        /**
         * Carrier phase observation with typical sign convention.
         */
        public Gnss.CarrierPhase l() { return l; }

        /**
         * Doppler observation with typical sign convention.
         */
        public Doppler d() { return d; }

        /**
         * Carrier-to-Noise density.  Zero implies invalid cn0.
         */
        public int cn0() { return cn0; }

        /**
         * Lock timer. This value gives an indication of the time for which a
         * signal has maintained continuous phase lock. Whenever a signal has
         * lost and regained lock, this value is reset to zero. It is encoded
         * according to DF402 from the RTCM 10403.2 Amendment 2 specification.
         * Valid values range from 0 to 15 and the most significant nibble is
         * reserved for future use.
         */
        public int lock() { return lock; }

        /**
         * Measurement status flags. A bit field of flags providing the status
         * of this observation.  If this field is 0 it means only the Cn0
         * estimate for the signal is valid.
         */
        public int flags() { return flags; }

        /**
         * GNSS signal identifier (16 bit)
         */
        public Gnss.GnssSignal sid() { return sid; }
        public Observation _root() { return _root; }
        public Observation.MsgObs _parent() { return _parent; }
    }

    /**
     * The base station position message is the position reported by the base
     * station itself in absolute Earth Centered Earth Fixed coordinates. It is
     * used for pseudo-absolute RTK positioning, and is required to be a high-
     * accuracy surveyed location of the base station. Any error here will
     * result in an error in the pseudo-absolute position output.
     */
    public static class MsgBasePosEcef extends KaitaiStruct {
        public static MsgBasePosEcef fromFile(String fileName) throws IOException {
            return new MsgBasePosEcef(new ByteBufferKaitaiStream(fileName));
        }

        public MsgBasePosEcef(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgBasePosEcef(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgBasePosEcef(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.x = this._io.readF8le();
            this.y = this._io.readF8le();
            this.z = this._io.readF8le();
        }
        private double x;
        private double y;
        private double z;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * ECEF X coordinate
         */
        public double x() { return x; }

        /**
         * ECEF Y coordinate
         */
        public double y() { return y; }

        /**
         * ECEF Z coordinate
         */
        public double z() { return z; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate GLO satellite position, velocity, and clock offset.
     * Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
     * immediate information (ephemeris parameters)" for more details.
     */
    public static class MsgEphemerisGloDepA extends KaitaiStruct {
        public static MsgEphemerisGloDepA fromFile(String fileName) throws IOException {
            return new MsgEphemerisGloDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisGloDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisGloDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisGloDepA(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new EphemerisCommonContentDepA(this._io, this, _root);
            this.gamma = this._io.readF8le();
            this.tau = this._io.readF8le();
            this.pos = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.pos.add(this._io.readF8le());
            }
            this.vel = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.vel.add(this._io.readF8le());
            }
            this.acc = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.acc.add(this._io.readF8le());
            }
        }
        private EphemerisCommonContentDepA common;
        private double gamma;
        private double tau;
        private ArrayList<Double> pos;
        private ArrayList<Double> vel;
        private ArrayList<Double> acc;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all ephemeris types
         */
        public EphemerisCommonContentDepA common() { return common; }

        /**
         * Relative deviation of predicted carrier frequency from nominal
         */
        public double gamma() { return gamma; }

        /**
         * Correction to the SV time
         */
        public double tau() { return tau; }

        /**
         * Position of the SV at tb in PZ-90.02 coordinates system
         */
        public ArrayList<Double> pos() { return pos; }

        /**
         * Velocity vector of the SV at tb in PZ-90.02 coordinates system
         */
        public ArrayList<Double> vel() { return vel; }

        /**
         * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
         */
        public ArrayList<Double> acc() { return acc; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
     */
    public static class MsgGroupDelay extends KaitaiStruct {
        public static MsgGroupDelay fromFile(String fileName) throws IOException {
            return new MsgGroupDelay(new ByteBufferKaitaiStream(fileName));
        }

        public MsgGroupDelay(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgGroupDelay(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgGroupDelay(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tOp = new Gnss.GpsTimeSec(this._io, this, _root);
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.valid = this._io.readU1();
            this.tgd = this._io.readS2le();
            this.iscL1ca = this._io.readS2le();
            this.iscL2c = this._io.readS2le();
        }
        private Gnss.GpsTimeSec tOp;
        private Gnss.GnssSignal sid;
        private int valid;
        private short tgd;
        private short iscL1ca;
        private short iscL2c;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Data Predict Time of Week
         */
        public Gnss.GpsTimeSec tOp() { return tOp; }

        /**
         * GNSS signal identifier
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * bit-field indicating validity of the values, LSB indicating tgd
         * validity etc. 1 = value is valid, 0 = value is not valid.
         */
        public int valid() { return valid; }
        public short tgd() { return tgd; }
        public short iscL1ca() { return iscL1ca; }
        public short iscL2c() { return iscL2c; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The almanac message returns a set of satellite orbit parameters. Almanac
     * data is not very precise and is considered valid for up to several
     * months. Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate
     * information and almanac" for details.
     */
    public static class MsgAlmanacGlo extends KaitaiStruct {
        public static MsgAlmanacGlo fromFile(String fileName) throws IOException {
            return new MsgAlmanacGlo(new ByteBufferKaitaiStream(fileName));
        }

        public MsgAlmanacGlo(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgAlmanacGlo(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgAlmanacGlo(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new AlmanacCommonContent(this._io, this, _root);
            this.lambdaNa = this._io.readF8le();
            this.tLambdaNa = this._io.readF8le();
            this.i = this._io.readF8le();
            this.t = this._io.readF8le();
            this.tDot = this._io.readF8le();
            this.epsilon = this._io.readF8le();
            this.omega = this._io.readF8le();
        }
        private AlmanacCommonContent common;
        private double lambdaNa;
        private double tLambdaNa;
        private double i;
        private double t;
        private double tDot;
        private double epsilon;
        private double omega;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all almanac types
         */
        public AlmanacCommonContent common() { return common; }

        /**
         * Longitude of the first ascending node of the orbit in PZ-90.02
         * coordinate system
         */
        public double lambdaNa() { return lambdaNa; }

        /**
         * Time of the first ascending node passage
         */
        public double tLambdaNa() { return tLambdaNa; }

        /**
         * Value of inclination at instant of t_lambda
         */
        public double i() { return i; }

        /**
         * Value of Draconian period at instant of t_lambda
         */
        public double t() { return t; }

        /**
         * Rate of change of the Draconian period
         */
        public double tDot() { return tDot; }

        /**
         * Eccentricity at instant of t_lambda
         */
        public double epsilon() { return epsilon; }

        /**
         * Argument of perigee at instant of t_lambda
         */
        public double omega() { return omega; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This observation message has been deprecated in favor of an ephemeris
     * message with explicit source of NAV data.
     */
    public static class MsgEphemerisGalDepA extends KaitaiStruct {
        public static MsgEphemerisGalDepA fromFile(String fileName) throws IOException {
            return new MsgEphemerisGalDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisGalDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisGalDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisGalDepA(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new EphemerisCommonContent(this._io, this, _root);
            this.bgdE1e5a = this._io.readF4le();
            this.bgdE1e5b = this._io.readF4le();
            this.cRs = this._io.readF4le();
            this.cRc = this._io.readF4le();
            this.cUc = this._io.readF4le();
            this.cUs = this._io.readF4le();
            this.cIc = this._io.readF4le();
            this.cIs = this._io.readF4le();
            this.dn = this._io.readF8le();
            this.m0 = this._io.readF8le();
            this.ecc = this._io.readF8le();
            this.sqrta = this._io.readF8le();
            this.omega0 = this._io.readF8le();
            this.omegadot = this._io.readF8le();
            this.w = this._io.readF8le();
            this.inc = this._io.readF8le();
            this.incDot = this._io.readF8le();
            this.af0 = this._io.readF8le();
            this.af1 = this._io.readF8le();
            this.af2 = this._io.readF4le();
            this.toc = new Gnss.GpsTimeSec(this._io, this, _root);
            this.iode = this._io.readU2le();
            this.iodc = this._io.readU2le();
        }
        private EphemerisCommonContent common;
        private float bgdE1e5a;
        private float bgdE1e5b;
        private float cRs;
        private float cRc;
        private float cUc;
        private float cUs;
        private float cIc;
        private float cIs;
        private double dn;
        private double m0;
        private double ecc;
        private double sqrta;
        private double omega0;
        private double omegadot;
        private double w;
        private double inc;
        private double incDot;
        private double af0;
        private double af1;
        private float af2;
        private Gnss.GpsTimeSec toc;
        private int iode;
        private int iodc;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all ephemeris types
         */
        public EphemerisCommonContent common() { return common; }

        /**
         * E1-E5a Broadcast Group Delay
         */
        public float bgdE1e5a() { return bgdE1e5a; }

        /**
         * E1-E5b Broadcast Group Delay
         */
        public float bgdE1e5b() { return bgdE1e5b; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public float cRs() { return cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public float cRc() { return cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public float cUc() { return cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public float cUs() { return cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public float cIc() { return cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public float cIs() { return cIs; }

        /**
         * Mean motion difference
         */
        public double dn() { return dn; }

        /**
         * Mean anomaly at reference time
         */
        public double m0() { return m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public double ecc() { return ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public double sqrta() { return sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public double omega0() { return omega0; }

        /**
         * Rate of right ascension
         */
        public double omegadot() { return omegadot; }

        /**
         * Argument of perigee
         */
        public double w() { return w; }

        /**
         * Inclination
         */
        public double inc() { return inc; }

        /**
         * Inclination first derivative
         */
        public double incDot() { return incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public double af0() { return af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public double af1() { return af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public float af2() { return af2; }

        /**
         * Clock reference
         */
        public Gnss.GpsTimeSec toc() { return toc; }

        /**
         * Issue of data (IODnav)
         */
        public int iode() { return iode; }

        /**
         * Issue of data (IODnav). Always equal to iode
         */
        public int iodc() { return iodc; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This observation message has been deprecated in favor of observations
     * that are more interoperable. This message should be used for
     * observations referenced to a nominal pseudorange which are not
     * interoperable with most 3rd party GNSS receivers or typical RTCMv3
     * observations.
     */
    public static class MsgObsDepB extends KaitaiStruct {
        public static MsgObsDepB fromFile(String fileName) throws IOException {
            return new MsgObsDepB(new ByteBufferKaitaiStream(fileName));
        }

        public MsgObsDepB(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgObsDepB(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgObsDepB(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new ObservationHeaderDep(this._io, this, _root);
            this.obs = new ArrayList<PackedObsContentDepB>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.obs.add(new PackedObsContentDepB(this._io, this, _root));
                    i++;
                }
            }
        }
        private ObservationHeaderDep header;
        private ArrayList<PackedObsContentDepB> obs;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Header of a GPS observation message
         */
        public ObservationHeaderDep header() { return header; }

        /**
         * Pseudorange and carrier phase observation for a satellite being
         * tracked.
         */
        public ArrayList<PackedObsContentDepB> obs() { return obs; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class PackedObsContentDepA extends KaitaiStruct {
        public static PackedObsContentDepA fromFile(String fileName) throws IOException {
            return new PackedObsContentDepA(new ByteBufferKaitaiStream(fileName));
        }

        public PackedObsContentDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public PackedObsContentDepA(KaitaiStream _io, Observation.MsgObsDepA _parent) {
            this(_io, _parent, null);
        }

        public PackedObsContentDepA(KaitaiStream _io, Observation.MsgObsDepA _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.p = this._io.readU4le();
            this.l = new CarrierPhaseDepA(this._io, this, _root);
            this.cn0 = this._io.readU1();
            this.lock = this._io.readU2le();
            this.prn = this._io.readU1();
        }
        private long p;
        private CarrierPhaseDepA l;
        private int cn0;
        private int lock;
        private int prn;
        private Observation _root;
        private Observation.MsgObsDepA _parent;

        /**
         * Pseudorange observation
         */
        public long p() { return p; }

        /**
         * Carrier phase observation with opposite sign from typical convention
         */
        public CarrierPhaseDepA l() { return l; }

        /**
         * Carrier-to-Noise density
         */
        public int cn0() { return cn0; }

        /**
         * Lock indicator. This value changes whenever a satellite signal has
         * lost and regained lock, indicating that the carrier phase ambiguity
         * may have changed.
         */
        public int lock() { return lock; }

        /**
         * PRN-1 identifier of the satellite signal
         */
        public int prn() { return prn; }
        public Observation _root() { return _root; }
        public Observation.MsgObsDepA _parent() { return _parent; }
    }

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate GLO satellite position, velocity, and clock offset.
     * Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
     * immediate information (ephemeris parameters)" for more details.
     */
    public static class MsgEphemerisGlo extends KaitaiStruct {
        public static MsgEphemerisGlo fromFile(String fileName) throws IOException {
            return new MsgEphemerisGlo(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisGlo(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisGlo(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisGlo(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new EphemerisCommonContent(this._io, this, _root);
            this.gamma = this._io.readF4le();
            this.tau = this._io.readF4le();
            this.dTau = this._io.readF4le();
            this.pos = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.pos.add(this._io.readF8le());
            }
            this.vel = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.vel.add(this._io.readF8le());
            }
            this.acc = new ArrayList<Float>();
            for (int i = 0; i < 3; i++) {
                this.acc.add(this._io.readF4le());
            }
            this.fcn = this._io.readU1();
            this.iod = this._io.readU1();
        }
        private EphemerisCommonContent common;
        private float gamma;
        private float tau;
        private float dTau;
        private ArrayList<Double> pos;
        private ArrayList<Double> vel;
        private ArrayList<Float> acc;
        private int fcn;
        private int iod;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all ephemeris types
         */
        public EphemerisCommonContent common() { return common; }

        /**
         * Relative deviation of predicted carrier frequency from nominal
         */
        public float gamma() { return gamma; }

        /**
         * Correction to the SV time
         */
        public float tau() { return tau; }

        /**
         * Equipment delay between L1 and L2
         */
        public float dTau() { return dTau; }

        /**
         * Position of the SV at tb in PZ-90.02 coordinates system
         */
        public ArrayList<Double> pos() { return pos; }

        /**
         * Velocity vector of the SV at tb in PZ-90.02 coordinates system
         */
        public ArrayList<Double> vel() { return vel; }

        /**
         * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
         */
        public ArrayList<Float> acc() { return acc; }

        /**
         * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
         */
        public int fcn() { return fcn; }

        /**
         * Issue of data. Equal to the 7 bits of the immediate data word t_b
         */
        public int iod() { return iod; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The ionospheric parameters which allow the "L1 only" or "L2 only" user
     * to utilize the ionospheric model for computation of the ionospheric
     * delay. Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
     */
    public static class MsgIono extends KaitaiStruct {
        public static MsgIono fromFile(String fileName) throws IOException {
            return new MsgIono(new ByteBufferKaitaiStream(fileName));
        }

        public MsgIono(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgIono(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgIono(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tNmct = new Gnss.GpsTimeSec(this._io, this, _root);
            this.a0 = this._io.readF8le();
            this.a1 = this._io.readF8le();
            this.a2 = this._io.readF8le();
            this.a3 = this._io.readF8le();
            this.b0 = this._io.readF8le();
            this.b1 = this._io.readF8le();
            this.b2 = this._io.readF8le();
            this.b3 = this._io.readF8le();
        }
        private Gnss.GpsTimeSec tNmct;
        private double a0;
        private double a1;
        private double a2;
        private double a3;
        private double b0;
        private double b1;
        private double b2;
        private double b3;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Navigation Message Correction Table Validity Time
         */
        public Gnss.GpsTimeSec tNmct() { return tNmct; }
        public double a0() { return a0; }
        public double a1() { return a1; }
        public double a2() { return a2; }
        public double a3() { return a3; }
        public double b0() { return b0; }
        public double b1() { return b1; }
        public double b2() { return b2; }
        public double b3() { return b3; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate GPS satellite position, velocity, and clock offset.
     * Please see the Navstar GPS Space Segment/Navigation user interfaces
     * (ICD-GPS-200, Table 20-III) for more details.
     */
    public static class MsgEphemerisDepD extends KaitaiStruct {
        public static MsgEphemerisDepD fromFile(String fileName) throws IOException {
            return new MsgEphemerisDepD(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisDepD(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisDepD(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisDepD(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tgd = this._io.readF8le();
            this.cRs = this._io.readF8le();
            this.cRc = this._io.readF8le();
            this.cUc = this._io.readF8le();
            this.cUs = this._io.readF8le();
            this.cIc = this._io.readF8le();
            this.cIs = this._io.readF8le();
            this.dn = this._io.readF8le();
            this.m0 = this._io.readF8le();
            this.ecc = this._io.readF8le();
            this.sqrta = this._io.readF8le();
            this.omega0 = this._io.readF8le();
            this.omegadot = this._io.readF8le();
            this.w = this._io.readF8le();
            this.inc = this._io.readF8le();
            this.incDot = this._io.readF8le();
            this.af0 = this._io.readF8le();
            this.af1 = this._io.readF8le();
            this.af2 = this._io.readF8le();
            this.toeTow = this._io.readF8le();
            this.toeWn = this._io.readU2le();
            this.tocTow = this._io.readF8le();
            this.tocWn = this._io.readU2le();
            this.valid = this._io.readU1();
            this.healthy = this._io.readU1();
            this.sid = new Gnss.GnssSignalDep(this._io, this, _root);
            this.iode = this._io.readU1();
            this.iodc = this._io.readU2le();
            this.reserved = this._io.readU4le();
        }
        private double tgd;
        private double cRs;
        private double cRc;
        private double cUc;
        private double cUs;
        private double cIc;
        private double cIs;
        private double dn;
        private double m0;
        private double ecc;
        private double sqrta;
        private double omega0;
        private double omegadot;
        private double w;
        private double inc;
        private double incDot;
        private double af0;
        private double af1;
        private double af2;
        private double toeTow;
        private int toeWn;
        private double tocTow;
        private int tocWn;
        private int valid;
        private int healthy;
        private Gnss.GnssSignalDep sid;
        private int iode;
        private int iodc;
        private long reserved;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Group delay differential between L1 and L2
         */
        public double tgd() { return tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public double cRs() { return cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public double cRc() { return cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public double cUc() { return cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public double cUs() { return cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public double cIc() { return cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public double cIs() { return cIs; }

        /**
         * Mean motion difference
         */
        public double dn() { return dn; }

        /**
         * Mean anomaly at reference time
         */
        public double m0() { return m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public double ecc() { return ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public double sqrta() { return sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public double omega0() { return omega0; }

        /**
         * Rate of right ascension
         */
        public double omegadot() { return omegadot; }

        /**
         * Argument of perigee
         */
        public double w() { return w; }

        /**
         * Inclination
         */
        public double inc() { return inc; }

        /**
         * Inclination first derivative
         */
        public double incDot() { return incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public double af0() { return af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public double af1() { return af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public double af2() { return af2; }

        /**
         * Time of week
         */
        public double toeTow() { return toeTow; }

        /**
         * Week number
         */
        public int toeWn() { return toeWn; }

        /**
         * Clock reference time of week
         */
        public double tocTow() { return tocTow; }

        /**
         * Clock reference week number
         */
        public int tocWn() { return tocWn; }

        /**
         * Is valid?
         */
        public int valid() { return valid; }

        /**
         * Satellite is healthy?
         */
        public int healthy() { return healthy; }

        /**
         * GNSS signal identifier
         */
        public Gnss.GnssSignalDep sid() { return sid; }

        /**
         * Issue of ephemeris data
         */
        public int iode() { return iode; }

        /**
         * Issue of clock data
         */
        public int iodc() { return iodc; }

        /**
         * Reserved field
         */
        public long reserved() { return reserved; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate GPS satellite position, velocity, and clock offset.
     * Please see the Navstar GPS Space Segment/Navigation user interfaces
     * (ICD-GPS-200, Table 20-III) for more details.
     */
    public static class MsgEphemerisGps extends KaitaiStruct {
        public static MsgEphemerisGps fromFile(String fileName) throws IOException {
            return new MsgEphemerisGps(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisGps(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisGps(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisGps(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new EphemerisCommonContent(this._io, this, _root);
            this.tgd = this._io.readF4le();
            this.cRs = this._io.readF4le();
            this.cRc = this._io.readF4le();
            this.cUc = this._io.readF4le();
            this.cUs = this._io.readF4le();
            this.cIc = this._io.readF4le();
            this.cIs = this._io.readF4le();
            this.dn = this._io.readF8le();
            this.m0 = this._io.readF8le();
            this.ecc = this._io.readF8le();
            this.sqrta = this._io.readF8le();
            this.omega0 = this._io.readF8le();
            this.omegadot = this._io.readF8le();
            this.w = this._io.readF8le();
            this.inc = this._io.readF8le();
            this.incDot = this._io.readF8le();
            this.af0 = this._io.readF4le();
            this.af1 = this._io.readF4le();
            this.af2 = this._io.readF4le();
            this.toc = new Gnss.GpsTimeSec(this._io, this, _root);
            this.iode = this._io.readU1();
            this.iodc = this._io.readU2le();
        }
        private EphemerisCommonContent common;
        private float tgd;
        private float cRs;
        private float cRc;
        private float cUc;
        private float cUs;
        private float cIc;
        private float cIs;
        private double dn;
        private double m0;
        private double ecc;
        private double sqrta;
        private double omega0;
        private double omegadot;
        private double w;
        private double inc;
        private double incDot;
        private float af0;
        private float af1;
        private float af2;
        private Gnss.GpsTimeSec toc;
        private int iode;
        private int iodc;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all ephemeris types
         */
        public EphemerisCommonContent common() { return common; }

        /**
         * Group delay differential between L1 and L2
         */
        public float tgd() { return tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public float cRs() { return cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public float cRc() { return cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public float cUc() { return cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public float cUs() { return cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public float cIc() { return cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public float cIs() { return cIs; }

        /**
         * Mean motion difference
         */
        public double dn() { return dn; }

        /**
         * Mean anomaly at reference time
         */
        public double m0() { return m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public double ecc() { return ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public double sqrta() { return sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public double omega0() { return omega0; }

        /**
         * Rate of right ascension
         */
        public double omegadot() { return omegadot; }

        /**
         * Argument of perigee
         */
        public double w() { return w; }

        /**
         * Inclination
         */
        public double inc() { return inc; }

        /**
         * Inclination first derivative
         */
        public double incDot() { return incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public float af0() { return af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public float af1() { return af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public float af2() { return af2; }

        /**
         * Clock reference
         */
        public Gnss.GpsTimeSec toc() { return toc; }

        /**
         * Issue of ephemeris data
         */
        public int iode() { return iode; }

        /**
         * Issue of clock data
         */
        public int iodc() { return iodc; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The base station position message is the position reported by the base
     * station itself. It is used for pseudo-absolute RTK positioning, and is
     * required to be a high-accuracy surveyed location of the base station.
     * Any error here will result in an error in the pseudo-absolute position
     * output.
     */
    public static class MsgBasePosLlh extends KaitaiStruct {
        public static MsgBasePosLlh fromFile(String fileName) throws IOException {
            return new MsgBasePosLlh(new ByteBufferKaitaiStream(fileName));
        }

        public MsgBasePosLlh(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgBasePosLlh(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgBasePosLlh(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.lat = this._io.readF8le();
            this.lon = this._io.readF8le();
            this.height = this._io.readF8le();
        }
        private double lat;
        private double lon;
        private double height;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Latitude
         */
        public double lat() { return lat; }

        /**
         * Longitude
         */
        public double lon() { return lon; }

        /**
         * Height
         */
        public double height() { return height; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class AlmanacCommonContent extends KaitaiStruct {
        public static AlmanacCommonContent fromFile(String fileName) throws IOException {
            return new AlmanacCommonContent(new ByteBufferKaitaiStream(fileName));
        }

        public AlmanacCommonContent(KaitaiStream _io) {
            this(_io, null, null);
        }

        public AlmanacCommonContent(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public AlmanacCommonContent(KaitaiStream _io, KaitaiStruct _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.toa = new Gnss.GpsTimeSec(this._io, this, _root);
            this.ura = this._io.readF8le();
            this.fitInterval = this._io.readU4le();
            this.valid = this._io.readU1();
            this.healthBits = this._io.readU1();
        }
        private Gnss.GnssSignal sid;
        private Gnss.GpsTimeSec toa;
        private double ura;
        private long fitInterval;
        private int valid;
        private int healthBits;
        private Observation _root;
        private KaitaiStruct _parent;

        /**
         * GNSS signal identifier
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * Reference time of almanac
         */
        public Gnss.GpsTimeSec toa() { return toa; }

        /**
         * User Range Accuracy
         */
        public double ura() { return ura; }

        /**
         * Curve fit interval
         */
        public long fitInterval() { return fitInterval; }

        /**
         * Status of almanac, 1 = valid, 0 = invalid
         */
        public int valid() { return valid; }

        /**
         * Satellite health status for GPS:
         *   - bits 5-7: NAV data health status. See IS-GPS-200H
         *     Table 20-VII: NAV Data Health Indications.
         *   - bits 0-4: Signal health status. See IS-GPS-200H
         *     Table 20-VIII. Codes for Health of SV Signal
         *     Components.
         * Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
         * details):
         *   - bit 0: C(n), "unhealthy" flag that is transmitted within
         *     non-immediate data and indicates overall constellation status
         *     at the moment of almanac uploading.
         *     '0' indicates malfunction of n-satellite.
         *     '1' indicates that n-satellite is operational.
         *   - bit 1: Bn(ln), '0' indicates the satellite is operational
         *     and suitable for navigation.
         */
        public int healthBits() { return healthBits; }
        public Observation _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * The OSR message contains network corrections in an observation-like
     * format.
     */
    public static class MsgOsr extends KaitaiStruct {
        public static MsgOsr fromFile(String fileName) throws IOException {
            return new MsgOsr(new ByteBufferKaitaiStream(fileName));
        }

        public MsgOsr(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgOsr(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgOsr(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new ObservationHeader(this._io, this, _root);
            this.obs = new ArrayList<PackedOsrContent>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.obs.add(new PackedOsrContent(this._io, this, _root));
                    i++;
                }
            }
        }
        private ObservationHeader header;
        private ArrayList<PackedOsrContent> obs;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Header of a GPS observation message
         */
        public ObservationHeader header() { return header; }

        /**
         * Network correction for a satellite signal.
         */
        public ArrayList<PackedOsrContent> obs() { return obs; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate GLO satellite position, velocity, and clock offset.
     * Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
     * immediate information (ephemeris parameters)" for more details.
     */
    public static class MsgEphemerisGloDepC extends KaitaiStruct {
        public static MsgEphemerisGloDepC fromFile(String fileName) throws IOException {
            return new MsgEphemerisGloDepC(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisGloDepC(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisGloDepC(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisGloDepC(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new EphemerisCommonContentDepB(this._io, this, _root);
            this.gamma = this._io.readF8le();
            this.tau = this._io.readF8le();
            this.dTau = this._io.readF8le();
            this.pos = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.pos.add(this._io.readF8le());
            }
            this.vel = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.vel.add(this._io.readF8le());
            }
            this.acc = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.acc.add(this._io.readF8le());
            }
            this.fcn = this._io.readU1();
        }
        private EphemerisCommonContentDepB common;
        private double gamma;
        private double tau;
        private double dTau;
        private ArrayList<Double> pos;
        private ArrayList<Double> vel;
        private ArrayList<Double> acc;
        private int fcn;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all ephemeris types
         */
        public EphemerisCommonContentDepB common() { return common; }

        /**
         * Relative deviation of predicted carrier frequency from nominal
         */
        public double gamma() { return gamma; }

        /**
         * Correction to the SV time
         */
        public double tau() { return tau; }

        /**
         * Equipment delay between L1 and L2
         */
        public double dTau() { return dTau; }

        /**
         * Position of the SV at tb in PZ-90.02 coordinates system
         */
        public ArrayList<Double> pos() { return pos; }

        /**
         * Velocity vector of the SV at tb in PZ-90.02 coordinates system
         */
        public ArrayList<Double> vel() { return vel; }

        /**
         * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
         */
        public ArrayList<Double> acc() { return acc; }

        /**
         * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
         */
        public int fcn() { return fcn; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate GLO satellite position, velocity, and clock offset.
     * Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
     * immediate information (ephemeris parameters)" for more details.
     */
    public static class MsgEphemerisGloDepB extends KaitaiStruct {
        public static MsgEphemerisGloDepB fromFile(String fileName) throws IOException {
            return new MsgEphemerisGloDepB(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisGloDepB(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisGloDepB(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisGloDepB(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new EphemerisCommonContentDepB(this._io, this, _root);
            this.gamma = this._io.readF8le();
            this.tau = this._io.readF8le();
            this.pos = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.pos.add(this._io.readF8le());
            }
            this.vel = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.vel.add(this._io.readF8le());
            }
            this.acc = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.acc.add(this._io.readF8le());
            }
        }
        private EphemerisCommonContentDepB common;
        private double gamma;
        private double tau;
        private ArrayList<Double> pos;
        private ArrayList<Double> vel;
        private ArrayList<Double> acc;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all ephemeris types
         */
        public EphemerisCommonContentDepB common() { return common; }

        /**
         * Relative deviation of predicted carrier frequency from nominal
         */
        public double gamma() { return gamma; }

        /**
         * Correction to the SV time
         */
        public double tau() { return tau; }

        /**
         * Position of the SV at tb in PZ-90.02 coordinates system
         */
        public ArrayList<Double> pos() { return pos; }

        /**
         * Velocity vector of the SV at tb in PZ-90.02 coordinates system
         */
        public ArrayList<Double> vel() { return vel; }

        /**
         * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
         */
        public ArrayList<Double> acc() { return acc; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
     */
    public static class MsgSvConfigurationGpsDep extends KaitaiStruct {
        public static MsgSvConfigurationGpsDep fromFile(String fileName) throws IOException {
            return new MsgSvConfigurationGpsDep(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSvConfigurationGpsDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSvConfigurationGpsDep(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSvConfigurationGpsDep(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tNmct = new Gnss.GpsTimeSec(this._io, this, _root);
            this.l2cMask = this._io.readU4le();
        }
        private Gnss.GpsTimeSec tNmct;
        private long l2cMask;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Navigation Message Correction Table Validity Time
         */
        public Gnss.GpsTimeSec tNmct() { return tNmct; }

        /**
         * L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
         */
        public long l2cMask() { return l2cMask; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class MsgEphemerisSbas extends KaitaiStruct {
        public static MsgEphemerisSbas fromFile(String fileName) throws IOException {
            return new MsgEphemerisSbas(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisSbas(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisSbas(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisSbas(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.common = new EphemerisCommonContent(this._io, this, _root);
            this.pos = new ArrayList<Double>();
            for (int i = 0; i < 3; i++) {
                this.pos.add(this._io.readF8le());
            }
            this.vel = new ArrayList<Float>();
            for (int i = 0; i < 3; i++) {
                this.vel.add(this._io.readF4le());
            }
            this.acc = new ArrayList<Float>();
            for (int i = 0; i < 3; i++) {
                this.acc.add(this._io.readF4le());
            }
            this.aGf0 = this._io.readF4le();
            this.aGf1 = this._io.readF4le();
        }
        private EphemerisCommonContent common;
        private ArrayList<Double> pos;
        private ArrayList<Float> vel;
        private ArrayList<Float> acc;
        private float aGf0;
        private float aGf1;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Values common for all ephemeris types
         */
        public EphemerisCommonContent common() { return common; }

        /**
         * Position of the GEO at time toe
         */
        public ArrayList<Double> pos() { return pos; }

        /**
         * Velocity of the GEO at time toe
         */
        public ArrayList<Float> vel() { return vel; }

        /**
         * Acceleration of the GEO at time toe
         */
        public ArrayList<Float> acc() { return acc; }

        /**
         * Time offset of the GEO clock w.r.t. SBAS Network Time
         */
        public float aGf0() { return aGf0; }

        /**
         * Drift of the GEO clock w.r.t. SBAS Network Time
         */
        public float aGf1() { return aGf1; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Pseudorange and carrier phase observation for a satellite being tracked.
     * Pseudoranges are referenced to a nominal pseudorange.
     */
    public static class PackedObsContentDepB extends KaitaiStruct {
        public static PackedObsContentDepB fromFile(String fileName) throws IOException {
            return new PackedObsContentDepB(new ByteBufferKaitaiStream(fileName));
        }

        public PackedObsContentDepB(KaitaiStream _io) {
            this(_io, null, null);
        }

        public PackedObsContentDepB(KaitaiStream _io, Observation.MsgObsDepB _parent) {
            this(_io, _parent, null);
        }

        public PackedObsContentDepB(KaitaiStream _io, Observation.MsgObsDepB _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.p = this._io.readU4le();
            this.l = new CarrierPhaseDepA(this._io, this, _root);
            this.cn0 = this._io.readU1();
            this.lock = this._io.readU2le();
            this.sid = new Gnss.GnssSignalDep(this._io, this, _root);
        }
        private long p;
        private CarrierPhaseDepA l;
        private int cn0;
        private int lock;
        private Gnss.GnssSignalDep sid;
        private Observation _root;
        private Observation.MsgObsDepB _parent;

        /**
         * Pseudorange observation
         */
        public long p() { return p; }

        /**
         * Carrier phase observation with opposite sign from typical
         * convention.
         */
        public CarrierPhaseDepA l() { return l; }

        /**
         * Carrier-to-Noise density
         */
        public int cn0() { return cn0; }

        /**
         * Lock indicator. This value changes whenever a satellite signal has
         * lost and regained lock, indicating that the carrier phase ambiguity
         * may have changed.
         */
        public int lock() { return lock; }

        /**
         * GNSS signal identifier
         */
        public Gnss.GnssSignalDep sid() { return sid; }
        public Observation _root() { return _root; }
        public Observation.MsgObsDepB _parent() { return _parent; }
    }

    /**
     * The GPS observations message reports all the raw pseudorange and carrier
     * phase observations for the satellites being tracked by the device.
     * Carrier phase observation here is represented as a 40-bit fixed point
     * number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
     * fractional cycles). The observations are interoperable with 3rd party
     * receivers and conform with typical RTCMv3 GNSS observations.
     */
    public static class MsgObsDepC extends KaitaiStruct {
        public static MsgObsDepC fromFile(String fileName) throws IOException {
            return new MsgObsDepC(new ByteBufferKaitaiStream(fileName));
        }

        public MsgObsDepC(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgObsDepC(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgObsDepC(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new ObservationHeaderDep(this._io, this, _root);
            this.obs = new ArrayList<PackedObsContentDepC>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.obs.add(new PackedObsContentDepC(this._io, this, _root));
                    i++;
                }
            }
        }
        private ObservationHeaderDep header;
        private ArrayList<PackedObsContentDepC> obs;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Header of a GPS observation message
         */
        public ObservationHeaderDep header() { return header; }

        /**
         * Pseudorange and carrier phase observation for a satellite being
         * tracked.
         */
        public ArrayList<PackedObsContentDepC> obs() { return obs; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class MsgEphemerisDepA extends KaitaiStruct {
        public static MsgEphemerisDepA fromFile(String fileName) throws IOException {
            return new MsgEphemerisDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEphemerisDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEphemerisDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEphemerisDepA(KaitaiStream _io, Sbp.Message _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tgd = this._io.readF8le();
            this.cRs = this._io.readF8le();
            this.cRc = this._io.readF8le();
            this.cUc = this._io.readF8le();
            this.cUs = this._io.readF8le();
            this.cIc = this._io.readF8le();
            this.cIs = this._io.readF8le();
            this.dn = this._io.readF8le();
            this.m0 = this._io.readF8le();
            this.ecc = this._io.readF8le();
            this.sqrta = this._io.readF8le();
            this.omega0 = this._io.readF8le();
            this.omegadot = this._io.readF8le();
            this.w = this._io.readF8le();
            this.inc = this._io.readF8le();
            this.incDot = this._io.readF8le();
            this.af0 = this._io.readF8le();
            this.af1 = this._io.readF8le();
            this.af2 = this._io.readF8le();
            this.toeTow = this._io.readF8le();
            this.toeWn = this._io.readU2le();
            this.tocTow = this._io.readF8le();
            this.tocWn = this._io.readU2le();
            this.valid = this._io.readU1();
            this.healthy = this._io.readU1();
            this.prn = this._io.readU1();
        }
        private double tgd;
        private double cRs;
        private double cRc;
        private double cUc;
        private double cUs;
        private double cIc;
        private double cIs;
        private double dn;
        private double m0;
        private double ecc;
        private double sqrta;
        private double omega0;
        private double omegadot;
        private double w;
        private double inc;
        private double incDot;
        private double af0;
        private double af1;
        private double af2;
        private double toeTow;
        private int toeWn;
        private double tocTow;
        private int tocWn;
        private int valid;
        private int healthy;
        private int prn;
        private Observation _root;
        private Sbp.Message _parent;

        /**
         * Group delay differential between L1 and L2
         */
        public double tgd() { return tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public double cRs() { return cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public double cRc() { return cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public double cUc() { return cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public double cUs() { return cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public double cIc() { return cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public double cIs() { return cIs; }

        /**
         * Mean motion difference
         */
        public double dn() { return dn; }

        /**
         * Mean anomaly at reference time
         */
        public double m0() { return m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public double ecc() { return ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public double sqrta() { return sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public double omega0() { return omega0; }

        /**
         * Rate of right ascension
         */
        public double omegadot() { return omegadot; }

        /**
         * Argument of perigee
         */
        public double w() { return w; }

        /**
         * Inclination
         */
        public double inc() { return inc; }

        /**
         * Inclination first derivative
         */
        public double incDot() { return incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public double af0() { return af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public double af1() { return af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public double af2() { return af2; }

        /**
         * Time of week
         */
        public double toeTow() { return toeTow; }

        /**
         * Week number
         */
        public int toeWn() { return toeWn; }

        /**
         * Clock reference time of week
         */
        public double tocTow() { return tocTow; }

        /**
         * Clock reference week number
         */
        public int tocWn() { return tocWn; }

        /**
         * Is valid?
         */
        public int valid() { return valid; }

        /**
         * Satellite is healthy?
         */
        public int healthy() { return healthy; }

        /**
         * PRN being tracked
         */
        public int prn() { return prn; }
        public Observation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class EphemerisCommonContentDepB extends KaitaiStruct {
        public static EphemerisCommonContentDepB fromFile(String fileName) throws IOException {
            return new EphemerisCommonContentDepB(new ByteBufferKaitaiStream(fileName));
        }

        public EphemerisCommonContentDepB(KaitaiStream _io) {
            this(_io, null, null);
        }

        public EphemerisCommonContentDepB(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public EphemerisCommonContentDepB(KaitaiStream _io, KaitaiStruct _parent, Observation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.toe = new Gnss.GpsTimeSec(this._io, this, _root);
            this.ura = this._io.readF8le();
            this.fitInterval = this._io.readU4le();
            this.valid = this._io.readU1();
            this.healthBits = this._io.readU1();
        }
        private Gnss.GnssSignal sid;
        private Gnss.GpsTimeSec toe;
        private double ura;
        private long fitInterval;
        private int valid;
        private int healthBits;
        private Observation _root;
        private KaitaiStruct _parent;

        /**
         * GNSS signal identifier (16 bit)
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * Time of Ephemerides
         */
        public Gnss.GpsTimeSec toe() { return toe; }

        /**
         * User Range Accuracy
         */
        public double ura() { return ura; }

        /**
         * Curve fit interval
         */
        public long fitInterval() { return fitInterval; }

        /**
         * Status of ephemeris, 1 = valid, 0 = invalid
         */
        public int valid() { return valid; }

        /**
         * Satellite health status.
         * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
         * Others: 0 = valid, non-zero = invalid
         */
        public int healthBits() { return healthBits; }
        public Observation _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }
    private Observation _root;
    private KaitaiStruct _parent;
    public Observation _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
