// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.util.ArrayList;

public class Flash extends KaitaiStruct {
    public static Flash fromFile(String fileName) throws IOException {
        return new Flash(new ByteBufferKaitaiStream(fileName));
    }

    public Flash(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Flash(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Flash(KaitaiStream _io, KaitaiStruct _parent, Flash _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * This message defines success or failure codes for a variety of flash
     * memory requests from the host to the device. Flash read and write
     * messages, such as MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return
     * this message on failure.
     */
    public static class MsgFlashDone extends KaitaiStruct {
        public static MsgFlashDone fromFile(String fileName) throws IOException {
            return new MsgFlashDone(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFlashDone(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFlashDone(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFlashDone(KaitaiStream _io, Sbp.Message _parent, Flash _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.response = this._io.readU1();
        }
        private int response;
        private Flash _root;
        private Sbp.Message _parent;

        /**
         * Response flags
         */
        public int response() { return response; }
        public Flash _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The flash status message writes to the 8-bit M25 flash status register.
     * The device replies with a MSG_FLASH_DONE message.
     */
    public static class MsgM25FlashWriteStatus extends KaitaiStruct {
        public static MsgM25FlashWriteStatus fromFile(String fileName) throws IOException {
            return new MsgM25FlashWriteStatus(new ByteBufferKaitaiStream(fileName));
        }

        public MsgM25FlashWriteStatus(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgM25FlashWriteStatus(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgM25FlashWriteStatus(KaitaiStream _io, Sbp.Message _parent, Flash _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.status = new ArrayList<Integer>();
            for (int i = 0; i < 1; i++) {
                this.status.add(this._io.readU1());
            }
        }
        private ArrayList<Integer> status;
        private Flash _root;
        private Sbp.Message _parent;

        /**
         * Byte to write to the M25 flash status register
         */
        public ArrayList<Integer> status() { return status; }
        public Flash _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The flash read message reads a set of addresses of either the STM or M25
     * onboard flash. The device replies with a MSG_FLASH_READ_RESP message
     * containing either the read data on success or a MSG_FLASH_DONE message
     * containing the return code FLASH_INVALID_LEN (2) if the maximum read
     * size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
     * the allowed range.
     */
    public static class MsgFlashReadResp extends KaitaiStruct {
        public static MsgFlashReadResp fromFile(String fileName) throws IOException {
            return new MsgFlashReadResp(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFlashReadResp(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFlashReadResp(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFlashReadResp(KaitaiStream _io, Sbp.Message _parent, Flash _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.target = this._io.readU1();
            this.addrStart = new ArrayList<Integer>();
            for (int i = 0; i < 3; i++) {
                this.addrStart.add(this._io.readU1());
            }
            this.addrLen = this._io.readU1();
        }
        private int target;
        private ArrayList<Integer> addrStart;
        private int addrLen;
        private Flash _root;
        private Sbp.Message _parent;

        /**
         * Target flags
         */
        public int target() { return target; }

        /**
         * Starting address offset to read from
         */
        public ArrayList<Integer> addrStart() { return addrStart; }

        /**
         * Length of set of addresses to read, counting up from starting
         * address
         */
        public int addrLen() { return addrLen; }
        public Flash _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The flash erase message from the host erases a sector of either the STM
     * or M25 onboard flash memory. The device will reply with a MSG_FLASH_DONE
     * message containing the return code - FLASH_OK (0) on success or
     * FLASH_INVALID_FLASH (1) if the flash specified is invalid.
     */
    public static class MsgFlashErase extends KaitaiStruct {
        public static MsgFlashErase fromFile(String fileName) throws IOException {
            return new MsgFlashErase(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFlashErase(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFlashErase(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFlashErase(KaitaiStream _io, Sbp.Message _parent, Flash _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.target = this._io.readU1();
            this.sectorNum = this._io.readU4le();
        }
        private int target;
        private long sectorNum;
        private Flash _root;
        private Sbp.Message _parent;

        /**
         * Target flags
         */
        public int target() { return target; }

        /**
         * Flash sector number to erase (0-11 for the STM, 0-15 for the M25)
         */
        public long sectorNum() { return sectorNum; }
        public Flash _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reads the device's hard-coded unique ID. The host requests
     * the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
     * MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
     */
    public static class MsgStmUniqueIdResp extends KaitaiStruct {
        public static MsgStmUniqueIdResp fromFile(String fileName) throws IOException {
            return new MsgStmUniqueIdResp(new ByteBufferKaitaiStream(fileName));
        }

        public MsgStmUniqueIdResp(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgStmUniqueIdResp(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgStmUniqueIdResp(KaitaiStream _io, Sbp.Message _parent, Flash _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.stmId = new ArrayList<Integer>();
            for (int i = 0; i < 12; i++) {
                this.stmId.add(this._io.readU1());
            }
        }
        private ArrayList<Integer> stmId;
        private Flash _root;
        private Sbp.Message _parent;

        /**
         * Device unique ID
         */
        public ArrayList<Integer> stmId() { return stmId; }
        public Flash _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reads the device's hard-coded unique ID. The host requests
     * the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
     * MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
     */
    public static class MsgStmUniqueIdReq extends KaitaiStruct {
        public static MsgStmUniqueIdReq fromFile(String fileName) throws IOException {
            return new MsgStmUniqueIdReq(new ByteBufferKaitaiStream(fileName));
        }

        public MsgStmUniqueIdReq(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgStmUniqueIdReq(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgStmUniqueIdReq(KaitaiStream _io, Sbp.Message _parent, Flash _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
        }
        private Flash _root;
        private Sbp.Message _parent;
        public Flash _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The flash program message programs a set of addresses of either the STM
     * or M25 flash. The device replies with either a MSG_FLASH_DONE message
     * containing the return code FLASH_OK (0) on success, or FLASH_INVALID_LEN
     * (2) if the maximum write size is exceeded. Note that the sector-
     * containing addresses must be erased before addresses can be programmed.
     */
    public static class MsgFlashProgram extends KaitaiStruct {
        public static MsgFlashProgram fromFile(String fileName) throws IOException {
            return new MsgFlashProgram(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFlashProgram(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFlashProgram(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFlashProgram(KaitaiStream _io, Sbp.Message _parent, Flash _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.target = this._io.readU1();
            this.addrStart = new ArrayList<Integer>();
            for (int i = 0; i < 3; i++) {
                this.addrStart.add(this._io.readU1());
            }
            this.addrLen = this._io.readU1();
            this.data = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.data.add(this._io.readU1());
                    i++;
                }
            }
        }
        private int target;
        private ArrayList<Integer> addrStart;
        private int addrLen;
        private ArrayList<Integer> data;
        private Flash _root;
        private Sbp.Message _parent;

        /**
         * Target flags
         */
        public int target() { return target; }

        /**
         * Starting address offset to program
         */
        public ArrayList<Integer> addrStart() { return addrStart; }

        /**
         * Length of set of addresses to program, counting up from starting
         * address
         */
        public int addrLen() { return addrLen; }

        /**
         * Data to program addresses with, with length N=addr_len
         */
        public ArrayList<Integer> data() { return data; }
        public Flash _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The flash read message reads a set of addresses of either the STM or M25
     * onboard flash. The device replies with a MSG_FLASH_READ_RESP message
     * containing either the read data on success or a MSG_FLASH_DONE message
     * containing the return code FLASH_INVALID_LEN (2) if the maximum read
     * size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
     * the allowed range.
     */
    public static class MsgFlashReadReq extends KaitaiStruct {
        public static MsgFlashReadReq fromFile(String fileName) throws IOException {
            return new MsgFlashReadReq(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFlashReadReq(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFlashReadReq(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFlashReadReq(KaitaiStream _io, Sbp.Message _parent, Flash _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.target = this._io.readU1();
            this.addrStart = new ArrayList<Integer>();
            for (int i = 0; i < 3; i++) {
                this.addrStart.add(this._io.readU1());
            }
            this.addrLen = this._io.readU1();
        }
        private int target;
        private ArrayList<Integer> addrStart;
        private int addrLen;
        private Flash _root;
        private Sbp.Message _parent;

        /**
         * Target flags
         */
        public int target() { return target; }

        /**
         * Starting address offset to read from
         */
        public ArrayList<Integer> addrStart() { return addrStart; }

        /**
         * Length of set of addresses to read, counting up from starting
         * address
         */
        public int addrLen() { return addrLen; }
        public Flash _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The flash unlock message unlocks a sector of the STM flash memory. The
     * device replies with a MSG_FLASH_DONE message.
     */
    public static class MsgStmFlashUnlockSector extends KaitaiStruct {
        public static MsgStmFlashUnlockSector fromFile(String fileName) throws IOException {
            return new MsgStmFlashUnlockSector(new ByteBufferKaitaiStream(fileName));
        }

        public MsgStmFlashUnlockSector(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgStmFlashUnlockSector(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgStmFlashUnlockSector(KaitaiStream _io, Sbp.Message _parent, Flash _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sector = this._io.readU4le();
        }
        private long sector;
        private Flash _root;
        private Sbp.Message _parent;

        /**
         * Flash sector number to unlock
         */
        public long sector() { return sector; }
        public Flash _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The flash lock message locks a sector of the STM flash memory. The
     * device replies with a MSG_FLASH_DONE message.
     */
    public static class MsgStmFlashLockSector extends KaitaiStruct {
        public static MsgStmFlashLockSector fromFile(String fileName) throws IOException {
            return new MsgStmFlashLockSector(new ByteBufferKaitaiStream(fileName));
        }

        public MsgStmFlashLockSector(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgStmFlashLockSector(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgStmFlashLockSector(KaitaiStream _io, Sbp.Message _parent, Flash _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sector = this._io.readU4le();
        }
        private long sector;
        private Flash _root;
        private Sbp.Message _parent;

        /**
         * Flash sector number to lock
         */
        public long sector() { return sector; }
        public Flash _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Flash _root;
    private KaitaiStruct _parent;
    public Flash _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
