// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.util.ArrayList;

public class Integrity extends KaitaiStruct {
    public static Integrity fromFile(String fileName) throws IOException {
        return new Integrity(new ByteBufferKaitaiStream(fileName));
    }

    public Integrity(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Integrity(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Integrity(KaitaiStream _io, KaitaiStruct _parent, Integrity _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }
    public static class MsgSsrFlagSatellites extends KaitaiStruct {
        public static MsgSsrFlagSatellites fromFile(String fileName) throws IOException {
            return new MsgSsrFlagSatellites(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrFlagSatellites(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrFlagSatellites(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrFlagSatellites(KaitaiStream _io, Sbp.Message _parent, Integrity _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.obsTime = new Gnss.GpsTimeSec(this._io, this, _root);
            this.numMsgs = this._io.readU1();
            this.seqNum = this._io.readU1();
            this.ssrSolId = this._io.readU1();
            this.chainId = this._io.readU1();
            this.constId = this._io.readU1();
            this.nFaultySats = this._io.readU1();
            this.faultySats = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.faultySats.add(this._io.readU1());
                    i++;
                }
            }
        }
        private Gnss.GpsTimeSec obsTime;
        private int numMsgs;
        private int seqNum;
        private int ssrSolId;
        private int chainId;
        private int constId;
        private int nFaultySats;
        private ArrayList<Integer> faultySats;
        private Integrity _root;
        private Sbp.Message _parent;

        /**
         * GNSS reference time of the observation used to generate the flag.
         */
        public Gnss.GpsTimeSec obsTime() { return obsTime; }

        /**
         * Number of messages in the dataset
         */
        public int numMsgs() { return numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public int seqNum() { return seqNum; }

        /**
         * SSR Solution ID.
         */
        public int ssrSolId() { return ssrSolId; }

        /**
         * Chain and type of flag.
         */
        public int chainId() { return chainId; }

        /**
         * Constellation ID.
         */
        public int constId() { return constId; }

        /**
         * Number of faulty satellites.
         */
        public int nFaultySats() { return nFaultySats; }

        /**
         * List of faulty satellites.
         */
        public ArrayList<Integer> faultySats() { return faultySats; }
        public Integrity _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class MsgSsrFlagIonoTileSatLos extends KaitaiStruct {
        public static MsgSsrFlagIonoTileSatLos fromFile(String fileName) throws IOException {
            return new MsgSsrFlagIonoTileSatLos(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrFlagIonoTileSatLos(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrFlagIonoTileSatLos(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrFlagIonoTileSatLos(KaitaiStream _io, Sbp.Message _parent, Integrity _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new IntegritySsrHeader(this._io, this, _root);
            this.nFaultyLos = this._io.readU1();
            this.faultyLos = new ArrayList<Gnss.SvId>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.faultyLos.add(new Gnss.SvId(this._io, this, _root));
                    i++;
                }
            }
        }
        private IntegritySsrHeader header;
        private int nFaultyLos;
        private ArrayList<Gnss.SvId> faultyLos;
        private Integrity _root;
        private Sbp.Message _parent;

        /**
         * Header of an integrity message.
         */
        public IntegritySsrHeader header() { return header; }

        /**
         * Number of faulty LOS.
         */
        public int nFaultyLos() { return nFaultyLos; }

        /**
         * List of faulty LOS
         */
        public ArrayList<Gnss.SvId> faultyLos() { return faultyLos; }
        public Integrity _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class MsgSsrFlagIonoGridPointSatLos extends KaitaiStruct {
        public static MsgSsrFlagIonoGridPointSatLos fromFile(String fileName) throws IOException {
            return new MsgSsrFlagIonoGridPointSatLos(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrFlagIonoGridPointSatLos(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrFlagIonoGridPointSatLos(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrFlagIonoGridPointSatLos(KaitaiStream _io, Sbp.Message _parent, Integrity _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new IntegritySsrHeader(this._io, this, _root);
            this.gridPointId = this._io.readU2le();
            this.nFaultyLos = this._io.readU1();
            this.faultyLos = new ArrayList<Gnss.SvId>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.faultyLos.add(new Gnss.SvId(this._io, this, _root));
                    i++;
                }
            }
        }
        private IntegritySsrHeader header;
        private int gridPointId;
        private int nFaultyLos;
        private ArrayList<Gnss.SvId> faultyLos;
        private Integrity _root;
        private Sbp.Message _parent;

        /**
         * Header of an integrity message.
         */
        public IntegritySsrHeader header() { return header; }

        /**
         * Index of the grid point.
         */
        public int gridPointId() { return gridPointId; }

        /**
         * Number of faulty LOS.
         */
        public int nFaultyLos() { return nFaultyLos; }

        /**
         * List of faulty LOS
         */
        public ArrayList<Gnss.SvId> faultyLos() { return faultyLos; }
        public Integrity _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class IntegritySsrHeader extends KaitaiStruct {
        public static IntegritySsrHeader fromFile(String fileName) throws IOException {
            return new IntegritySsrHeader(new ByteBufferKaitaiStream(fileName));
        }

        public IntegritySsrHeader(KaitaiStream _io) {
            this(_io, null, null);
        }

        public IntegritySsrHeader(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public IntegritySsrHeader(KaitaiStream _io, KaitaiStruct _parent, Integrity _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.obsTime = new Gnss.GpsTimeSec(this._io, this, _root);
            this.numMsgs = this._io.readU1();
            this.seqNum = this._io.readU1();
            this.ssrSolId = this._io.readU1();
            this.tileSetId = this._io.readU2le();
            this.tileId = this._io.readU2le();
            this.chainId = this._io.readU1();
        }
        private Gnss.GpsTimeSec obsTime;
        private int numMsgs;
        private int seqNum;
        private int ssrSolId;
        private int tileSetId;
        private int tileId;
        private int chainId;
        private Integrity _root;
        private KaitaiStruct _parent;

        /**
         * GNSS reference time of the observation used to generate the flag.
         */
        public Gnss.GpsTimeSec obsTime() { return obsTime; }

        /**
         * Number of messages in the dataset
         */
        public int numMsgs() { return numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public int seqNum() { return seqNum; }

        /**
         * SSR Solution ID.
         */
        public int ssrSolId() { return ssrSolId; }

        /**
         * Unique identifier of the set this tile belongs to.
         */
        public int tileSetId() { return tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         */
        public int tileId() { return tileId; }

        /**
         * Chain and type of flag.
         */
        public int chainId() { return chainId; }
        public Integrity _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }
    public static class MsgAcknowledge extends KaitaiStruct {
        public static MsgAcknowledge fromFile(String fileName) throws IOException {
            return new MsgAcknowledge(new ByteBufferKaitaiStream(fileName));
        }

        public MsgAcknowledge(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgAcknowledge(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgAcknowledge(KaitaiStream _io, Sbp.Message _parent, Integrity _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.requestId = this._io.readU1();
            this.areaId = this._io.readU4le();
            this.responseCode = this._io.readU1();
            this.correctionMaskOnDemand = this._io.readU2le();
            this.correctionMaskStream = this._io.readU2le();
            this.solutionId = this._io.readU1();
        }
        private int requestId;
        private long areaId;
        private int responseCode;
        private int correctionMaskOnDemand;
        private int correctionMaskStream;
        private int solutionId;
        private Integrity _root;
        private Sbp.Message _parent;

        /**
         * Echo of the request ID field from the corresponding CRA message, or
         * 255 if no request ID was provided.
         */
        public int requestId() { return requestId; }

        /**
         * Echo of the Area ID field from the corresponding CRA message.
         */
        public long areaId() { return areaId; }

        /**
         * Reported status of the request.
         */
        public int responseCode() { return responseCode; }

        /**
         * Contains the message group(s) that will be sent in response from the
         * corresponding CRA correction mask. An echo of the correction mask
         * field from the corresponding CRA message.
         */
        public int correctionMaskOnDemand() { return correctionMaskOnDemand; }

        /**
         * For future expansion. Always set to 0.
         */
        public int correctionMaskStream() { return correctionMaskStream; }

        /**
         * The solution ID of the instance providing the corrections.
         */
        public int solutionId() { return solutionId; }
        public Integrity _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class MsgSsrFlagIonoGridPoints extends KaitaiStruct {
        public static MsgSsrFlagIonoGridPoints fromFile(String fileName) throws IOException {
            return new MsgSsrFlagIonoGridPoints(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrFlagIonoGridPoints(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrFlagIonoGridPoints(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrFlagIonoGridPoints(KaitaiStream _io, Sbp.Message _parent, Integrity _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new IntegritySsrHeader(this._io, this, _root);
            this.nFaultyPoints = this._io.readU1();
            this.faultyPoints = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.faultyPoints.add(this._io.readU2le());
                    i++;
                }
            }
        }
        private IntegritySsrHeader header;
        private int nFaultyPoints;
        private ArrayList<Integer> faultyPoints;
        private Integrity _root;
        private Sbp.Message _parent;

        /**
         * Header of an integrity message.
         */
        public IntegritySsrHeader header() { return header; }

        /**
         * Number of faulty grid points.
         */
        public int nFaultyPoints() { return nFaultyPoints; }

        /**
         * List of faulty grid points.
         */
        public ArrayList<Integer> faultyPoints() { return faultyPoints; }
        public Integrity _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class MsgSsrFlagTropoGridPoints extends KaitaiStruct {
        public static MsgSsrFlagTropoGridPoints fromFile(String fileName) throws IOException {
            return new MsgSsrFlagTropoGridPoints(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrFlagTropoGridPoints(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrFlagTropoGridPoints(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrFlagTropoGridPoints(KaitaiStream _io, Sbp.Message _parent, Integrity _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new IntegritySsrHeader(this._io, this, _root);
            this.nFaultyPoints = this._io.readU1();
            this.faultyPoints = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.faultyPoints.add(this._io.readU2le());
                    i++;
                }
            }
        }
        private IntegritySsrHeader header;
        private int nFaultyPoints;
        private ArrayList<Integer> faultyPoints;
        private Integrity _root;
        private Sbp.Message _parent;

        /**
         * Header of an integrity message.
         */
        public IntegritySsrHeader header() { return header; }

        /**
         * Number of faulty grid points.
         */
        public int nFaultyPoints() { return nFaultyPoints; }

        /**
         * List of faulty grid points.
         */
        public ArrayList<Integer> faultyPoints() { return faultyPoints; }
        public Integrity _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Integrity monitoring flags for multiple aggregated elements. An element
     * could be a satellite, SSR grid point, or SSR tile. A group of aggregated
     * elements being monitored for integrity could refer to:
     * 
     * - Satellites in a particular {GPS, GAL, BDS} constellation.
     * 
     * - Satellites in the line-of-sight of a particular SSR tile.
     * 
     * - Satellites in the line-of-sight of a particular SSR grid point.
     * 
     * The integrity usage for a group of aggregated elements varies according
     * to the integrity flag of the satellites comprising that group.
     * 
     * SSR_INTEGRITY_USAGE_NOMINAL: All satellites received passed the
     * integrity check and have flag INTEGRITY_FLAG_OK.
     * 
     * SSR_INTEGRITY_USAGE_WARNING: A limited number of elements in the group
     * failed the integrity check. Refer to more granular integrity messages
     * for details on the specific failing elements.
     * 
     * SSR_INTEGRITY_USAGE_ALERT: Most elements in the group failed the
     * integrity check, do not use for positioning.
     * 
     * SSR_INTEGRITY_USAGE_NOT_MONITORED: Unable to verify the integrity flag
     * of elements in the group.
     */
    public static class MsgSsrFlagHighLevel extends KaitaiStruct {
        public static MsgSsrFlagHighLevel fromFile(String fileName) throws IOException {
            return new MsgSsrFlagHighLevel(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrFlagHighLevel(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrFlagHighLevel(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrFlagHighLevel(KaitaiStream _io, Sbp.Message _parent, Integrity _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.obsTime = new Gnss.GpsTimeSec(this._io, this, _root);
            this.corrTime = new Gnss.GpsTimeSec(this._io, this, _root);
            this.ssrSolId = this._io.readU1();
            this.tileSetId = this._io.readU2le();
            this.tileId = this._io.readU2le();
            this.chainId = this._io.readU1();
            this.useGpsSat = this._io.readU1();
            this.useGalSat = this._io.readU1();
            this.useBdsSat = this._io.readU1();
            this.reserved = new ArrayList<Integer>();
            for (int i = 0; i < 6; i++) {
                this.reserved.add(this._io.readU1());
            }
            this.useTropoGridPoints = this._io.readU1();
            this.useIonoGridPoints = this._io.readU1();
            this.useIonoTileSatLos = this._io.readU1();
            this.useIonoGridPointSatLos = this._io.readU1();
        }
        private Gnss.GpsTimeSec obsTime;
        private Gnss.GpsTimeSec corrTime;
        private int ssrSolId;
        private int tileSetId;
        private int tileId;
        private int chainId;
        private int useGpsSat;
        private int useGalSat;
        private int useBdsSat;
        private ArrayList<Integer> reserved;
        private int useTropoGridPoints;
        private int useIonoGridPoints;
        private int useIonoTileSatLos;
        private int useIonoGridPointSatLos;
        private Integrity _root;
        private Sbp.Message _parent;

        /**
         * GNSS reference time of the observation used to generate the flag.
         */
        public Gnss.GpsTimeSec obsTime() { return obsTime; }

        /**
         * GNSS reference time of the correction associated to the flag.
         */
        public Gnss.GpsTimeSec corrTime() { return corrTime; }

        /**
         * SSR Solution ID.
         */
        public int ssrSolId() { return ssrSolId; }

        /**
         * Unique identifier of the set this tile belongs to.
         */
        public int tileSetId() { return tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         */
        public int tileId() { return tileId; }

        /**
         * Chain and type of flag.
         */
        public int chainId() { return chainId; }

        /**
         * Use GPS satellites.
         */
        public int useGpsSat() { return useGpsSat; }

        /**
         * Use GAL satellites.
         */
        public int useGalSat() { return useGalSat; }

        /**
         * Use BDS satellites.
         */
        public int useBdsSat() { return useBdsSat; }

        /**
         * Reserved
         */
        public ArrayList<Integer> reserved() { return reserved; }

        /**
         * Use tropo grid points.
         */
        public int useTropoGridPoints() { return useTropoGridPoints; }

        /**
         * Use iono grid points.
         */
        public int useIonoGridPoints() { return useIonoGridPoints; }

        /**
         * Use iono tile satellite LoS.
         */
        public int useIonoTileSatLos() { return useIonoTileSatLos; }

        /**
         * Use iono grid point satellite LoS.
         */
        public int useIonoGridPointSatLos() { return useIonoGridPointSatLos; }
        public Integrity _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Integrity _root;
    private KaitaiStruct _parent;
    public Integrity _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
