// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.nio.charset.Charset;
import java.util.ArrayList;

public class Bootload extends KaitaiStruct {
    public static Bootload fromFile(String fileName) throws IOException {
        return new Bootload(new ByteBufferKaitaiStream(fileName));
    }

    public Bootload(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Bootload(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Bootload(KaitaiStream _io, KaitaiStruct _parent, Bootload _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * The device message from the host reads a unique device identifier from
     * the SwiftNAP, an FPGA. The host requests the ID by sending a
     * MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
     * MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
     * that this ID is tied to the FPGA, and not related to the Piksi's serial
     * number.
     */
    public static class MsgNapDeviceDnaReq extends KaitaiStruct {
        public static MsgNapDeviceDnaReq fromFile(String fileName) throws IOException {
            return new MsgNapDeviceDnaReq(new ByteBufferKaitaiStream(fileName));
        }

        public MsgNapDeviceDnaReq(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgNapDeviceDnaReq(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgNapDeviceDnaReq(KaitaiStream _io, Sbp.Message _parent, Bootload _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
        }
        private Bootload _root;
        private Sbp.Message _parent;
        public Bootload _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The host initiates the bootloader to jump to the application.
     */
    public static class MsgBootloaderJumpToApp extends KaitaiStruct {
        public static MsgBootloaderJumpToApp fromFile(String fileName) throws IOException {
            return new MsgBootloaderJumpToApp(new ByteBufferKaitaiStream(fileName));
        }

        public MsgBootloaderJumpToApp(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgBootloaderJumpToApp(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgBootloaderJumpToApp(KaitaiStream _io, Sbp.Message _parent, Bootload _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.jump = this._io.readU1();
        }
        private int jump;
        private Bootload _root;
        private Sbp.Message _parent;

        /**
         * Ignored by the device
         */
        public int jump() { return jump; }
        public Bootload _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The handshake message response from the device establishes a handshake
     * between the device bootloader and the host. The request from the host is
     * MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader
     * version number and the SBP protocol version number.
     */
    public static class MsgBootloaderHandshakeResp extends KaitaiStruct {
        public static MsgBootloaderHandshakeResp fromFile(String fileName) throws IOException {
            return new MsgBootloaderHandshakeResp(new ByteBufferKaitaiStream(fileName));
        }

        public MsgBootloaderHandshakeResp(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgBootloaderHandshakeResp(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgBootloaderHandshakeResp(KaitaiStream _io, Sbp.Message _parent, Bootload _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.flags = this._io.readU4le();
            this.version = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private long flags;
        private String version;
        private Bootload _root;
        private Sbp.Message _parent;

        /**
         * Bootloader flags
         */
        public long flags() { return flags; }

        /**
         * Bootloader version number
         */
        public String version() { return version; }
        public Bootload _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The device message from the host reads a unique device identifier from
     * the SwiftNAP, an FPGA. The host requests the ID by sending a
     * MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
     * MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
     * that this ID is tied to the FPGA, and not related to the Piksi's serial
     * number.
     */
    public static class MsgNapDeviceDnaResp extends KaitaiStruct {
        public static MsgNapDeviceDnaResp fromFile(String fileName) throws IOException {
            return new MsgNapDeviceDnaResp(new ByteBufferKaitaiStream(fileName));
        }

        public MsgNapDeviceDnaResp(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgNapDeviceDnaResp(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgNapDeviceDnaResp(KaitaiStream _io, Sbp.Message _parent, Bootload _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.dna = new ArrayList<Integer>();
            for (int i = 0; i < 8; i++) {
                this.dna.add(this._io.readU1());
            }
        }
        private ArrayList<Integer> dna;
        private Bootload _root;
        private Sbp.Message _parent;

        /**
         * 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the
         * right.
         */
        public ArrayList<Integer> dna() { return dna; }
        public Bootload _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The handshake message request from the host establishes a handshake
     * between the device bootloader and the host. The response from the device
     * is MSG_BOOTLOADER_HANDSHAKE_RESP.
     */
    public static class MsgBootloaderHandshakeReq extends KaitaiStruct {
        public static MsgBootloaderHandshakeReq fromFile(String fileName) throws IOException {
            return new MsgBootloaderHandshakeReq(new ByteBufferKaitaiStream(fileName));
        }

        public MsgBootloaderHandshakeReq(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgBootloaderHandshakeReq(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgBootloaderHandshakeReq(KaitaiStream _io, Sbp.Message _parent, Bootload _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
        }
        private Bootload _root;
        private Sbp.Message _parent;
        public Bootload _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     */
    public static class MsgBootloaderHandshakeDepA extends KaitaiStruct {
        public static MsgBootloaderHandshakeDepA fromFile(String fileName) throws IOException {
            return new MsgBootloaderHandshakeDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgBootloaderHandshakeDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgBootloaderHandshakeDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgBootloaderHandshakeDepA(KaitaiStream _io, Sbp.Message _parent, Bootload _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.handshake = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.handshake.add(this._io.readU1());
                    i++;
                }
            }
        }
        private ArrayList<Integer> handshake;
        private Bootload _root;
        private Sbp.Message _parent;

        /**
         * Version number string (not NULL terminated)
         */
        public ArrayList<Integer> handshake() { return handshake; }
        public Bootload _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Bootload _root;
    private KaitaiStruct _parent;
    public Bootload _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
