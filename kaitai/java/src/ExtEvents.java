// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;

public class ExtEvents extends KaitaiStruct {
    public static ExtEvents fromFile(String fileName) throws IOException {
        return new ExtEvents(new ByteBufferKaitaiStream(fileName));
    }

    public ExtEvents(KaitaiStream _io) {
        this(_io, null, null);
    }

    public ExtEvents(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public ExtEvents(KaitaiStream _io, KaitaiStruct _parent, ExtEvents _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * Reports detection of an external event, the GPS time it occurred, which
     * pin it was and whether it was rising or falling.
     */
    public static class MsgExtEvent extends KaitaiStruct {
        public static MsgExtEvent fromFile(String fileName) throws IOException {
            return new MsgExtEvent(new ByteBufferKaitaiStream(fileName));
        }

        public MsgExtEvent(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgExtEvent(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgExtEvent(KaitaiStream _io, Sbp.Message _parent, ExtEvents _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.wn = this._io.readU2le();
            this.tow = this._io.readU4le();
            this.nsResidual = this._io.readS4le();
            this.flags = this._io.readU1();
            this.pin = this._io.readU1();
        }
        private int wn;
        private long tow;
        private int nsResidual;
        private int flags;
        private int pin;
        private ExtEvents _root;
        private Sbp.Message _parent;

        /**
         * GPS week number
         */
        public int wn() { return wn; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        public long tow() { return tow; }

        /**
         * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
         * to 500000)
         */
        public int nsResidual() { return nsResidual; }

        /**
         * Flags
         */
        public int flags() { return flags; }

        /**
         * Pin number.  0..9 = DEBUG0..9.
         */
        public int pin() { return pin; }
        public ExtEvents _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private ExtEvents _root;
    private KaitaiStruct _parent;
    public ExtEvents _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
