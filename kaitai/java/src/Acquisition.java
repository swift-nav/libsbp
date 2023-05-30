// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.util.ArrayList;

public class Acquisition extends KaitaiStruct {
    public static Acquisition fromFile(String fileName) throws IOException {
        return new Acquisition(new ByteBufferKaitaiStream(fileName));
    }

    public Acquisition(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Acquisition(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Acquisition(KaitaiStream _io, KaitaiStruct _parent, Acquisition _root) {
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
    public static class MsgAcqResultDepC extends KaitaiStruct {
        public static MsgAcqResultDepC fromFile(String fileName) throws IOException {
            return new MsgAcqResultDepC(new ByteBufferKaitaiStream(fileName));
        }

        public MsgAcqResultDepC(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgAcqResultDepC(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgAcqResultDepC(KaitaiStream _io, Sbp.Message _parent, Acquisition _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.cn0 = this._io.readF4le();
            this.cp = this._io.readF4le();
            this.cf = this._io.readF4le();
            this.sid = new Gnss.GnssSignalDep(this._io, this, _root);
        }
        private float cn0;
        private float cp;
        private float cf;
        private Gnss.GnssSignalDep sid;
        private Acquisition _root;
        private Sbp.Message _parent;

        /**
         * CN/0 of best point
         */
        public float cn0() { return cn0; }

        /**
         * Code phase of best point
         */
        public float cp() { return cp; }

        /**
         * Carrier frequency of best point
         */
        public float cf() { return cf; }

        /**
         * GNSS signal for which acquisition was attempted
         */
        public Gnss.GnssSignalDep sid() { return sid; }
        public Acquisition _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class MsgAcqResultDepB extends KaitaiStruct {
        public static MsgAcqResultDepB fromFile(String fileName) throws IOException {
            return new MsgAcqResultDepB(new ByteBufferKaitaiStream(fileName));
        }

        public MsgAcqResultDepB(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgAcqResultDepB(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgAcqResultDepB(KaitaiStream _io, Sbp.Message _parent, Acquisition _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.snr = this._io.readF4le();
            this.cp = this._io.readF4le();
            this.cf = this._io.readF4le();
            this.sid = new Gnss.GnssSignalDep(this._io, this, _root);
        }
        private float snr;
        private float cp;
        private float cf;
        private Gnss.GnssSignalDep sid;
        private Acquisition _root;
        private Sbp.Message _parent;

        /**
         * SNR of best point. Currently in arbitrary SNR points, but will be in
         * units of dB Hz in a later revision of this message.
         */
        public float snr() { return snr; }

        /**
         * Code phase of best point
         */
        public float cp() { return cp; }

        /**
         * Carrier frequency of best point
         */
        public float cf() { return cf; }

        /**
         * GNSS signal for which acquisition was attempted
         */
        public Gnss.GnssSignalDep sid() { return sid; }
        public Acquisition _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Profile for a specific SV for debugging purposes. The message describes
     * SV profile during acquisition time. The message is used to debug and
     * measure the performance.
     */
    public static class AcqSvProfile extends KaitaiStruct {
        public static AcqSvProfile fromFile(String fileName) throws IOException {
            return new AcqSvProfile(new ByteBufferKaitaiStream(fileName));
        }

        public AcqSvProfile(KaitaiStream _io) {
            this(_io, null, null);
        }

        public AcqSvProfile(KaitaiStream _io, Acquisition.MsgAcqSvProfile _parent) {
            this(_io, _parent, null);
        }

        public AcqSvProfile(KaitaiStream _io, Acquisition.MsgAcqSvProfile _parent, Acquisition _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.jobType = this._io.readU1();
            this.status = this._io.readU1();
            this.cn0 = this._io.readU2le();
            this.intTime = this._io.readU1();
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.binWidth = this._io.readU2le();
            this.timestamp = this._io.readU4le();
            this.timeSpent = this._io.readU4le();
            this.cfMin = this._io.readS4le();
            this.cfMax = this._io.readS4le();
            this.cf = this._io.readS4le();
            this.cp = this._io.readU4le();
        }
        private int jobType;
        private int status;
        private int cn0;
        private int intTime;
        private Gnss.GnssSignal sid;
        private int binWidth;
        private long timestamp;
        private long timeSpent;
        private int cfMin;
        private int cfMax;
        private int cf;
        private long cp;
        private Acquisition _root;
        private Acquisition.MsgAcqSvProfile _parent;

        /**
         * SV search job type (deep, fallback, etc)
         */
        public int jobType() { return jobType; }

        /**
         * Acquisition status 1 is Success, 0 is Failure
         */
        public int status() { return status; }

        /**
         * CN0 value. Only valid if status is '1'
         */
        public int cn0() { return cn0; }

        /**
         * Acquisition integration time
         */
        public int intTime() { return intTime; }

        /**
         * GNSS signal for which acquisition was attempted
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * Acq frequency bin width
         */
        public int binWidth() { return binWidth; }

        /**
         * Timestamp of the job complete event
         */
        public long timestamp() { return timestamp; }

        /**
         * Time spent to search for sid.code
         */
        public long timeSpent() { return timeSpent; }

        /**
         * Doppler range lowest frequency
         */
        public int cfMin() { return cfMin; }

        /**
         * Doppler range highest frequency
         */
        public int cfMax() { return cfMax; }

        /**
         * Doppler value of detected peak. Only valid if status is '1'
         */
        public int cf() { return cf; }

        /**
         * Codephase of detected peak. Only valid if status is '1'
         */
        public long cp() { return cp; }
        public Acquisition _root() { return _root; }
        public Acquisition.MsgAcqSvProfile _parent() { return _parent; }
    }

    /**
     * The message describes all SV profiles during acquisition time. The
     * message is used to debug and measure the performance.
     */
    public static class MsgAcqSvProfile extends KaitaiStruct {
        public static MsgAcqSvProfile fromFile(String fileName) throws IOException {
            return new MsgAcqSvProfile(new ByteBufferKaitaiStream(fileName));
        }

        public MsgAcqSvProfile(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgAcqSvProfile(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgAcqSvProfile(KaitaiStream _io, Sbp.Message _parent, Acquisition _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.acqSvProfile = new ArrayList<AcqSvProfile>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.acqSvProfile.add(new AcqSvProfile(this._io, this, _root));
                    i++;
                }
            }
        }
        private ArrayList<AcqSvProfile> acqSvProfile;
        private Acquisition _root;
        private Sbp.Message _parent;

        /**
         * SV profiles during acquisition time
         */
        public ArrayList<AcqSvProfile> acqSvProfile() { return acqSvProfile; }
        public Acquisition _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class AcqSvProfileDep extends KaitaiStruct {
        public static AcqSvProfileDep fromFile(String fileName) throws IOException {
            return new AcqSvProfileDep(new ByteBufferKaitaiStream(fileName));
        }

        public AcqSvProfileDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public AcqSvProfileDep(KaitaiStream _io, Acquisition.MsgAcqSvProfileDep _parent) {
            this(_io, _parent, null);
        }

        public AcqSvProfileDep(KaitaiStream _io, Acquisition.MsgAcqSvProfileDep _parent, Acquisition _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.jobType = this._io.readU1();
            this.status = this._io.readU1();
            this.cn0 = this._io.readU2le();
            this.intTime = this._io.readU1();
            this.sid = new Gnss.GnssSignalDep(this._io, this, _root);
            this.binWidth = this._io.readU2le();
            this.timestamp = this._io.readU4le();
            this.timeSpent = this._io.readU4le();
            this.cfMin = this._io.readS4le();
            this.cfMax = this._io.readS4le();
            this.cf = this._io.readS4le();
            this.cp = this._io.readU4le();
        }
        private int jobType;
        private int status;
        private int cn0;
        private int intTime;
        private Gnss.GnssSignalDep sid;
        private int binWidth;
        private long timestamp;
        private long timeSpent;
        private int cfMin;
        private int cfMax;
        private int cf;
        private long cp;
        private Acquisition _root;
        private Acquisition.MsgAcqSvProfileDep _parent;

        /**
         * SV search job type (deep, fallback, etc)
         */
        public int jobType() { return jobType; }

        /**
         * Acquisition status 1 is Success, 0 is Failure
         */
        public int status() { return status; }

        /**
         * CN0 value. Only valid if status is '1'
         */
        public int cn0() { return cn0; }

        /**
         * Acquisition integration time
         */
        public int intTime() { return intTime; }

        /**
         * GNSS signal for which acquisition was attempted
         */
        public Gnss.GnssSignalDep sid() { return sid; }

        /**
         * Acq frequency bin width
         */
        public int binWidth() { return binWidth; }

        /**
         * Timestamp of the job complete event
         */
        public long timestamp() { return timestamp; }

        /**
         * Time spent to search for sid.code
         */
        public long timeSpent() { return timeSpent; }

        /**
         * Doppler range lowest frequency
         */
        public int cfMin() { return cfMin; }

        /**
         * Doppler range highest frequency
         */
        public int cfMax() { return cfMax; }

        /**
         * Doppler value of detected peak. Only valid if status is '1'
         */
        public int cf() { return cf; }

        /**
         * Codephase of detected peak. Only valid if status is '1'
         */
        public long cp() { return cp; }
        public Acquisition _root() { return _root; }
        public Acquisition.MsgAcqSvProfileDep _parent() { return _parent; }
    }

    /**
     * This message describes the results from an attempted GPS signal
     * acquisition search for a satellite PRN over a code phase/carrier
     * frequency range. It contains the parameters of the point in the
     * acquisition search space with the best carrier-to-noise (CN/0) ratio.
     */
    public static class MsgAcqResult extends KaitaiStruct {
        public static MsgAcqResult fromFile(String fileName) throws IOException {
            return new MsgAcqResult(new ByteBufferKaitaiStream(fileName));
        }

        public MsgAcqResult(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgAcqResult(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgAcqResult(KaitaiStream _io, Sbp.Message _parent, Acquisition _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.cn0 = this._io.readF4le();
            this.cp = this._io.readF4le();
            this.cf = this._io.readF4le();
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
        }
        private float cn0;
        private float cp;
        private float cf;
        private Gnss.GnssSignal sid;
        private Acquisition _root;
        private Sbp.Message _parent;

        /**
         * CN/0 of best point
         */
        public float cn0() { return cn0; }

        /**
         * Code phase of best point
         */
        public float cp() { return cp; }

        /**
         * Carrier frequency of best point
         */
        public float cf() { return cf; }

        /**
         * GNSS signal for which acquisition was attempted
         */
        public Gnss.GnssSignal sid() { return sid; }
        public Acquisition _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class MsgAcqResultDepA extends KaitaiStruct {
        public static MsgAcqResultDepA fromFile(String fileName) throws IOException {
            return new MsgAcqResultDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgAcqResultDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgAcqResultDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgAcqResultDepA(KaitaiStream _io, Sbp.Message _parent, Acquisition _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.snr = this._io.readF4le();
            this.cp = this._io.readF4le();
            this.cf = this._io.readF4le();
            this.prn = this._io.readU1();
        }
        private float snr;
        private float cp;
        private float cf;
        private int prn;
        private Acquisition _root;
        private Sbp.Message _parent;

        /**
         * SNR of best point. Currently dimensionless, but will have units of
         * dB Hz in the revision of this message.
         */
        public float snr() { return snr; }

        /**
         * Code phase of best point
         */
        public float cp() { return cp; }

        /**
         * Carrier frequency of best point
         */
        public float cf() { return cf; }

        /**
         * PRN-1 identifier of the satellite signal for which acquisition was
         * attempted
         */
        public int prn() { return prn; }
        public Acquisition _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class MsgAcqSvProfileDep extends KaitaiStruct {
        public static MsgAcqSvProfileDep fromFile(String fileName) throws IOException {
            return new MsgAcqSvProfileDep(new ByteBufferKaitaiStream(fileName));
        }

        public MsgAcqSvProfileDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgAcqSvProfileDep(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgAcqSvProfileDep(KaitaiStream _io, Sbp.Message _parent, Acquisition _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.acqSvProfile = new ArrayList<AcqSvProfileDep>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.acqSvProfile.add(new AcqSvProfileDep(this._io, this, _root));
                    i++;
                }
            }
        }
        private ArrayList<AcqSvProfileDep> acqSvProfile;
        private Acquisition _root;
        private Sbp.Message _parent;

        /**
         * SV profiles during acquisition time
         */
        public ArrayList<AcqSvProfileDep> acqSvProfile() { return acqSvProfile; }
        public Acquisition _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Acquisition _root;
    private KaitaiStruct _parent;
    public Acquisition _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
