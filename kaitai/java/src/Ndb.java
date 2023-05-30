// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;

public class Ndb extends KaitaiStruct {
    public static Ndb fromFile(String fileName) throws IOException {
        return new Ndb(new ByteBufferKaitaiStream(fileName));
    }

    public Ndb(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Ndb(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Ndb(KaitaiStream _io, KaitaiStruct _parent, Ndb _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * This message is sent out when an object is stored into NDB. If needed
     * message could also be sent out when fetching an object from NDB.
     */
    public static class MsgNdbEvent extends KaitaiStruct {
        public static MsgNdbEvent fromFile(String fileName) throws IOException {
            return new MsgNdbEvent(new ByteBufferKaitaiStream(fileName));
        }

        public MsgNdbEvent(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgNdbEvent(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgNdbEvent(KaitaiStream _io, Sbp.Message _parent, Ndb _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.recvTime = this._io.readU8le();
            this.event = this._io.readU1();
            this.objectType = this._io.readU1();
            this.result = this._io.readU1();
            this.dataSource = this._io.readU1();
            this.objectSid = new Gnss.GnssSignal(this._io, this, _root);
            this.srcSid = new Gnss.GnssSignal(this._io, this, _root);
            this.originalSender = this._io.readU2le();
        }
        private long recvTime;
        private int event;
        private int objectType;
        private int result;
        private int dataSource;
        private Gnss.GnssSignal objectSid;
        private Gnss.GnssSignal srcSid;
        private int originalSender;
        private Ndb _root;
        private Sbp.Message _parent;

        /**
         * HW time in milliseconds.
         */
        public long recvTime() { return recvTime; }

        /**
         * Event type.
         */
        public int event() { return event; }

        /**
         * Event object type.
         */
        public int objectType() { return objectType; }

        /**
         * Event result.
         */
        public int result() { return result; }

        /**
         * Data source for STORE event, reserved for other events.
         */
        public int dataSource() { return dataSource; }

        /**
         * GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid
         * indicates for which signal the object belongs to. Reserved in other
         * cases.
         */
        public Gnss.GnssSignal objectSid() { return objectSid; }

        /**
         * GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono
         * OR L2C capabilities AND data_source is NDB_DS_RECEIVER sid indicates
         * from which SV data was decoded. Reserved in other cases.
         */
        public Gnss.GnssSignal srcSid() { return srcSid; }

        /**
         * A unique identifier of the sending hardware. For v1.0, set to the 2
         * least significant bytes of the device serial number, valid only if
         * data_source is NDB_DS_SBP. Reserved in case of other data_source.
         */
        public int originalSender() { return originalSender; }
        public Ndb _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Ndb _root;
    private KaitaiStruct _parent;
    public Ndb _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
