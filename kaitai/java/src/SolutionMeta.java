// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.util.ArrayList;

public class SolutionMeta extends KaitaiStruct {
    public static SolutionMeta fromFile(String fileName) throws IOException {
        return new SolutionMeta(new ByteBufferKaitaiStream(fileName));
    }

    public SolutionMeta(KaitaiStream _io) {
        this(_io, null, null);
    }

    public SolutionMeta(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public SolutionMeta(KaitaiStream _io, KaitaiStruct _parent, SolutionMeta _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * Metadata around the GNSS sensors involved in the fuzed solution.
     * Accessible through sol_in[N].flags in a MSG_SOLN_META.
     */
    public static class GnssInputType extends KaitaiStruct {
        public static GnssInputType fromFile(String fileName) throws IOException {
            return new GnssInputType(new ByteBufferKaitaiStream(fileName));
        }

        public GnssInputType(KaitaiStream _io) {
            this(_io, null, null);
        }

        public GnssInputType(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public GnssInputType(KaitaiStream _io, KaitaiStruct _parent, SolutionMeta _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.flags = this._io.readU1();
        }
        private int flags;
        private SolutionMeta _root;
        private KaitaiStruct _parent;

        /**
         * flags that store all relevant info specific to this sensor type.
         */
        public int flags() { return flags; }
        public SolutionMeta _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * This message contains all metadata about the sensors received and/or
     * used in computing the sensorfusion solution. It focuses primarily, but
     * not only, on GNSS metadata. Regarding the age of the last received valid
     * GNSS solution, the highest two bits are time status, indicating whether
     * age gnss can or can not be used to retrieve time of measurement (noted
     * TOM, also known as time of validity) If it can, subtract 'age gnss' from
     * 'tow' in navigation messages to get TOM. Can be used before alignment is
     * complete in the Fusion Engine, when output solution is the last received
     * valid GNSS solution and its tow is not a TOM.
     */
    public static class MsgSolnMeta extends KaitaiStruct {
        public static MsgSolnMeta fromFile(String fileName) throws IOException {
            return new MsgSolnMeta(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSolnMeta(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSolnMeta(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSolnMeta(KaitaiStream _io, Sbp.Message _parent, SolutionMeta _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.pdop = this._io.readU2le();
            this.hdop = this._io.readU2le();
            this.vdop = this._io.readU2le();
            this.ageCorrections = this._io.readU2le();
            this.ageGnss = this._io.readU4le();
            this.solIn = new ArrayList<SolutionInputType>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.solIn.add(new SolutionInputType(this._io, this, _root));
                    i++;
                }
            }
        }
        private long tow;
        private int pdop;
        private int hdop;
        private int vdop;
        private int ageCorrections;
        private long ageGnss;
        private ArrayList<SolutionInputType> solIn;
        private SolutionMeta _root;
        private Sbp.Message _parent;

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        public long tow() { return tow; }

        /**
         * Position Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public int pdop() { return pdop; }

        /**
         * Horizontal Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public int hdop() { return hdop; }

        /**
         * Vertical Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public int vdop() { return vdop; }

        /**
         * Age of corrections as per last available AGE_CORRECTIONS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public int ageCorrections() { return ageCorrections; }

        /**
         * Age and Time Status of the last received valid GNSS solution.
         */
        public long ageGnss() { return ageGnss; }

        /**
         * Array of Metadata describing the sensors potentially involved in the
         * solution. Each element in the array represents a single sensor type
         * and consists of flags containing (meta)data pertaining to that
         * specific single sensor. Refer to each (XX)InputType descriptor in
         * the present doc.
         */
        public ArrayList<SolutionInputType> solIn() { return solIn; }
        public SolutionMeta _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Deprecated.
     * 
     * This message contains all metadata about the sensors received and/or
     * used in computing the Fuzed Solution. It focuses primarily, but not
     * only, on GNSS metadata.
     */
    public static class MsgSolnMetaDepA extends KaitaiStruct {
        public static MsgSolnMetaDepA fromFile(String fileName) throws IOException {
            return new MsgSolnMetaDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSolnMetaDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSolnMetaDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSolnMetaDepA(KaitaiStream _io, Sbp.Message _parent, SolutionMeta _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.pdop = this._io.readU2le();
            this.hdop = this._io.readU2le();
            this.vdop = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.ageCorrections = this._io.readU2le();
            this.alignmentStatus = this._io.readU1();
            this.lastUsedGnssPosTow = this._io.readU4le();
            this.lastUsedGnssVelTow = this._io.readU4le();
            this.solIn = new ArrayList<SolutionInputType>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.solIn.add(new SolutionInputType(this._io, this, _root));
                    i++;
                }
            }
        }
        private int pdop;
        private int hdop;
        private int vdop;
        private int nSats;
        private int ageCorrections;
        private int alignmentStatus;
        private long lastUsedGnssPosTow;
        private long lastUsedGnssVelTow;
        private ArrayList<SolutionInputType> solIn;
        private SolutionMeta _root;
        private Sbp.Message _parent;

        /**
         * Position Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public int pdop() { return pdop; }

        /**
         * Horizontal Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public int hdop() { return hdop; }

        /**
         * Vertical Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public int vdop() { return vdop; }

        /**
         * Number of satellites as per last available solution from PVT engine
         */
        public int nSats() { return nSats; }

        /**
         * Age of corrections as per last available AGE_CORRECTIONS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public int ageCorrections() { return ageCorrections; }

        /**
         * State of alignment and the status and receipt of the alignment
         * inputs
         */
        public int alignmentStatus() { return alignmentStatus; }

        /**
         * Tow of last-used GNSS position measurement
         */
        public long lastUsedGnssPosTow() { return lastUsedGnssPosTow; }

        /**
         * Tow of last-used GNSS velocity measurement
         */
        public long lastUsedGnssVelTow() { return lastUsedGnssVelTow; }

        /**
         * Array of Metadata describing the sensors potentially involved in the
         * solution. Each element in the array represents a single sensor type
         * and consists of flags containing (meta)data pertaining to that
         * specific single sensor. Refer to each (XX)InputType descriptor in
         * the present doc.
         */
        public ArrayList<SolutionInputType> solIn() { return solIn; }
        public SolutionMeta _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Metadata around the IMU sensors involved in the fuzed solution.
     * Accessible through sol_in[N].flags in a MSG_SOLN_META.
     */
    public static class ImuInputType extends KaitaiStruct {
        public static ImuInputType fromFile(String fileName) throws IOException {
            return new ImuInputType(new ByteBufferKaitaiStream(fileName));
        }

        public ImuInputType(KaitaiStream _io) {
            this(_io, null, null);
        }

        public ImuInputType(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public ImuInputType(KaitaiStream _io, KaitaiStruct _parent, SolutionMeta _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.flags = this._io.readU1();
        }
        private int flags;
        private SolutionMeta _root;
        private KaitaiStruct _parent;

        /**
         * Instrument time, grade, and architecture for a sensor.
         */
        public int flags() { return flags; }
        public SolutionMeta _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * Metadata around the Odometry sensors involved in the fuzed solution.
     * Accessible through sol_in[N].flags in a MSG_SOLN_META.
     */
    public static class OdoInputType extends KaitaiStruct {
        public static OdoInputType fromFile(String fileName) throws IOException {
            return new OdoInputType(new ByteBufferKaitaiStream(fileName));
        }

        public OdoInputType(KaitaiStream _io) {
            this(_io, null, null);
        }

        public OdoInputType(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public OdoInputType(KaitaiStream _io, KaitaiStruct _parent, SolutionMeta _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.flags = this._io.readU1();
        }
        private int flags;
        private SolutionMeta _root;
        private KaitaiStruct _parent;

        /**
         * Instrument ODO rate, grade, and quality.
         */
        public int flags() { return flags; }
        public SolutionMeta _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * Metadata describing which sensors were involved in the solution. The
     * structure is fixed no matter what the actual sensor type is. The
     * sensor_type field tells you which sensor we are talking about. It also
     * tells you whether the sensor data was actually used or not. The flags
     * field, always a u8, contains the sensor-specific data. The content of
     * flags, for each sensor type, is described in the relevant structures in
     * this section.
     */
    public static class SolutionInputType extends KaitaiStruct {
        public static SolutionInputType fromFile(String fileName) throws IOException {
            return new SolutionInputType(new ByteBufferKaitaiStream(fileName));
        }

        public SolutionInputType(KaitaiStream _io) {
            this(_io, null, null);
        }

        public SolutionInputType(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public SolutionInputType(KaitaiStream _io, KaitaiStruct _parent, SolutionMeta _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sensorType = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private int sensorType;
        private int flags;
        private SolutionMeta _root;
        private KaitaiStruct _parent;

        /**
         * The type of sensor
         */
        public int sensorType() { return sensorType; }

        /**
         * Refer to each InputType description
         */
        public int flags() { return flags; }
        public SolutionMeta _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }
    private SolutionMeta _root;
    private KaitaiStruct _parent;
    public SolutionMeta _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
