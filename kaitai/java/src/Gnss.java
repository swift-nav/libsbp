// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;

public class Gnss extends KaitaiStruct {
    public static Gnss fromFile(String fileName) throws IOException {
        return new Gnss(new ByteBufferKaitaiStream(fileName));
    }

    public Gnss(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Gnss(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Gnss(KaitaiStream _io, KaitaiStruct _parent, Gnss _root) {
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
    public static class GnssSignalDep extends KaitaiStruct {
        public static GnssSignalDep fromFile(String fileName) throws IOException {
            return new GnssSignalDep(new ByteBufferKaitaiStream(fileName));
        }

        public GnssSignalDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public GnssSignalDep(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public GnssSignalDep(KaitaiStream _io, KaitaiStruct _parent, Gnss _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sat = this._io.readU2le();
            this.code = this._io.readU1();
            this.reserved = this._io.readU1();
        }
        private int sat;
        private int code;
        private int reserved;
        private Gnss _root;
        private KaitaiStruct _parent;

        /**
         * Constellation-specific satellite identifier.
         * 
         * Note: unlike GnssSignal, GPS satellites are encoded as (PRN - 1).
         * Other constellations do not have this offset.
         */
        public int sat() { return sat; }

        /**
         * Signal constellation, band and code
         */
        public int code() { return code; }

        /**
         * Reserved
         */
        public int reserved() { return reserved; }
        public Gnss _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * Carrier phase measurement in cycles represented as a 40-bit fixed point
     * number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
     * fractional cycles. This phase has the same sign as the pseudorange.
     */
    public static class CarrierPhase extends KaitaiStruct {
        public static CarrierPhase fromFile(String fileName) throws IOException {
            return new CarrierPhase(new ByteBufferKaitaiStream(fileName));
        }

        public CarrierPhase(KaitaiStream _io) {
            this(_io, null, null);
        }

        public CarrierPhase(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public CarrierPhase(KaitaiStream _io, KaitaiStruct _parent, Gnss _root) {
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
        private Gnss _root;
        private KaitaiStruct _parent;

        /**
         * Carrier phase whole cycles
         */
        public int i() { return i; }

        /**
         * Carrier phase fractional part
         */
        public int f() { return f; }
        public Gnss _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * A wire-appropriate GPS time, defined as the number of milliseconds since
     * beginning of the week on the Saturday/Sunday transition.
     */
    public static class GpsTimeDep extends KaitaiStruct {
        public static GpsTimeDep fromFile(String fileName) throws IOException {
            return new GpsTimeDep(new ByteBufferKaitaiStream(fileName));
        }

        public GpsTimeDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public GpsTimeDep(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public GpsTimeDep(KaitaiStream _io, KaitaiStruct _parent, Gnss _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.wn = this._io.readU2le();
        }
        private long tow;
        private int wn;
        private Gnss _root;
        private KaitaiStruct _parent;

        /**
         * Milliseconds since start of GPS week
         */
        public long tow() { return tow; }

        /**
         * GPS week number
         */
        public int wn() { return wn; }
        public Gnss _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * Signal identifier containing constellation, band, and satellite
     * identifier.
     */
    public static class GnssSignal extends KaitaiStruct {
        public static GnssSignal fromFile(String fileName) throws IOException {
            return new GnssSignal(new ByteBufferKaitaiStream(fileName));
        }

        public GnssSignal(KaitaiStream _io) {
            this(_io, null, null);
        }

        public GnssSignal(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public GnssSignal(KaitaiStream _io, KaitaiStruct _parent, Gnss _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sat = this._io.readU1();
            this.code = this._io.readU1();
        }
        private int sat;
        private int code;
        private Gnss _root;
        private KaitaiStruct _parent;

        /**
         * Constellation-specific satellite id. For GLO can either be (100+FCN)
         * where FCN is in [-7,+6] or the Slot ID in [1,28].
         */
        public int sat() { return sat; }

        /**
         * Signal constellation, band and code
         */
        public int code() { return code; }
        public Gnss _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * A wire-appropriate receiver clock time, defined as the time since the
     * beginning of the week on the Saturday/Sunday transition. In most cases,
     * observations are epoch aligned so ns field will be 0.
     */
    public static class GpsTime extends KaitaiStruct {
        public static GpsTime fromFile(String fileName) throws IOException {
            return new GpsTime(new ByteBufferKaitaiStream(fileName));
        }

        public GpsTime(KaitaiStream _io) {
            this(_io, null, null);
        }

        public GpsTime(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public GpsTime(KaitaiStream _io, KaitaiStruct _parent, Gnss _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.nsResidual = this._io.readS4le();
            this.wn = this._io.readU2le();
        }
        private long tow;
        private int nsResidual;
        private int wn;
        private Gnss _root;
        private KaitaiStruct _parent;

        /**
         * Milliseconds since start of GPS week
         */
        public long tow() { return tow; }

        /**
         * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
         * to 500000)
         */
        public int nsResidual() { return nsResidual; }

        /**
         * GPS week number
         */
        public int wn() { return wn; }
        public Gnss _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * A GPS time, defined as the number of seconds since beginning of the week
     * on the Saturday/Sunday transition.
     */
    public static class GpsTimeSec extends KaitaiStruct {
        public static GpsTimeSec fromFile(String fileName) throws IOException {
            return new GpsTimeSec(new ByteBufferKaitaiStream(fileName));
        }

        public GpsTimeSec(KaitaiStream _io) {
            this(_io, null, null);
        }

        public GpsTimeSec(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public GpsTimeSec(KaitaiStream _io, KaitaiStruct _parent, Gnss _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.wn = this._io.readU2le();
        }
        private long tow;
        private int wn;
        private Gnss _root;
        private KaitaiStruct _parent;

        /**
         * Seconds since start of GPS week
         */
        public long tow() { return tow; }

        /**
         * GPS week number
         */
        public int wn() { return wn; }
        public Gnss _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * A (Constellation ID, satellite ID) tuple that uniquely identifies a
     * space vehicle.
     */
    public static class SvId extends KaitaiStruct {
        public static SvId fromFile(String fileName) throws IOException {
            return new SvId(new ByteBufferKaitaiStream(fileName));
        }

        public SvId(KaitaiStream _io) {
            this(_io, null, null);
        }

        public SvId(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public SvId(KaitaiStream _io, KaitaiStruct _parent, Gnss _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.satId = this._io.readU1();
            this.constellation = this._io.readU1();
        }
        private int satId;
        private int constellation;
        private Gnss _root;
        private KaitaiStruct _parent;

        /**
         * Constellation-specific satellite id. For GLO can either be (100+FCN)
         * where FCN is in [-7,+6] or the Slot ID in [1,28].
         */
        public int satId() { return satId; }

        /**
         * Constellation ID to which the SV belongs
         */
        public int constellation() { return constellation; }
        public Gnss _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }
    private Gnss _root;
    private KaitaiStruct _parent;
    public Gnss _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
