// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.util.ArrayList;

public class Telemetry extends KaitaiStruct {
    public static Telemetry fromFile(String fileName) throws IOException {
        return new Telemetry(new ByteBufferKaitaiStream(fileName));
    }

    public Telemetry(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Telemetry(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Telemetry(KaitaiStream _io, KaitaiStruct _parent, Telemetry _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }
    public static class TelemetrySv extends KaitaiStruct {
        public static TelemetrySv fromFile(String fileName) throws IOException {
            return new TelemetrySv(new ByteBufferKaitaiStream(fileName));
        }

        public TelemetrySv(KaitaiStream _io) {
            this(_io, null, null);
        }

        public TelemetrySv(KaitaiStream _io, Telemetry.MsgTelSv _parent) {
            this(_io, _parent, null);
        }

        public TelemetrySv(KaitaiStream _io, Telemetry.MsgTelSv _parent, Telemetry _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.az = this._io.readU1();
            this.el = this._io.readS1();
            this.availabilityFlags = this._io.readU1();
            this.pseudorangeResidual = this._io.readS2le();
            this.phaseResidual = this._io.readS2le();
            this.outlierFlags = this._io.readU1();
            this.ephemerisFlags = this._io.readU1();
            this.correctionFlags = this._io.readU1();
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
        }
        private int az;
        private byte el;
        private int availabilityFlags;
        private short pseudorangeResidual;
        private short phaseResidual;
        private int outlierFlags;
        private int ephemerisFlags;
        private int correctionFlags;
        private Gnss.GnssSignal sid;
        private Telemetry _root;
        private Telemetry.MsgTelSv _parent;

        /**
         * Azimuth angle (range 0..179)
         */
        public int az() { return az; }

        /**
         * Elevation angle (range -90..90)
         */
        public byte el() { return el; }

        /**
         * Observation availability at filter update
         */
        public int availabilityFlags() { return availabilityFlags; }

        /**
         * Pseudorange observation residual
         */
        public short pseudorangeResidual() { return pseudorangeResidual; }

        /**
         * Carrier-phase or carrier-phase-derived observation residual
         */
        public short phaseResidual() { return phaseResidual; }

        /**
         * Reports if observation is marked as an outlier and is excluded from
         * the update
         */
        public int outlierFlags() { return outlierFlags; }

        /**
         * Ephemeris metadata
         */
        public int ephemerisFlags() { return ephemerisFlags; }

        /**
         * Reserved
         */
        public int correctionFlags() { return correctionFlags; }

        /**
         * GNSS signal identifier (16 bit)
         */
        public Gnss.GnssSignal sid() { return sid; }
        public Telemetry _root() { return _root; }
        public Telemetry.MsgTelSv _parent() { return _parent; }
    }

    /**
     * This message includes telemetry pertinent to satellite signals available
     * to Starling.
     */
    public static class MsgTelSv extends KaitaiStruct {
        public static MsgTelSv fromFile(String fileName) throws IOException {
            return new MsgTelSv(new ByteBufferKaitaiStream(fileName));
        }

        public MsgTelSv(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgTelSv(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgTelSv(KaitaiStream _io, Sbp.Message _parent, Telemetry _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.wn = this._io.readU2le();
            this.tow = this._io.readU4le();
            this.nObs = this._io.readU1();
            this.originFlags = this._io.readU1();
            this.svTel = new ArrayList<TelemetrySv>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.svTel.add(new TelemetrySv(this._io, this, _root));
                    i++;
                }
            }
        }
        private int wn;
        private long tow;
        private int nObs;
        private int originFlags;
        private ArrayList<TelemetrySv> svTel;
        private Telemetry _root;
        private Sbp.Message _parent;

        /**
         * GPS week number
         */
        public int wn() { return wn; }

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Total number of observations. First nibble is the size of the
         * sequence (n), second nibble is the zero-indexed counter (ith packet
         * of n)
         */
        public int nObs() { return nObs; }

        /**
         * Flags to identify the filter type from which the telemetry is
         * reported from
         */
        public int originFlags() { return originFlags; }

        /**
         * Array of per-signal telemetry entries
         */
        public ArrayList<TelemetrySv> svTel() { return svTel; }
        public Telemetry _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Telemetry _root;
    private KaitaiStruct _parent;
    public Telemetry _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
