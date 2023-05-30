// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;

public class Imu extends KaitaiStruct {
    public static Imu fromFile(String fileName) throws IOException {
        return new Imu(new ByteBufferKaitaiStream(fileName));
    }

    public Imu(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Imu(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Imu(KaitaiStream _io, KaitaiStruct _parent, Imu _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * Raw data from the Inertial Measurement Unit, containing accelerometer
     * and gyroscope readings. The sense of the measurements are to be aligned
     * with the indications on the device itself. Measurement units, which are
     * specific to the device hardware and settings, are communicated via the
     * MSG_IMU_AUX message. If using "time since startup" time tags, the
     * receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
     * becomes available to synchronise IMU measurements with GNSS. The
     * timestamp must wrap around to zero when reaching one week (604800
     * seconds).
     * 
     * The time-tagging mode should not change throughout a run.
     */
    public static class MsgImuRaw extends KaitaiStruct {
        public static MsgImuRaw fromFile(String fileName) throws IOException {
            return new MsgImuRaw(new ByteBufferKaitaiStream(fileName));
        }

        public MsgImuRaw(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgImuRaw(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgImuRaw(KaitaiStream _io, Sbp.Message _parent, Imu _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.towF = this._io.readU1();
            this.accX = this._io.readS2le();
            this.accY = this._io.readS2le();
            this.accZ = this._io.readS2le();
            this.gyrX = this._io.readS2le();
            this.gyrY = this._io.readS2le();
            this.gyrZ = this._io.readS2le();
        }
        private long tow;
        private int towF;
        private short accX;
        private short accY;
        private short accZ;
        private short gyrX;
        private short gyrY;
        private short gyrZ;
        private Imu _root;
        private Sbp.Message _parent;

        /**
         * Milliseconds since reference epoch and time status.
         */
        public long tow() { return tow; }

        /**
         * Milliseconds since reference epoch, fractional part
         */
        public int towF() { return towF; }

        /**
         * Acceleration in the IMU frame X axis
         */
        public short accX() { return accX; }

        /**
         * Acceleration in the IMU frame Y axis
         */
        public short accY() { return accY; }

        /**
         * Acceleration in the IMU frame Z axis
         */
        public short accZ() { return accZ; }

        /**
         * Angular rate around IMU frame X axis
         */
        public short gyrX() { return gyrX; }

        /**
         * Angular rate around IMU frame Y axis
         */
        public short gyrY() { return gyrY; }

        /**
         * Angular rate around IMU frame Z axis
         */
        public short gyrZ() { return gyrZ; }
        public Imu _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Auxiliary data specific to a particular IMU. The `imu_type` field will
     * always be consistent but the rest of the payload is device specific and
     * depends on the value of `imu_type`.
     */
    public static class MsgImuAux extends KaitaiStruct {
        public static MsgImuAux fromFile(String fileName) throws IOException {
            return new MsgImuAux(new ByteBufferKaitaiStream(fileName));
        }

        public MsgImuAux(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgImuAux(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgImuAux(KaitaiStream _io, Sbp.Message _parent, Imu _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.imuType = this._io.readU1();
            this.temp = this._io.readS2le();
            this.imuConf = this._io.readU1();
        }
        private int imuType;
        private short temp;
        private int imuConf;
        private Imu _root;
        private Sbp.Message _parent;

        /**
         * IMU type
         */
        public int imuType() { return imuType; }

        /**
         * Raw IMU temperature
         */
        public short temp() { return temp; }

        /**
         * IMU configuration
         */
        public int imuConf() { return imuConf; }
        public Imu _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Imu _root;
    private KaitaiStruct _parent;
    public Imu _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
