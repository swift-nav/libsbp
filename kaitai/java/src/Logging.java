// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.nio.charset.Charset;
import java.util.ArrayList;

public class Logging extends KaitaiStruct {
    public static Logging fromFile(String fileName) throws IOException {
        return new Logging(new ByteBufferKaitaiStream(fileName));
    }

    public Logging(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Logging(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Logging(KaitaiStream _io, KaitaiStruct _parent, Logging _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * This message contains a human-readable payload string from the device
     * containing errors, warnings and informational messages at ERROR,
     * WARNING, DEBUG, INFO logging levels.
     */
    public static class MsgLog extends KaitaiStruct {
        public static MsgLog fromFile(String fileName) throws IOException {
            return new MsgLog(new ByteBufferKaitaiStream(fileName));
        }

        public MsgLog(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgLog(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgLog(KaitaiStream _io, Sbp.Message _parent, Logging _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.level = this._io.readU1();
            this.text = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private int level;
        private String text;
        private Logging _root;
        private Sbp.Message _parent;

        /**
         * Logging level
         */
        public int level() { return level; }

        /**
         * Human-readable string
         */
        public String text() { return text; }
        public Logging _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message provides the ability to forward messages over SBP.  This
     * may take the form of wrapping up SBP messages received by Piksi for
     * logging purposes or wrapping another protocol with SBP.
     * 
     * The source identifier indicates from what interface a forwarded stream
     * derived. The protocol identifier identifies what the expected protocol
     * the forwarded msg contains. Protocol 0 represents SBP and the remaining
     * values are implementation defined.
     */
    public static class MsgFwd extends KaitaiStruct {
        public static MsgFwd fromFile(String fileName) throws IOException {
            return new MsgFwd(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFwd(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFwd(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFwd(KaitaiStream _io, Sbp.Message _parent, Logging _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.source = this._io.readU1();
            this.protocol = this._io.readU1();
            this.fwdPayload = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.fwdPayload.add(this._io.readU1());
                    i++;
                }
            }
        }
        private int source;
        private int protocol;
        private ArrayList<Integer> fwdPayload;
        private Logging _root;
        private Sbp.Message _parent;

        /**
         * source identifier
         */
        public int source() { return source; }

        /**
         * protocol identifier
         */
        public int protocol() { return protocol; }

        /**
         * variable length wrapped binary message
         */
        public ArrayList<Integer> fwdPayload() { return fwdPayload; }
        public Logging _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class MsgPrintDep extends KaitaiStruct {
        public static MsgPrintDep fromFile(String fileName) throws IOException {
            return new MsgPrintDep(new ByteBufferKaitaiStream(fileName));
        }

        public MsgPrintDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgPrintDep(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgPrintDep(KaitaiStream _io, Sbp.Message _parent, Logging _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.text = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private String text;
        private Logging _root;
        private Sbp.Message _parent;

        /**
         * Human-readable string
         */
        public String text() { return text; }
        public Logging _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Logging _root;
    private KaitaiStruct _parent;
    public Logging _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
