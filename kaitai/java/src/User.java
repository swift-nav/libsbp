// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.util.ArrayList;

public class User extends KaitaiStruct {
    public static User fromFile(String fileName) throws IOException {
        return new User(new ByteBufferKaitaiStream(fileName));
    }

    public User(KaitaiStream _io) {
        this(_io, null, null);
    }

    public User(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public User(KaitaiStream _io, KaitaiStruct _parent, User _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * This message can contain any application specific user data up to a
     * maximum length of 255 bytes per message.
     */
    public static class MsgUserData extends KaitaiStruct {
        public static MsgUserData fromFile(String fileName) throws IOException {
            return new MsgUserData(new ByteBufferKaitaiStream(fileName));
        }

        public MsgUserData(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgUserData(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgUserData(KaitaiStream _io, Sbp.Message _parent, User _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.contents = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.contents.add(this._io.readU1());
                    i++;
                }
            }
        }
        private ArrayList<Integer> contents;
        private User _root;
        private Sbp.Message _parent;

        /**
         * User data payload
         */
        public ArrayList<Integer> contents() { return contents; }
        public User _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private User _root;
    private KaitaiStruct _parent;
    public User _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
