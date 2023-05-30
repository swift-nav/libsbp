// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.util.ArrayList;

public class Sbas extends KaitaiStruct {
    public static Sbas fromFile(String fileName) throws IOException {
        return new Sbas(new ByteBufferKaitaiStream(fileName));
    }

    public Sbas(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Sbas(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Sbas(KaitaiStream _io, KaitaiStruct _parent, Sbas _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * This message is sent once per second per SBAS satellite. ME checks the
     * parity of the data block and sends only blocks that pass the check.
     */
    public static class MsgSbasRaw extends KaitaiStruct {
        public static MsgSbasRaw fromFile(String fileName) throws IOException {
            return new MsgSbasRaw(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSbasRaw(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSbasRaw(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSbasRaw(KaitaiStream _io, Sbp.Message _parent, Sbas _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.tow = this._io.readU4le();
            this.messageType = this._io.readU1();
            this.data = new ArrayList<Integer>();
            for (int i = 0; i < 27; i++) {
                this.data.add(this._io.readU1());
            }
        }
        private Gnss.GnssSignal sid;
        private long tow;
        private int messageType;
        private ArrayList<Integer> data;
        private Sbas _root;
        private Sbp.Message _parent;

        /**
         * GNSS signal identifier.
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * GPS time-of-week at the start of the data block.
         */
        public long tow() { return tow; }

        /**
         * SBAS message type (0-63)
         */
        public int messageType() { return messageType; }

        /**
         * Raw SBAS data field of 212 bits (last byte padded with zeros).
         */
        public ArrayList<Integer> data() { return data; }
        public Sbas _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Sbas _root;
    private KaitaiStruct _parent;
    public Sbas _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
