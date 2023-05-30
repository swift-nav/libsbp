// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;

public class Vehicle extends KaitaiStruct {
    public static Vehicle fromFile(String fileName) throws IOException {
        return new Vehicle(new ByteBufferKaitaiStream(fileName));
    }

    public Vehicle(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Vehicle(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Vehicle(KaitaiStream _io, KaitaiStruct _parent, Vehicle _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * Message representing the x component of vehicle velocity in the user
     * frame at the odometry reference point(s) specified by the user. The
     * offset for the odometry reference point and the definition and origin of
     * the user frame are defined through the device settings interface. There
     * are 4 possible user-defined sources of this message which are labeled
     * arbitrarily source 0 through 3. If using "processor time" time tags, the
     * receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
     * becomes available to synchronise odometry measurements with GNSS.
     * Processor time shall roll over to zero after one week.
     */
    public static class MsgOdometry extends KaitaiStruct {
        public static MsgOdometry fromFile(String fileName) throws IOException {
            return new MsgOdometry(new ByteBufferKaitaiStream(fileName));
        }

        public MsgOdometry(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgOdometry(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgOdometry(KaitaiStream _io, Sbp.Message _parent, Vehicle _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.velocity = this._io.readS4le();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int velocity;
        private int flags;
        private Vehicle _root;
        private Sbp.Message _parent;

        /**
         * Time field representing either milliseconds in the GPS Week or local
         * CPU time from the producing system in milliseconds.  See the
         * tow_source flag for the exact source of this timestamp.
         */
        public long tow() { return tow; }

        /**
         * The signed forward component of vehicle velocity.
         */
        public int velocity() { return velocity; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Vehicle _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Message containing the accumulated distance travelled by a wheel located
     * at an odometry reference point defined by the user. The offset for the
     * odometry reference point and the definition and origin of the user frame
     * are defined through the device settings interface. The source of this
     * message is identified by the source field, which is an integer ranging
     * from 0 to 255. The timestamp associated with this message should
     * represent the time when the accumulated tick count reached the value
     * given by the contents of this message as accurately as possible. If
     * using "local CPU time" time tags, the receiving end will expect a
     * `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise
     * wheeltick measurements with GNSS. Local CPU time shall roll over to zero
     * after one week.
     */
    public static class MsgWheeltick extends KaitaiStruct {
        public static MsgWheeltick fromFile(String fileName) throws IOException {
            return new MsgWheeltick(new ByteBufferKaitaiStream(fileName));
        }

        public MsgWheeltick(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgWheeltick(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgWheeltick(KaitaiStream _io, Sbp.Message _parent, Vehicle _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.time = this._io.readU8le();
            this.flags = this._io.readU1();
            this.source = this._io.readU1();
            this.ticks = this._io.readS4le();
        }
        private long time;
        private int flags;
        private int source;
        private int ticks;
        private Vehicle _root;
        private Sbp.Message _parent;

        /**
         * Time field representing either microseconds since the last PPS,
         * microseconds in the GPS Week or local CPU time from the producing
         * system in microseconds. See the synch_type field for the exact
         * meaning of this timestamp.
         */
        public long time() { return time; }

        /**
         * Field indicating the type of timestamp contained in the time field.
         */
        public int flags() { return flags; }

        /**
         * ID of the sensor producing this message
         */
        public int source() { return source; }

        /**
         * Free-running counter of the accumulated distance for this sensor.
         * The counter should be incrementing if travelling into one direction
         * and decrementing when travelling in the opposite direction.
         */
        public int ticks() { return ticks; }
        public Vehicle _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Vehicle _root;
    private KaitaiStruct _parent;
    public Vehicle _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
