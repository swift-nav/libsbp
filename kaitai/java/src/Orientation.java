// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;

public class Orientation extends KaitaiStruct {
    public static Orientation fromFile(String fileName) throws IOException {
        return new Orientation(new ByteBufferKaitaiStream(fileName));
    }

    public Orientation(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Orientation(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Orientation(KaitaiStream _io, KaitaiStruct _parent, Orientation _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * This message reports the baseline heading pointing from the base station
     * to the rover relative to True North. The full GPS time is given by the
     * preceding MSG_GPS_TIME with the matching time-of-week (tow). It is
     * intended that time-matched RTK mode is used when the base station is
     * moving.
     */
    public static class MsgBaselineHeading extends KaitaiStruct {
        public static MsgBaselineHeading fromFile(String fileName) throws IOException {
            return new MsgBaselineHeading(new ByteBufferKaitaiStream(fileName));
        }

        public MsgBaselineHeading(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgBaselineHeading(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgBaselineHeading(KaitaiStream _io, Sbp.Message _parent, Orientation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.heading = this._io.readU4le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private long heading;
        private int nSats;
        private int flags;
        private Orientation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Heading
         */
        public long heading() { return heading; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Orientation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the quaternion vector describing the vehicle body
     * frame's orientation with respect to a local-level NED frame. The
     * components of the vector should sum to a unit vector assuming that the
     * LSB of each component as a value of 2^-31. This message will only be
     * available in future INS versions of Swift Products and is not produced
     * by Piksi Multi or Duro.
     */
    public static class MsgOrientQuat extends KaitaiStruct {
        public static MsgOrientQuat fromFile(String fileName) throws IOException {
            return new MsgOrientQuat(new ByteBufferKaitaiStream(fileName));
        }

        public MsgOrientQuat(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgOrientQuat(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgOrientQuat(KaitaiStream _io, Sbp.Message _parent, Orientation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.w = this._io.readS4le();
            this.x = this._io.readS4le();
            this.y = this._io.readS4le();
            this.z = this._io.readS4le();
            this.wAccuracy = this._io.readF4le();
            this.xAccuracy = this._io.readF4le();
            this.yAccuracy = this._io.readF4le();
            this.zAccuracy = this._io.readF4le();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int w;
        private int x;
        private int y;
        private int z;
        private float wAccuracy;
        private float xAccuracy;
        private float yAccuracy;
        private float zAccuracy;
        private int flags;
        private Orientation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Real component
         */
        public int w() { return w; }

        /**
         * 1st imaginary component
         */
        public int x() { return x; }

        /**
         * 2nd imaginary component
         */
        public int y() { return y; }

        /**
         * 3rd imaginary component
         */
        public int z() { return z; }

        /**
         * Estimated standard deviation of w
         */
        public float wAccuracy() { return wAccuracy; }

        /**
         * Estimated standard deviation of x
         */
        public float xAccuracy() { return xAccuracy; }

        /**
         * Estimated standard deviation of y
         */
        public float yAccuracy() { return yAccuracy; }

        /**
         * Estimated standard deviation of z
         */
        public float zAccuracy() { return zAccuracy; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Orientation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the yaw, pitch, and roll angles of the vehicle body
     * frame. The rotations should applied intrinsically in the order yaw,
     * pitch, and roll in order to rotate the from a frame aligned with the
     * local-level NED frame to the vehicle body frame.  This message will only
     * be available in future INS versions of Swift Products and is not
     * produced by Piksi Multi or Duro.
     */
    public static class MsgOrientEuler extends KaitaiStruct {
        public static MsgOrientEuler fromFile(String fileName) throws IOException {
            return new MsgOrientEuler(new ByteBufferKaitaiStream(fileName));
        }

        public MsgOrientEuler(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgOrientEuler(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgOrientEuler(KaitaiStream _io, Sbp.Message _parent, Orientation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.roll = this._io.readS4le();
            this.pitch = this._io.readS4le();
            this.yaw = this._io.readS4le();
            this.rollAccuracy = this._io.readF4le();
            this.pitchAccuracy = this._io.readF4le();
            this.yawAccuracy = this._io.readF4le();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int roll;
        private int pitch;
        private int yaw;
        private float rollAccuracy;
        private float pitchAccuracy;
        private float yawAccuracy;
        private int flags;
        private Orientation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * rotation about the forward axis of the vehicle
         */
        public int roll() { return roll; }

        /**
         * rotation about the rightward axis of the vehicle
         */
        public int pitch() { return pitch; }

        /**
         * rotation about the downward axis of the vehicle
         */
        public int yaw() { return yaw; }

        /**
         * Estimated standard deviation of roll
         */
        public float rollAccuracy() { return rollAccuracy; }

        /**
         * Estimated standard deviation of pitch
         */
        public float pitchAccuracy() { return pitchAccuracy; }

        /**
         * Estimated standard deviation of yaw
         */
        public float yawAccuracy() { return yawAccuracy; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Orientation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the orientation rates in the vehicle body frame.
     * The values represent the measurements a strapped down gyroscope would
     * make and are not equivalent to the time derivative of the Euler angles.
     * The orientation and origin of the user frame is specified via device
     * settings. By convention, the vehicle x-axis is expected to be aligned
     * with the forward direction, while the vehicle y-axis is expected to be
     * aligned with the right direction, and the vehicle z-axis should be
     * aligned with the down direction. This message will only be available in
     * future INS versions of Swift Products and is not produced by Piksi Multi
     * or Duro.
     */
    public static class MsgAngularRate extends KaitaiStruct {
        public static MsgAngularRate fromFile(String fileName) throws IOException {
            return new MsgAngularRate(new ByteBufferKaitaiStream(fileName));
        }

        public MsgAngularRate(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgAngularRate(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgAngularRate(KaitaiStream _io, Sbp.Message _parent, Orientation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.x = this._io.readS4le();
            this.y = this._io.readS4le();
            this.z = this._io.readS4le();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int x;
        private int y;
        private int z;
        private int flags;
        private Orientation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * angular rate about x axis
         */
        public int x() { return x; }

        /**
         * angular rate about y axis
         */
        public int y() { return y; }

        /**
         * angular rate about z axis
         */
        public int z() { return z; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Orientation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Orientation _root;
    private KaitaiStruct _parent;
    public Orientation _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
