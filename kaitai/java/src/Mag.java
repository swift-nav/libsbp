// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;

public class Mag extends KaitaiStruct {
    public static Mag fromFile(String fileName) throws IOException {
        return new Mag(new ByteBufferKaitaiStream(fileName));
    }

    public Mag(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Mag(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Mag(KaitaiStream _io, KaitaiStruct _parent, Mag _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * Raw data from the magnetometer.
     */
    public static class MsgMagRaw extends KaitaiStruct {
        public static MsgMagRaw fromFile(String fileName) throws IOException {
            return new MsgMagRaw(new ByteBufferKaitaiStream(fileName));
        }

        public MsgMagRaw(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgMagRaw(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgMagRaw(KaitaiStream _io, Sbp.Message _parent, Mag _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.towF = this._io.readU1();
            this.magX = this._io.readS2le();
            this.magY = this._io.readS2le();
            this.magZ = this._io.readS2le();
        }
        private long tow;
        private int towF;
        private short magX;
        private short magY;
        private short magZ;
        private Mag _root;
        private Sbp.Message _parent;

        /**
         * Milliseconds since start of GPS week. If the high bit is set, the
         * time is unknown or invalid.
         */
        public long tow() { return tow; }

        /**
         * Milliseconds since start of GPS week, fractional part
         */
        public int towF() { return towF; }

        /**
         * Magnetic field in the body frame X axis
         */
        public short magX() { return magX; }

        /**
         * Magnetic field in the body frame Y axis
         */
        public short magY() { return magY; }

        /**
         * Magnetic field in the body frame Z axis
         */
        public short magZ() { return magZ; }
        public Mag _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Mag _root;
    private KaitaiStruct _parent;
    public Mag _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
