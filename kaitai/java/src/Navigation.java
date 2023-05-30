// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.nio.charset.Charset;
import java.util.ArrayList;

public class Navigation extends KaitaiStruct {
    public static Navigation fromFile(String fileName) throws IOException {
        return new Navigation(new ByteBufferKaitaiStream(fileName));
    }

    public Navigation(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Navigation(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Navigation(KaitaiStream _io, KaitaiStruct _parent, Navigation _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * This position solution message reports the absolute geodetic coordinates
     * and the status (single point vs pseudo-absolute RTK) of the position
     * solution. If the rover receiver knows the surveyed position of the base
     * station and has an RTK solution, this reports a pseudo-absolute position
     * solution using the base station position and the rover's RTK baseline
     * vector. The full GPS time is given by the preceding MSG_GPS_TIME with
     * the matching time-of-week (tow).
     */
    public static class MsgPosLlhDepA extends KaitaiStruct {
        public static MsgPosLlhDepA fromFile(String fileName) throws IOException {
            return new MsgPosLlhDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgPosLlhDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgPosLlhDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgPosLlhDepA(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.lat = this._io.readF8le();
            this.lon = this._io.readF8le();
            this.height = this._io.readF8le();
            this.hAccuracy = this._io.readU2le();
            this.vAccuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private double lat;
        private double lon;
        private double height;
        private int hAccuracy;
        private int vAccuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Latitude
         */
        public double lat() { return lat; }

        /**
         * Longitude
         */
        public double lon() { return lon; }

        /**
         * Height
         */
        public double height() { return height; }

        /**
         * Horizontal position accuracy estimate (not implemented). Defaults to
         * 0.
         */
        public int hAccuracy() { return hAccuracy; }

        /**
         * Vertical position accuracy estimate (not implemented). Defaults to
         * 0.
         */
        public int vAccuracy() { return vAccuracy; }

        /**
         * Number of satellites used in solution.
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the local vertical and horizontal protection levels
     * associated with a given LLH position solution. The full GPS time is
     * given by the preceding MSG_GPS_TIME with the matching time-of-week
     * (tow).
     */
    public static class MsgProtectionLevelDepA extends KaitaiStruct {
        public static MsgProtectionLevelDepA fromFile(String fileName) throws IOException {
            return new MsgProtectionLevelDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgProtectionLevelDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgProtectionLevelDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgProtectionLevelDepA(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.vpl = this._io.readU2le();
            this.hpl = this._io.readU2le();
            this.lat = this._io.readF8le();
            this.lon = this._io.readF8le();
            this.height = this._io.readF8le();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int vpl;
        private int hpl;
        private double lat;
        private double lon;
        private double height;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Vertical protection level
         */
        public int vpl() { return vpl; }

        /**
         * Horizontal protection level
         */
        public int hpl() { return hpl; }

        /**
         * Latitude
         */
        public double lat() { return lat; }

        /**
         * Longitude
         */
        public double lon() { return lon; }

        /**
         * Height
         */
        public double height() { return height; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This position solution message reports the absolute geodetic coordinates
     * and the status (single point vs pseudo-absolute RTK) of the position
     * solution as well as the upper triangle of the 3x3 covariance matrix.
     * The position information and Fix Mode flags follow the MSG_POS_LLH
     * message.  Since the covariance matrix is computed in the local-level
     * North, East, Down frame, the covariance terms follow that convention.
     * Thus, covariances are reported against the "downward" measurement and
     * care should be taken with the sign convention.
     */
    public static class MsgPosLlhCov extends KaitaiStruct {
        public static MsgPosLlhCov fromFile(String fileName) throws IOException {
            return new MsgPosLlhCov(new ByteBufferKaitaiStream(fileName));
        }

        public MsgPosLlhCov(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgPosLlhCov(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgPosLlhCov(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.lat = this._io.readF8le();
            this.lon = this._io.readF8le();
            this.height = this._io.readF8le();
            this.covNN = this._io.readF4le();
            this.covNE = this._io.readF4le();
            this.covND = this._io.readF4le();
            this.covEE = this._io.readF4le();
            this.covED = this._io.readF4le();
            this.covDD = this._io.readF4le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private double lat;
        private double lon;
        private double height;
        private float covNN;
        private float covNE;
        private float covND;
        private float covEE;
        private float covED;
        private float covDD;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Latitude
         */
        public double lat() { return lat; }

        /**
         * Longitude
         */
        public double lon() { return lon; }

        /**
         * Height above WGS84 ellipsoid
         */
        public double height() { return height; }

        /**
         * Estimated variance of northing
         */
        public float covNN() { return covNN; }

        /**
         * Covariance of northing and easting
         */
        public float covNE() { return covNE; }

        /**
         * Covariance of northing and downward measurement
         */
        public float covND() { return covND; }

        /**
         * Estimated variance of easting
         */
        public float covEE() { return covEE; }

        /**
         * Covariance of easting and downward measurement
         */
        public float covED() { return covED; }

        /**
         * Estimated variance of downward measurement
         */
        public float covDD() { return covDD; }

        /**
         * Number of satellites used in solution.
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the velocity in local North East Down (NED)
     * coordinates. The NED coordinate system is defined as the local WGS84
     * tangent plane centered at the current position. The full GPS time is
     * given by the preceding MSG_GPS_TIME with the matching time-of-week
     * (tow).
     */
    public static class MsgVelNedDepA extends KaitaiStruct {
        public static MsgVelNedDepA fromFile(String fileName) throws IOException {
            return new MsgVelNedDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgVelNedDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgVelNedDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgVelNedDepA(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.n = this._io.readS4le();
            this.e = this._io.readS4le();
            this.d = this._io.readS4le();
            this.hAccuracy = this._io.readU2le();
            this.vAccuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int n;
        private int e;
        private int d;
        private int hAccuracy;
        private int vAccuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Velocity North coordinate
         */
        public int n() { return n; }

        /**
         * Velocity East coordinate
         */
        public int e() { return e; }

        /**
         * Velocity Down coordinate
         */
        public int d() { return d; }

        /**
         * Horizontal velocity accuracy estimate (not implemented). Defaults to
         * 0.
         */
        public int hAccuracy() { return hAccuracy; }

        /**
         * Vertical velocity accuracy estimate (not implemented). Defaults to
         * 0.
         */
        public int vAccuracy() { return vAccuracy; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags (reserved)
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the velocity in local North East Down (NED)
     * coordinates. The NED coordinate system is defined as the local WGS84
     * tangent plane centered at the current position. The full GPS time is
     * given by the preceding MSG_GPS_TIME with the matching time-of-week
     * (tow). This message is similar to the MSG_VEL_NED, but it includes the
     * upper triangular portion of the 3x3 covariance matrix.
     */
    public static class MsgVelNedCov extends KaitaiStruct {
        public static MsgVelNedCov fromFile(String fileName) throws IOException {
            return new MsgVelNedCov(new ByteBufferKaitaiStream(fileName));
        }

        public MsgVelNedCov(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgVelNedCov(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgVelNedCov(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.n = this._io.readS4le();
            this.e = this._io.readS4le();
            this.d = this._io.readS4le();
            this.covNN = this._io.readF4le();
            this.covNE = this._io.readF4le();
            this.covND = this._io.readF4le();
            this.covEE = this._io.readF4le();
            this.covED = this._io.readF4le();
            this.covDD = this._io.readF4le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int n;
        private int e;
        private int d;
        private float covNN;
        private float covNE;
        private float covND;
        private float covEE;
        private float covED;
        private float covDD;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Velocity North coordinate
         */
        public int n() { return n; }

        /**
         * Velocity East coordinate
         */
        public int e() { return e; }

        /**
         * Velocity Down coordinate
         */
        public int d() { return d; }

        /**
         * Estimated variance of northward measurement
         */
        public float covNN() { return covNN; }

        /**
         * Covariance of northward and eastward measurement
         */
        public float covNE() { return covNE; }

        /**
         * Covariance of northward and downward measurement
         */
        public float covND() { return covND; }

        /**
         * Estimated variance of eastward measurement
         */
        public float covEE() { return covEE; }

        /**
         * Covariance of eastward and downward measurement
         */
        public float covED() { return covED; }

        /**
         * Estimated variance of downward measurement
         */
        public float covDD() { return covDD; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the Universal Coordinated Time (UTC).  Note the
     * flags which indicate the source of the UTC offset value and source of
     * the time fix.
     */
    public static class MsgUtcTime extends KaitaiStruct {
        public static MsgUtcTime fromFile(String fileName) throws IOException {
            return new MsgUtcTime(new ByteBufferKaitaiStream(fileName));
        }

        public MsgUtcTime(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgUtcTime(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgUtcTime(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.flags = this._io.readU1();
            this.tow = this._io.readU4le();
            this.year = this._io.readU2le();
            this.month = this._io.readU1();
            this.day = this._io.readU1();
            this.hours = this._io.readU1();
            this.minutes = this._io.readU1();
            this.seconds = this._io.readU1();
            this.ns = this._io.readU4le();
        }
        private int flags;
        private long tow;
        private int year;
        private int month;
        private int day;
        private int hours;
        private int minutes;
        private int seconds;
        private long ns;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * Indicates source and time validity
         */
        public int flags() { return flags; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        public long tow() { return tow; }

        /**
         * Year
         */
        public int year() { return year; }

        /**
         * Month (range 1 .. 12)
         */
        public int month() { return month; }

        /**
         * days in the month (range 1-31)
         */
        public int day() { return day; }

        /**
         * hours of day (range 0-23)
         */
        public int hours() { return hours; }

        /**
         * minutes of hour (range 0-59)
         */
        public int minutes() { return minutes; }

        /**
         * seconds of minute (range 0-60) rounded down
         */
        public int seconds() { return seconds; }

        /**
         * nanoseconds of second (range 0-999999999)
         */
        public long ns() { return ns; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The position solution message reports absolute Earth Centered Earth
     * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
     * RTK) of the position solution. The message also reports the upper
     * triangular portion of the 3x3 covariance matrix. If the receiver knows
     * the surveyed position of the base station and has an RTK solution, this
     * reports a pseudo-absolute position solution using the base station
     * position and the rover's RTK baseline vector. The full GPS time is given
     * by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
     */
    public static class MsgPosEcefCovGnss extends KaitaiStruct {
        public static MsgPosEcefCovGnss fromFile(String fileName) throws IOException {
            return new MsgPosEcefCovGnss(new ByteBufferKaitaiStream(fileName));
        }

        public MsgPosEcefCovGnss(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgPosEcefCovGnss(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgPosEcefCovGnss(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.x = this._io.readF8le();
            this.y = this._io.readF8le();
            this.z = this._io.readF8le();
            this.covXX = this._io.readF4le();
            this.covXY = this._io.readF4le();
            this.covXZ = this._io.readF4le();
            this.covYY = this._io.readF4le();
            this.covYZ = this._io.readF4le();
            this.covZZ = this._io.readF4le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private double x;
        private double y;
        private double z;
        private float covXX;
        private float covXY;
        private float covXZ;
        private float covYY;
        private float covYZ;
        private float covZZ;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * ECEF X coordinate
         */
        public double x() { return x; }

        /**
         * ECEF Y coordinate
         */
        public double y() { return y; }

        /**
         * ECEF Z coordinate
         */
        public double z() { return z; }

        /**
         * Estimated variance of x
         */
        public float covXX() { return covXX; }

        /**
         * Estimated covariance of x and y
         */
        public float covXY() { return covXY; }

        /**
         * Estimated covariance of x and z
         */
        public float covXZ() { return covXZ; }

        /**
         * Estimated variance of y
         */
        public float covYY() { return covYY; }

        /**
         * Estimated covariance of y and z
         */
        public float covYZ() { return covYZ; }

        /**
         * Estimated variance of z
         */
        public float covZZ() { return covZZ; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the velocity in local North East Down (NED)
     * coordinates. The NED coordinate system is defined as the local WGS84
     * tangent plane centered at the current position. The full GPS time is
     * given by the preceding MSG_GPS_TIME with the matching time-of-week
     * (tow).
     */
    public static class MsgVelNedGnss extends KaitaiStruct {
        public static MsgVelNedGnss fromFile(String fileName) throws IOException {
            return new MsgVelNedGnss(new ByteBufferKaitaiStream(fileName));
        }

        public MsgVelNedGnss(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgVelNedGnss(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgVelNedGnss(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.n = this._io.readS4le();
            this.e = this._io.readS4le();
            this.d = this._io.readS4le();
            this.hAccuracy = this._io.readU2le();
            this.vAccuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int n;
        private int e;
        private int d;
        private int hAccuracy;
        private int vAccuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Velocity North coordinate
         */
        public int n() { return n; }

        /**
         * Velocity East coordinate
         */
        public int e() { return e; }

        /**
         * Velocity Down coordinate
         */
        public int d() { return d; }

        /**
         * Horizontal velocity estimated standard deviation
         */
        public int hAccuracy() { return hAccuracy; }

        /**
         * Vertical velocity estimated standard deviation
         */
        public int vAccuracy() { return vAccuracy; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the velocity in local North East Down (NED)
     * coordinates. The NED coordinate system is defined as the local WGS84
     * tangent plane centered at the current position. The full GPS time is
     * given by the preceding MSG_GPS_TIME with the matching time-of-week
     * (tow). This message is similar to the MSG_VEL_NED, but it includes the
     * upper triangular portion of the 3x3 covariance matrix.
     */
    public static class MsgVelNedCovGnss extends KaitaiStruct {
        public static MsgVelNedCovGnss fromFile(String fileName) throws IOException {
            return new MsgVelNedCovGnss(new ByteBufferKaitaiStream(fileName));
        }

        public MsgVelNedCovGnss(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgVelNedCovGnss(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgVelNedCovGnss(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.n = this._io.readS4le();
            this.e = this._io.readS4le();
            this.d = this._io.readS4le();
            this.covNN = this._io.readF4le();
            this.covNE = this._io.readF4le();
            this.covND = this._io.readF4le();
            this.covEE = this._io.readF4le();
            this.covED = this._io.readF4le();
            this.covDD = this._io.readF4le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int n;
        private int e;
        private int d;
        private float covNN;
        private float covNE;
        private float covND;
        private float covEE;
        private float covED;
        private float covDD;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Velocity North coordinate
         */
        public int n() { return n; }

        /**
         * Velocity East coordinate
         */
        public int e() { return e; }

        /**
         * Velocity Down coordinate
         */
        public int d() { return d; }

        /**
         * Estimated variance of northward measurement
         */
        public float covNN() { return covNN; }

        /**
         * Covariance of northward and eastward measurement
         */
        public float covNE() { return covNE; }

        /**
         * Covariance of northward and downward measurement
         */
        public float covND() { return covND; }

        /**
         * Estimated variance of eastward measurement
         */
        public float covEE() { return covEE; }

        /**
         * Covariance of eastward and downward measurement
         */
        public float covED() { return covED; }

        /**
         * Estimated variance of downward measurement
         */
        public float covDD() { return covDD; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the baseline solution in North East Down (NED)
     * coordinates. This baseline is the relative vector distance from the base
     * station to the rover receiver, and NED coordinate system is defined at
     * the local WGS84 tangent plane centered at the base station position.
     * The full GPS time is given by the preceding MSG_GPS_TIME with the
     * matching time-of-week (tow).
     */
    public static class MsgBaselineNedDepA extends KaitaiStruct {
        public static MsgBaselineNedDepA fromFile(String fileName) throws IOException {
            return new MsgBaselineNedDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgBaselineNedDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgBaselineNedDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgBaselineNedDepA(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.n = this._io.readS4le();
            this.e = this._io.readS4le();
            this.d = this._io.readS4le();
            this.hAccuracy = this._io.readU2le();
            this.vAccuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int n;
        private int e;
        private int d;
        private int hAccuracy;
        private int vAccuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Baseline North coordinate
         */
        public int n() { return n; }

        /**
         * Baseline East coordinate
         */
        public int e() { return e; }

        /**
         * Baseline Down coordinate
         */
        public int d() { return d; }

        /**
         * Horizontal position accuracy estimate (not implemented). Defaults to
         * 0.
         */
        public int hAccuracy() { return hAccuracy; }

        /**
         * Vertical position accuracy estimate (not implemented). Defaults to
         * 0.
         */
        public int vAccuracy() { return vAccuracy; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
     * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
     * with the matching time-of-week (tow).
     */
    public static class MsgVelEcefDepA extends KaitaiStruct {
        public static MsgVelEcefDepA fromFile(String fileName) throws IOException {
            return new MsgVelEcefDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgVelEcefDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgVelEcefDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgVelEcefDepA(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
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
            this.accuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int x;
        private int y;
        private int z;
        private int accuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Velocity ECEF X coordinate
         */
        public int x() { return x; }

        /**
         * Velocity ECEF Y coordinate
         */
        public int y() { return y; }

        /**
         * Velocity ECEF Z coordinate
         */
        public int z() { return z; }

        /**
         * Velocity accuracy estimate (not implemented). Defaults to 0.
         */
        public int accuracy() { return accuracy; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags (reserved)
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class MsgReferenceFrameParam extends KaitaiStruct {
        public static MsgReferenceFrameParam fromFile(String fileName) throws IOException {
            return new MsgReferenceFrameParam(new ByteBufferKaitaiStream(fileName));
        }

        public MsgReferenceFrameParam(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgReferenceFrameParam(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgReferenceFrameParam(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.ssrIod = this._io.readU1();
            this.sn = new String(this._io.readBytesFull(), Charset.forName("ascii"));
            this.tn = new String(this._io.readBytesFull(), Charset.forName("ascii"));
            this.sin = this._io.readU1();
            this.utn = this._io.readU2le();
            this.reT0 = this._io.readU2le();
            this.deltaX0 = this._io.readS4le();
            this.deltaY0 = this._io.readS4le();
            this.deltaZ0 = this._io.readS4le();
            this.theta01 = this._io.readS4le();
            this.theta02 = this._io.readS4le();
            this.theta03 = this._io.readS4le();
            this.scale = this._io.readS4le();
            this.dotDeltaX0 = this._io.readS4le();
            this.dotDeltaY0 = this._io.readS4le();
            this.dotDeltaZ0 = this._io.readS4le();
            this.dotTheta01 = this._io.readS4le();
            this.dotTheta02 = this._io.readS4le();
            this.dotTheta03 = this._io.readS4le();
            this.dotScale = this._io.readS2le();
        }
        private int ssrIod;
        private String sn;
        private String tn;
        private int sin;
        private int utn;
        private int reT0;
        private int deltaX0;
        private int deltaY0;
        private int deltaZ0;
        private int theta01;
        private int theta02;
        private int theta03;
        private int scale;
        private int dotDeltaX0;
        private int dotDeltaY0;
        private int dotDeltaZ0;
        private int dotTheta01;
        private int dotTheta02;
        private int dotTheta03;
        private short dotScale;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * SSR IOD parameter.
         */
        public int ssrIod() { return ssrIod; }

        /**
         * Name of source coordinate-system.
         */
        public String sn() { return sn; }

        /**
         * Name of target coordinate-system.
         */
        public String tn() { return tn; }

        /**
         * System Identification Number.
         */
        public int sin() { return sin; }

        /**
         * Utilized Transformation Message.
         */
        public int utn() { return utn; }

        /**
         * Reference Epoch t0 for transformation parameter set given as
         * Modified Julian Day (MJD) Number minus 44244 days.
         */
        public int reT0() { return reT0; }

        /**
         * Translation in X for Reference Epoch t0.
         */
        public int deltaX0() { return deltaX0; }

        /**
         * Translation in Y for Reference Epoch t0.
         */
        public int deltaY0() { return deltaY0; }

        /**
         * Translation in Z for Reference Epoch t0.
         */
        public int deltaZ0() { return deltaZ0; }

        /**
         * Rotation around the X-axis for Reference Epoch t0.
         */
        public int theta01() { return theta01; }

        /**
         * Rotation around the Y-axis for Reference Epoch t0.
         */
        public int theta02() { return theta02; }

        /**
         * Rotation around the Z-axis for Reference Epoch t0.
         */
        public int theta03() { return theta03; }

        /**
         * Scale correction for Reference Epoch t0.
         */
        public int scale() { return scale; }

        /**
         * Rate of change of translation in X.
         */
        public int dotDeltaX0() { return dotDeltaX0; }

        /**
         * Rate of change of translation in Y.
         */
        public int dotDeltaY0() { return dotDeltaY0; }

        /**
         * Rate of change of translation in Z.
         */
        public int dotDeltaZ0() { return dotDeltaZ0; }

        /**
         * Rate of change of rotation around the X-axis.
         */
        public int dotTheta01() { return dotTheta01; }

        /**
         * Rate of change of rotation around the Y-axis.
         */
        public int dotTheta02() { return dotTheta02; }

        /**
         * Rate of change of rotation around the Z-axis.
         */
        public int dotTheta03() { return dotTheta03; }

        /**
         * Rate of change of scale correction.
         */
        public short dotScale() { return dotScale; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This solution message reports the relative pose of a sensor between two
     * time instances. The relative pose comprises of a rotation and a
     * translation which relates the sensor (e.g. camera) frame at a given time
     * (first keyframe) to the sensor frame at another time (second keyframe).
     * The relative translations is a 3x1 vector described in the first
     * keyframe.  Relative rotation is described by a quaternion from second
     * keyframe to the first keyframe.
     */
    public static class MsgPoseRelative extends KaitaiStruct {
        public static MsgPoseRelative fromFile(String fileName) throws IOException {
            return new MsgPoseRelative(new ByteBufferKaitaiStream(fileName));
        }

        public MsgPoseRelative(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgPoseRelative(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgPoseRelative(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.sensorId = this._io.readU1();
            this.timestamp1 = this._io.readU4le();
            this.timestamp2 = this._io.readU4le();
            this.trans = new ArrayList<Integer>();
            for (int i = 0; i < 3; i++) {
                this.trans.add(this._io.readS4le());
            }
            this.w = this._io.readS4le();
            this.x = this._io.readS4le();
            this.y = this._io.readS4le();
            this.z = this._io.readS4le();
            this.covRXX = this._io.readF4le();
            this.covRXY = this._io.readF4le();
            this.covRXZ = this._io.readF4le();
            this.covRYY = this._io.readF4le();
            this.covRYZ = this._io.readF4le();
            this.covRZZ = this._io.readF4le();
            this.covCXX = this._io.readF4le();
            this.covCXY = this._io.readF4le();
            this.covCXZ = this._io.readF4le();
            this.covCYY = this._io.readF4le();
            this.covCYZ = this._io.readF4le();
            this.covCZZ = this._io.readF4le();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int sensorId;
        private long timestamp1;
        private long timestamp2;
        private ArrayList<Integer> trans;
        private int w;
        private int x;
        private int y;
        private int z;
        private float covRXX;
        private float covRXY;
        private float covRXZ;
        private float covRYY;
        private float covRYZ;
        private float covRZZ;
        private float covCXX;
        private float covCXY;
        private float covCXZ;
        private float covCYY;
        private float covCYZ;
        private float covCZZ;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * ID of the sensor producing this message
         */
        public int sensorId() { return sensorId; }

        /**
         * Timestamp of first keyframe
         */
        public long timestamp1() { return timestamp1; }

        /**
         * Timestamp of second keyframe
         */
        public long timestamp2() { return timestamp2; }

        /**
         * Relative translation [x,y,z] described in first keyframe
         */
        public ArrayList<Integer> trans() { return trans; }

        /**
         * Real component of quaternion to describe relative rotation (second
         * to first keyframe)
         */
        public int w() { return w; }

        /**
         * 1st imaginary component of quaternion to describe relative rotation
         * (second to first keyframe)
         */
        public int x() { return x; }

        /**
         * 2nd imaginary component of quaternion to describe relative rotation
         * (second to first keyframe)
         */
        public int y() { return y; }

        /**
         * 3rd imaginary component of quaternion to describe relative rotation
         * (second to first keyframe)
         */
        public int z() { return z; }

        /**
         * Estimated variance of x (relative translation)
         */
        public float covRXX() { return covRXX; }

        /**
         * Covariance of x and y (relative translation)
         */
        public float covRXY() { return covRXY; }

        /**
         * Covariance of x and z (relative translation)
         */
        public float covRXZ() { return covRXZ; }

        /**
         * Estimated variance of y (relative translation)
         */
        public float covRYY() { return covRYY; }

        /**
         * Covariance of y and z (relative translation)
         */
        public float covRYZ() { return covRYZ; }

        /**
         * Estimated variance of z (relative translation)
         */
        public float covRZZ() { return covRZZ; }

        /**
         * Estimated variance of x (relative rotation)
         */
        public float covCXX() { return covCXX; }

        /**
         * Covariance of x and y (relative rotation)
         */
        public float covCXY() { return covCXY; }

        /**
         * Covariance of x and z (relative rotation)
         */
        public float covCXZ() { return covCXZ; }

        /**
         * Estimated variance of y (relative rotation)
         */
        public float covCYY() { return covCYY; }

        /**
         * Covariance of y and z (relative rotation)
         */
        public float covCYZ() { return covCYZ; }

        /**
         * Estimated variance of z (relative rotation)
         */
        public float covCZZ() { return covCZZ; }

        /**
         * Status flags of relative translation and rotation
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
     * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
     * with the matching time-of-week (tow).
     */
    public static class MsgVelEcefCov extends KaitaiStruct {
        public static MsgVelEcefCov fromFile(String fileName) throws IOException {
            return new MsgVelEcefCov(new ByteBufferKaitaiStream(fileName));
        }

        public MsgVelEcefCov(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgVelEcefCov(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgVelEcefCov(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
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
            this.covXX = this._io.readF4le();
            this.covXY = this._io.readF4le();
            this.covXZ = this._io.readF4le();
            this.covYY = this._io.readF4le();
            this.covYZ = this._io.readF4le();
            this.covZZ = this._io.readF4le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int x;
        private int y;
        private int z;
        private float covXX;
        private float covXY;
        private float covXZ;
        private float covYY;
        private float covYZ;
        private float covZZ;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Velocity ECEF X coordinate
         */
        public int x() { return x; }

        /**
         * Velocity ECEF Y coordinate
         */
        public int y() { return y; }

        /**
         * Velocity ECEF Z coordinate
         */
        public int z() { return z; }

        /**
         * Estimated variance of x
         */
        public float covXX() { return covXX; }

        /**
         * Estimated covariance of x and y
         */
        public float covXY() { return covXY; }

        /**
         * Estimated covariance of x and z
         */
        public float covXZ() { return covXZ; }

        /**
         * Estimated variance of y
         */
        public float covYY() { return covYY; }

        /**
         * Estimated covariance of y and z
         */
        public float covYZ() { return covYZ; }

        /**
         * Estimated variance of z
         */
        public float covZZ() { return covZZ; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the velocity in the Vehicle Body Frame. By
     * convention, the x-axis should point out the nose of the vehicle and
     * represent the forward direction, while as the y-axis should point out
     * the right hand side of the vehicle. Since this is a right handed system,
     * z should point out the bottom of the vehicle. The orientation and origin
     * of the Vehicle Body Frame are specified via the device settings. The
     * full GPS time is given by the preceding MSG_GPS_TIME with the matching
     * time-of-week (tow). This message is only produced by inertial versions
     * of Swift products and is not available from Piksi Multi or Duro.
     */
    public static class MsgVelBody extends KaitaiStruct {
        public static MsgVelBody fromFile(String fileName) throws IOException {
            return new MsgVelBody(new ByteBufferKaitaiStream(fileName));
        }

        public MsgVelBody(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgVelBody(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgVelBody(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
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
            this.covXX = this._io.readF4le();
            this.covXY = this._io.readF4le();
            this.covXZ = this._io.readF4le();
            this.covYY = this._io.readF4le();
            this.covYZ = this._io.readF4le();
            this.covZZ = this._io.readF4le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int x;
        private int y;
        private int z;
        private float covXX;
        private float covXY;
        private float covXZ;
        private float covYY;
        private float covYZ;
        private float covZZ;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Velocity in x direction
         */
        public int x() { return x; }

        /**
         * Velocity in y direction
         */
        public int y() { return y; }

        /**
         * Velocity in z direction
         */
        public int z() { return z; }

        /**
         * Estimated variance of x
         */
        public float covXX() { return covXX; }

        /**
         * Covariance of x and y
         */
        public float covXY() { return covXY; }

        /**
         * Covariance of x and z
         */
        public float covXZ() { return covXZ; }

        /**
         * Estimated variance of y
         */
        public float covYY() { return covYY; }

        /**
         * Covariance of y and z
         */
        public float covYZ() { return covYZ; }

        /**
         * Estimated variance of z
         */
        public float covZZ() { return covZZ; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
     * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
     * with the matching time-of-week (tow).
     */
    public static class MsgVelEcefGnss extends KaitaiStruct {
        public static MsgVelEcefGnss fromFile(String fileName) throws IOException {
            return new MsgVelEcefGnss(new ByteBufferKaitaiStream(fileName));
        }

        public MsgVelEcefGnss(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgVelEcefGnss(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgVelEcefGnss(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
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
            this.accuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int x;
        private int y;
        private int z;
        private int accuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Velocity ECEF X coordinate
         */
        public int x() { return x; }

        /**
         * Velocity ECEF Y coordinate
         */
        public int y() { return y; }

        /**
         * Velocity ECEF Z coordinate
         */
        public int z() { return z; }

        /**
         * Velocity estimated standard deviation
         */
        public int accuracy() { return accuracy; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
     * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
     * with the matching time-of-week (tow).
     */
    public static class MsgVelEcef extends KaitaiStruct {
        public static MsgVelEcef fromFile(String fileName) throws IOException {
            return new MsgVelEcef(new ByteBufferKaitaiStream(fileName));
        }

        public MsgVelEcef(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgVelEcef(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgVelEcef(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
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
            this.accuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int x;
        private int y;
        private int z;
        private int accuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Velocity ECEF X coordinate
         */
        public int x() { return x; }

        /**
         * Velocity ECEF Y coordinate
         */
        public int y() { return y; }

        /**
         * Velocity ECEF Z coordinate
         */
        public int z() { return z; }

        /**
         * Velocity estimated standard deviation
         */
        public int accuracy() { return accuracy; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This position solution message reports the absolute geodetic coordinates
     * and the status (single point vs pseudo-absolute RTK) of the position
     * solution as well as the upper triangle of the 3x3 covariance matrix.
     * The position information and Fix Mode flags should follow the
     * MSG_POS_LLH message.  Since the covariance matrix is computed in the
     * local-level North, East, Down frame, the covariance terms follow with
     * that convention. Thus, covariances are reported against the "downward"
     * measurement and care should be taken with the sign convention.
     */
    public static class MsgPosLlhCovGnss extends KaitaiStruct {
        public static MsgPosLlhCovGnss fromFile(String fileName) throws IOException {
            return new MsgPosLlhCovGnss(new ByteBufferKaitaiStream(fileName));
        }

        public MsgPosLlhCovGnss(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgPosLlhCovGnss(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgPosLlhCovGnss(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.lat = this._io.readF8le();
            this.lon = this._io.readF8le();
            this.height = this._io.readF8le();
            this.covNN = this._io.readF4le();
            this.covNE = this._io.readF4le();
            this.covND = this._io.readF4le();
            this.covEE = this._io.readF4le();
            this.covED = this._io.readF4le();
            this.covDD = this._io.readF4le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private double lat;
        private double lon;
        private double height;
        private float covNN;
        private float covNE;
        private float covND;
        private float covEE;
        private float covED;
        private float covDD;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Latitude
         */
        public double lat() { return lat; }

        /**
         * Longitude
         */
        public double lon() { return lon; }

        /**
         * Height above WGS84 ellipsoid
         */
        public double height() { return height; }

        /**
         * Estimated variance of northing
         */
        public float covNN() { return covNN; }

        /**
         * Covariance of northing and easting
         */
        public float covNE() { return covNE; }

        /**
         * Covariance of northing and downward measurement
         */
        public float covND() { return covND; }

        /**
         * Estimated variance of easting
         */
        public float covEE() { return covEE; }

        /**
         * Covariance of easting and downward measurement
         */
        public float covED() { return covED; }

        /**
         * Estimated variance of downward measurement
         */
        public float covDD() { return covDD; }

        /**
         * Number of satellites used in solution.
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the baseline solution in Earth Centered Earth Fixed
     * (ECEF) coordinates. This baseline is the relative vector distance from
     * the base station to the rover receiver. The full GPS time is given by
     * the preceding MSG_GPS_TIME with the matching time-of-week (tow).
     */
    public static class MsgBaselineEcef extends KaitaiStruct {
        public static MsgBaselineEcef fromFile(String fileName) throws IOException {
            return new MsgBaselineEcef(new ByteBufferKaitaiStream(fileName));
        }

        public MsgBaselineEcef(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgBaselineEcef(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgBaselineEcef(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
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
            this.accuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int x;
        private int y;
        private int z;
        private int accuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Baseline ECEF X coordinate
         */
        public int x() { return x; }

        /**
         * Baseline ECEF Y coordinate
         */
        public int y() { return y; }

        /**
         * Baseline ECEF Z coordinate
         */
        public int z() { return z; }

        /**
         * Position estimated standard deviation
         */
        public int accuracy() { return accuracy; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This dilution of precision (DOP) message describes the effect of
     * navigation satellite geometry on positional measurement precision.
     */
    public static class MsgDopsDepA extends KaitaiStruct {
        public static MsgDopsDepA fromFile(String fileName) throws IOException {
            return new MsgDopsDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgDopsDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgDopsDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgDopsDepA(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.gdop = this._io.readU2le();
            this.pdop = this._io.readU2le();
            this.tdop = this._io.readU2le();
            this.hdop = this._io.readU2le();
            this.vdop = this._io.readU2le();
        }
        private long tow;
        private int gdop;
        private int pdop;
        private int tdop;
        private int hdop;
        private int vdop;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Geometric Dilution of Precision
         */
        public int gdop() { return gdop; }

        /**
         * Position Dilution of Precision
         */
        public int pdop() { return pdop; }

        /**
         * Time Dilution of Precision
         */
        public int tdop() { return tdop; }

        /**
         * Horizontal Dilution of Precision
         */
        public int hdop() { return hdop; }

        /**
         * Vertical Dilution of Precision
         */
        public int vdop() { return vdop; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The position solution message reports absolute Earth Centered Earth
     * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
     * RTK) of the position solution. If the rover receiver knows the surveyed
     * position of the base station and has an RTK solution, this reports a
     * pseudo-absolute position solution using the base station position and
     * the rover's RTK baseline vector. The full GPS time is given by the
     * preceding MSG_GPS_TIME with the matching time-of-week (tow).
     */
    public static class MsgPosEcef extends KaitaiStruct {
        public static MsgPosEcef fromFile(String fileName) throws IOException {
            return new MsgPosEcef(new ByteBufferKaitaiStream(fileName));
        }

        public MsgPosEcef(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgPosEcef(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgPosEcef(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.x = this._io.readF8le();
            this.y = this._io.readF8le();
            this.z = this._io.readF8le();
            this.accuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private double x;
        private double y;
        private double z;
        private int accuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * ECEF X coordinate
         */
        public double x() { return x; }

        /**
         * ECEF Y coordinate
         */
        public double y() { return y; }

        /**
         * ECEF Z coordinate
         */
        public double z() { return z; }

        /**
         * Position estimated standard deviation
         */
        public int accuracy() { return accuracy; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the Age of the corrections used for the current
     * Differential solution.
     */
    public static class MsgAgeCorrections extends KaitaiStruct {
        public static MsgAgeCorrections fromFile(String fileName) throws IOException {
            return new MsgAgeCorrections(new ByteBufferKaitaiStream(fileName));
        }

        public MsgAgeCorrections(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgAgeCorrections(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgAgeCorrections(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.age = this._io.readU2le();
        }
        private long tow;
        private int age;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Age of the corrections (0xFFFF indicates invalid)
         */
        public int age() { return age; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
     * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
     * with the matching time-of-week (tow).
     */
    public static class MsgVelEcefCovGnss extends KaitaiStruct {
        public static MsgVelEcefCovGnss fromFile(String fileName) throws IOException {
            return new MsgVelEcefCovGnss(new ByteBufferKaitaiStream(fileName));
        }

        public MsgVelEcefCovGnss(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgVelEcefCovGnss(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgVelEcefCovGnss(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
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
            this.covXX = this._io.readF4le();
            this.covXY = this._io.readF4le();
            this.covXZ = this._io.readF4le();
            this.covYY = this._io.readF4le();
            this.covYZ = this._io.readF4le();
            this.covZZ = this._io.readF4le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int x;
        private int y;
        private int z;
        private float covXX;
        private float covXY;
        private float covXZ;
        private float covYY;
        private float covYZ;
        private float covZZ;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Velocity ECEF X coordinate
         */
        public int x() { return x; }

        /**
         * Velocity ECEF Y coordinate
         */
        public int y() { return y; }

        /**
         * Velocity ECEF Z coordinate
         */
        public int z() { return z; }

        /**
         * Estimated variance of x
         */
        public float covXX() { return covXX; }

        /**
         * Estimated covariance of x and y
         */
        public float covXY() { return covXY; }

        /**
         * Estimated covariance of x and z
         */
        public float covXZ() { return covXZ; }

        /**
         * Estimated variance of y
         */
        public float covYY() { return covYY; }

        /**
         * Estimated covariance of y and z
         */
        public float covYZ() { return covYZ; }

        /**
         * Estimated variance of z
         */
        public float covZZ() { return covZZ; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the protection levels associated to the given state
     * estimate. The full GPS time is given by the preceding MSG_GPS_TIME with
     * the matching time-of-week (tow).
     */
    public static class MsgProtectionLevel extends KaitaiStruct {
        public static MsgProtectionLevel fromFile(String fileName) throws IOException {
            return new MsgProtectionLevel(new ByteBufferKaitaiStream(fileName));
        }

        public MsgProtectionLevel(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgProtectionLevel(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgProtectionLevel(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.wn = this._io.readS2le();
            this.hpl = this._io.readU2le();
            this.vpl = this._io.readU2le();
            this.atpl = this._io.readU2le();
            this.ctpl = this._io.readU2le();
            this.hvpl = this._io.readU2le();
            this.vvpl = this._io.readU2le();
            this.hopl = this._io.readU2le();
            this.popl = this._io.readU2le();
            this.ropl = this._io.readU2le();
            this.lat = this._io.readF8le();
            this.lon = this._io.readF8le();
            this.height = this._io.readF8le();
            this.vX = this._io.readS4le();
            this.vY = this._io.readS4le();
            this.vZ = this._io.readS4le();
            this.roll = this._io.readS4le();
            this.pitch = this._io.readS4le();
            this.heading = this._io.readS4le();
            this.flags = this._io.readU4le();
        }
        private long tow;
        private short wn;
        private int hpl;
        private int vpl;
        private int atpl;
        private int ctpl;
        private int hvpl;
        private int vvpl;
        private int hopl;
        private int popl;
        private int ropl;
        private double lat;
        private double lon;
        private double height;
        private int vX;
        private int vY;
        private int vZ;
        private int roll;
        private int pitch;
        private int heading;
        private long flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * GPS week number
         */
        public short wn() { return wn; }

        /**
         * Horizontal protection level
         */
        public int hpl() { return hpl; }

        /**
         * Vertical protection level
         */
        public int vpl() { return vpl; }

        /**
         * Along-track position error protection level
         */
        public int atpl() { return atpl; }

        /**
         * Cross-track position error protection level
         */
        public int ctpl() { return ctpl; }

        /**
         * Protection level for the error vector between estimated and true
         * along/cross track velocity vector
         */
        public int hvpl() { return hvpl; }

        /**
         * Protection level for the velocity in vehicle upright direction
         * (different from vertical direction if on a slope)
         */
        public int vvpl() { return vvpl; }

        /**
         * Heading orientation protection level
         */
        public int hopl() { return hopl; }

        /**
         * Pitch orientation protection level
         */
        public int popl() { return popl; }

        /**
         * Roll orientation protection level
         */
        public int ropl() { return ropl; }

        /**
         * Latitude
         */
        public double lat() { return lat; }

        /**
         * Longitude
         */
        public double lon() { return lon; }

        /**
         * Height
         */
        public double height() { return height; }

        /**
         * Velocity in vehicle x direction
         */
        public int vX() { return vX; }

        /**
         * Velocity in vehicle y direction
         */
        public int vY() { return vY; }

        /**
         * Velocity in vehicle z direction
         */
        public int vZ() { return vZ; }

        /**
         * Roll angle
         */
        public int roll() { return roll; }

        /**
         * Pitch angle
         */
        public int pitch() { return pitch; }

        /**
         * Heading angle
         */
        public int heading() { return heading; }

        /**
         * Status flags
         */
        public long flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The position solution message reports absolute Earth Centered Earth
     * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
     * RTK) of the position solution. The message also reports the upper
     * triangular portion of the 3x3 covariance matrix. If the receiver knows
     * the surveyed position of the base station and has an RTK solution, this
     * reports a pseudo-absolute position solution using the base station
     * position and the rover's RTK baseline vector. The full GPS time is given
     * by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
     */
    public static class MsgPosEcefCov extends KaitaiStruct {
        public static MsgPosEcefCov fromFile(String fileName) throws IOException {
            return new MsgPosEcefCov(new ByteBufferKaitaiStream(fileName));
        }

        public MsgPosEcefCov(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgPosEcefCov(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgPosEcefCov(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.x = this._io.readF8le();
            this.y = this._io.readF8le();
            this.z = this._io.readF8le();
            this.covXX = this._io.readF4le();
            this.covXY = this._io.readF4le();
            this.covXZ = this._io.readF4le();
            this.covYY = this._io.readF4le();
            this.covYZ = this._io.readF4le();
            this.covZZ = this._io.readF4le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private double x;
        private double y;
        private double z;
        private float covXX;
        private float covXY;
        private float covXZ;
        private float covYY;
        private float covYZ;
        private float covZZ;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * ECEF X coordinate
         */
        public double x() { return x; }

        /**
         * ECEF Y coordinate
         */
        public double y() { return y; }

        /**
         * ECEF Z coordinate
         */
        public double z() { return z; }

        /**
         * Estimated variance of x
         */
        public float covXX() { return covXX; }

        /**
         * Estimated covariance of x and y
         */
        public float covXY() { return covXY; }

        /**
         * Estimated covariance of x and z
         */
        public float covXZ() { return covXZ; }

        /**
         * Estimated variance of y
         */
        public float covYY() { return covYY; }

        /**
         * Estimated covariance of y and z
         */
        public float covYZ() { return covYZ; }

        /**
         * Estimated variance of z
         */
        public float covZZ() { return covZZ; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The position solution message reports absolute Earth Centered Earth
     * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
     * RTK) of the position solution. If the rover receiver knows the surveyed
     * position of the base station and has an RTK solution, this reports a
     * pseudo-absolute position solution using the base station position and
     * the rover's RTK baseline vector. The full GPS time is given by the
     * preceding MSG_GPS_TIME with the matching time-of-week (tow).
     */
    public static class MsgPosEcefGnss extends KaitaiStruct {
        public static MsgPosEcefGnss fromFile(String fileName) throws IOException {
            return new MsgPosEcefGnss(new ByteBufferKaitaiStream(fileName));
        }

        public MsgPosEcefGnss(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgPosEcefGnss(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgPosEcefGnss(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.x = this._io.readF8le();
            this.y = this._io.readF8le();
            this.z = this._io.readF8le();
            this.accuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private double x;
        private double y;
        private double z;
        private int accuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * ECEF X coordinate
         */
        public double x() { return x; }

        /**
         * ECEF Y coordinate
         */
        public double y() { return y; }

        /**
         * ECEF Z coordinate
         */
        public double z() { return z; }

        /**
         * Position estimated standard deviation
         */
        public int accuracy() { return accuracy; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the velocity in local North East Down (NED)
     * coordinates. The NED coordinate system is defined as the local WGS84
     * tangent plane centered at the current position. The full GPS time is
     * given by the preceding MSG_GPS_TIME with the matching time-of-week
     * (tow).
     */
    public static class MsgVelNed extends KaitaiStruct {
        public static MsgVelNed fromFile(String fileName) throws IOException {
            return new MsgVelNed(new ByteBufferKaitaiStream(fileName));
        }

        public MsgVelNed(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgVelNed(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgVelNed(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.n = this._io.readS4le();
            this.e = this._io.readS4le();
            this.d = this._io.readS4le();
            this.hAccuracy = this._io.readU2le();
            this.vAccuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int n;
        private int e;
        private int d;
        private int hAccuracy;
        private int vAccuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Velocity North coordinate
         */
        public int n() { return n; }

        /**
         * Velocity East coordinate
         */
        public int e() { return e; }

        /**
         * Velocity Down coordinate
         */
        public int d() { return d; }

        /**
         * Horizontal velocity estimated standard deviation
         */
        public int hAccuracy() { return hAccuracy; }

        /**
         * Vertical velocity estimated standard deviation
         */
        public int vAccuracy() { return vAccuracy; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * UTC-GPST leap seconds before and after the most recent (past, or future,
     * for announced insertions) UTC leap second insertion.
     */
    public static class MsgUtcLeapSecond extends KaitaiStruct {
        public static MsgUtcLeapSecond fromFile(String fileName) throws IOException {
            return new MsgUtcLeapSecond(new ByteBufferKaitaiStream(fileName));
        }

        public MsgUtcLeapSecond(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgUtcLeapSecond(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgUtcLeapSecond(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.reserved0 = this._io.readS2le();
            this.reserved1 = this._io.readS2le();
            this.reserved2 = this._io.readS1();
            this.countBefore = this._io.readS1();
            this.reserved3 = this._io.readU2le();
            this.reserved4 = this._io.readU2le();
            this.refWn = this._io.readU2le();
            this.refDn = this._io.readU1();
            this.countAfter = this._io.readS1();
        }
        private short reserved0;
        private short reserved1;
        private byte reserved2;
        private byte countBefore;
        private int reserved3;
        private int reserved4;
        private int refWn;
        private int refDn;
        private byte countAfter;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * Reserved.
         */
        public short reserved0() { return reserved0; }

        /**
         * Reserved.
         */
        public short reserved1() { return reserved1; }

        /**
         * Reserved.
         */
        public byte reserved2() { return reserved2; }

        /**
         * Leap second count before insertion.
         */
        public byte countBefore() { return countBefore; }

        /**
         * Reserved.
         */
        public int reserved3() { return reserved3; }

        /**
         * Reserved.
         */
        public int reserved4() { return reserved4; }

        /**
         * Leap second reference GPS week number.
         */
        public int refWn() { return refWn; }

        /**
         * Leap second reference day number.
         */
        public int refDn() { return refDn; }

        /**
         * Leap second count after insertion.
         */
        public byte countAfter() { return countAfter; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the GPS time, representing the time since the GPS
     * epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
     * and seconds of the week. The weeks begin at the Saturday/Sunday
     * transition. GPS week 0 began at the beginning of the GPS time scale.
     * 
     * Within each week number, the GPS time of the week is between between 0
     * and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
     * leap seconds, and as of now, has a small offset from UTC. In a message
     * stream, this message precedes a set of other navigation messages
     * referenced to the same time (but lacking the ns field) and indicates a
     * more precise time of these messages.
     */
    public static class MsgGpsTimeDepA extends KaitaiStruct {
        public static MsgGpsTimeDepA fromFile(String fileName) throws IOException {
            return new MsgGpsTimeDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgGpsTimeDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgGpsTimeDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgGpsTimeDepA(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.wn = this._io.readU2le();
            this.tow = this._io.readU4le();
            this.nsResidual = this._io.readS4le();
            this.flags = this._io.readU1();
        }
        private int wn;
        private long tow;
        private int nsResidual;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS week number
         */
        public int wn() { return wn; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        public long tow() { return tow; }

        /**
         * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
         * to 500000)
         */
        public int nsResidual() { return nsResidual; }

        /**
         * Status flags (reserved)
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This position solution message reports the absolute geodetic coordinates
     * and the status (single point vs pseudo-absolute RTK) of the position
     * solution. If the rover receiver knows the surveyed position of the base
     * station and has an RTK solution, this reports a pseudo-absolute position
     * solution using the base station position and the rover's RTK baseline
     * vector. The full GPS time is given by the preceding MSG_GPS_TIME with
     * the matching time-of-week (tow).
     */
    public static class MsgPosLlhGnss extends KaitaiStruct {
        public static MsgPosLlhGnss fromFile(String fileName) throws IOException {
            return new MsgPosLlhGnss(new ByteBufferKaitaiStream(fileName));
        }

        public MsgPosLlhGnss(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgPosLlhGnss(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgPosLlhGnss(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.lat = this._io.readF8le();
            this.lon = this._io.readF8le();
            this.height = this._io.readF8le();
            this.hAccuracy = this._io.readU2le();
            this.vAccuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private double lat;
        private double lon;
        private double height;
        private int hAccuracy;
        private int vAccuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Latitude
         */
        public double lat() { return lat; }

        /**
         * Longitude
         */
        public double lon() { return lon; }

        /**
         * Height above WGS84 ellipsoid
         */
        public double height() { return height; }

        /**
         * Horizontal position estimated standard deviation
         */
        public int hAccuracy() { return hAccuracy; }

        /**
         * Vertical position estimated standard deviation
         */
        public int vAccuracy() { return vAccuracy; }

        /**
         * Number of satellites used in solution.
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the Universal Coordinated Time (UTC).  Note the
     * flags which indicate the source of the UTC offset value and source of
     * the time fix.
     */
    public static class MsgUtcTimeGnss extends KaitaiStruct {
        public static MsgUtcTimeGnss fromFile(String fileName) throws IOException {
            return new MsgUtcTimeGnss(new ByteBufferKaitaiStream(fileName));
        }

        public MsgUtcTimeGnss(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgUtcTimeGnss(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgUtcTimeGnss(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.flags = this._io.readU1();
            this.tow = this._io.readU4le();
            this.year = this._io.readU2le();
            this.month = this._io.readU1();
            this.day = this._io.readU1();
            this.hours = this._io.readU1();
            this.minutes = this._io.readU1();
            this.seconds = this._io.readU1();
            this.ns = this._io.readU4le();
        }
        private int flags;
        private long tow;
        private int year;
        private int month;
        private int day;
        private int hours;
        private int minutes;
        private int seconds;
        private long ns;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * Indicates source and time validity
         */
        public int flags() { return flags; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        public long tow() { return tow; }

        /**
         * Year
         */
        public int year() { return year; }

        /**
         * Month (range 1 .. 12)
         */
        public int month() { return month; }

        /**
         * days in the month (range 1-31)
         */
        public int day() { return day; }

        /**
         * hours of day (range 0-23)
         */
        public int hours() { return hours; }

        /**
         * minutes of hour (range 0-59)
         */
        public int minutes() { return minutes; }

        /**
         * seconds of minute (range 0-60) rounded down
         */
        public int seconds() { return seconds; }

        /**
         * nanoseconds of second (range 0-999999999)
         */
        public long ns() { return ns; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the receiver course over ground (COG) and speed
     * over  ground (SOG) based on the horizontal (N-E) components of the NED
     * velocity  vector. It also includes the vertical velocity coordinate. A
     * flag is provided to indicate whether the COG value has been frozen. When
     * the flag is set to true, the COG field is set to its last valid value
     * until  the system exceeds a minimum velocity threshold. No other fields
     * are  affected by this flag.  The NED coordinate system is defined as the
     * local WGS84 tangent  plane centered at the current position. The full
     * GPS time is given by the  preceding MSG_GPS_TIME with the matching time-
     * of-week (tow). Note: course over ground represents the receiver's
     * direction of travel,  but not necessarily the device heading.
     */
    public static class MsgVelCog extends KaitaiStruct {
        public static MsgVelCog fromFile(String fileName) throws IOException {
            return new MsgVelCog(new ByteBufferKaitaiStream(fileName));
        }

        public MsgVelCog(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgVelCog(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgVelCog(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.cog = this._io.readU4le();
            this.sog = this._io.readU4le();
            this.vUp = this._io.readS4le();
            this.cogAccuracy = this._io.readU4le();
            this.sogAccuracy = this._io.readU4le();
            this.vUpAccuracy = this._io.readU4le();
            this.flags = this._io.readU2le();
        }
        private long tow;
        private long cog;
        private long sog;
        private int vUp;
        private long cogAccuracy;
        private long sogAccuracy;
        private long vUpAccuracy;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Course over ground relative to north direction
         */
        public long cog() { return cog; }

        /**
         * Speed over ground (based on horizontal velocity)
         */
        public long sog() { return sog; }

        /**
         * Vertical velocity component (positive up)
         */
        public int vUp() { return vUp; }

        /**
         * Course over ground estimated standard deviation
         */
        public long cogAccuracy() { return cogAccuracy; }

        /**
         * Speed over ground estimated standard deviation
         */
        public long sogAccuracy() { return sogAccuracy; }

        /**
         * Vertical velocity estimated standard deviation
         */
        public long vUpAccuracy() { return vUpAccuracy; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the baseline solution in North East Down (NED)
     * coordinates. This baseline is the relative vector distance from the base
     * station to the rover receiver, and NED coordinate system is defined at
     * the local WGS84 tangent plane centered at the base station position.
     * The full GPS time is given by the preceding MSG_GPS_TIME with the
     * matching time-of-week (tow).
     */
    public static class MsgBaselineNed extends KaitaiStruct {
        public static MsgBaselineNed fromFile(String fileName) throws IOException {
            return new MsgBaselineNed(new ByteBufferKaitaiStream(fileName));
        }

        public MsgBaselineNed(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgBaselineNed(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgBaselineNed(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.n = this._io.readS4le();
            this.e = this._io.readS4le();
            this.d = this._io.readS4le();
            this.hAccuracy = this._io.readU2le();
            this.vAccuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int n;
        private int e;
        private int d;
        private int hAccuracy;
        private int vAccuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Baseline North coordinate
         */
        public int n() { return n; }

        /**
         * Baseline East coordinate
         */
        public int e() { return e; }

        /**
         * Baseline Down coordinate
         */
        public int d() { return d; }

        /**
         * Horizontal position estimated standard deviation
         */
        public int hAccuracy() { return hAccuracy; }

        /**
         * Vertical position estimated standard deviation
         */
        public int vAccuracy() { return vAccuracy; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This position solution message reports the absolute geodetic coordinates
     * and the status (single point vs pseudo-absolute RTK) of the position
     * solution. If the rover receiver knows the surveyed position of the base
     * station and has an RTK solution, this reports a pseudo-absolute position
     * solution using the base station position and the rover's RTK baseline
     * vector. The full GPS time is given by the preceding MSG_GPS_TIME with
     * the matching time-of-week (tow).
     */
    public static class MsgPosLlh extends KaitaiStruct {
        public static MsgPosLlh fromFile(String fileName) throws IOException {
            return new MsgPosLlh(new ByteBufferKaitaiStream(fileName));
        }

        public MsgPosLlh(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgPosLlh(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgPosLlh(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.lat = this._io.readF8le();
            this.lon = this._io.readF8le();
            this.height = this._io.readF8le();
            this.hAccuracy = this._io.readU2le();
            this.vAccuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private double lat;
        private double lon;
        private double height;
        private int hAccuracy;
        private int vAccuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Latitude
         */
        public double lat() { return lat; }

        /**
         * Longitude
         */
        public double lon() { return lon; }

        /**
         * Height above WGS84 ellipsoid
         */
        public double height() { return height; }

        /**
         * Horizontal position estimated standard deviation
         */
        public int hAccuracy() { return hAccuracy; }

        /**
         * Vertical position estimated standard deviation
         */
        public int vAccuracy() { return vAccuracy; }

        /**
         * Number of satellites used in solution.
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the baseline heading pointing from the base station
     * to the rover relative to True North. The full GPS time is given by the
     * preceding MSG_GPS_TIME with the matching time-of-week (tow).
     */
    public static class MsgBaselineHeadingDepA extends KaitaiStruct {
        public static MsgBaselineHeadingDepA fromFile(String fileName) throws IOException {
            return new MsgBaselineHeadingDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgBaselineHeadingDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgBaselineHeadingDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgBaselineHeadingDepA(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
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
        private Navigation _root;
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
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the GPS time, representing the time since the GPS
     * epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
     * and seconds of the week. The weeks begin at the Saturday/Sunday
     * transition. GPS week 0 began at the beginning of the GPS time scale.
     * 
     * Within each week number, the GPS time of the week is between between 0
     * and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
     * leap seconds, and as of now, has a small offset from UTC. In a message
     * stream, this message precedes a set of other navigation messages
     * referenced to the same time (but lacking the ns field) and indicates a
     * more precise time of these messages.
     */
    public static class MsgGpsTimeGnss extends KaitaiStruct {
        public static MsgGpsTimeGnss fromFile(String fileName) throws IOException {
            return new MsgGpsTimeGnss(new ByteBufferKaitaiStream(fileName));
        }

        public MsgGpsTimeGnss(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgGpsTimeGnss(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgGpsTimeGnss(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.wn = this._io.readU2le();
            this.tow = this._io.readU4le();
            this.nsResidual = this._io.readS4le();
            this.flags = this._io.readU1();
        }
        private int wn;
        private long tow;
        private int nsResidual;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS week number
         */
        public int wn() { return wn; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        public long tow() { return tow; }

        /**
         * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
         * to 500000)
         */
        public int nsResidual() { return nsResidual; }

        /**
         * Status flags (reserved)
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the baseline solution in Earth Centered Earth Fixed
     * (ECEF) coordinates. This baseline is the relative vector distance from
     * the base station to the rover receiver. The full GPS time is given by
     * the preceding MSG_GPS_TIME with the matching time-of-week (tow).
     */
    public static class MsgBaselineEcefDepA extends KaitaiStruct {
        public static MsgBaselineEcefDepA fromFile(String fileName) throws IOException {
            return new MsgBaselineEcefDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgBaselineEcefDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgBaselineEcefDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgBaselineEcefDepA(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
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
            this.accuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int x;
        private int y;
        private int z;
        private int accuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Baseline ECEF X coordinate
         */
        public int x() { return x; }

        /**
         * Baseline ECEF Y coordinate
         */
        public int y() { return y; }

        /**
         * Baseline ECEF Z coordinate
         */
        public int z() { return z; }

        /**
         * Position accuracy estimate
         */
        public int accuracy() { return accuracy; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message reports the GPS time, representing the time since the GPS
     * epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
     * and seconds of the week. The weeks begin at the Saturday/Sunday
     * transition. GPS week 0 began at the beginning of the GPS time scale.
     * 
     * Within each week number, the GPS time of the week is between between 0
     * and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
     * leap seconds, and as of now, has a small offset from UTC. In a message
     * stream, this message precedes a set of other navigation messages
     * referenced to the same time (but lacking the ns field) and indicates a
     * more precise time of these messages.
     */
    public static class MsgGpsTime extends KaitaiStruct {
        public static MsgGpsTime fromFile(String fileName) throws IOException {
            return new MsgGpsTime(new ByteBufferKaitaiStream(fileName));
        }

        public MsgGpsTime(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgGpsTime(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgGpsTime(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.wn = this._io.readU2le();
            this.tow = this._io.readU4le();
            this.nsResidual = this._io.readS4le();
            this.flags = this._io.readU1();
        }
        private int wn;
        private long tow;
        private int nsResidual;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS week number
         */
        public int wn() { return wn; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        public long tow() { return tow; }

        /**
         * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
         * to 500000)
         */
        public int nsResidual() { return nsResidual; }

        /**
         * Status flags (reserved)
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This dilution of precision (DOP) message describes the effect of
     * navigation satellite geometry on positional measurement precision.  The
     * flags field indicated whether the DOP reported corresponds to
     * differential or SPP solution.
     */
    public static class MsgDops extends KaitaiStruct {
        public static MsgDops fromFile(String fileName) throws IOException {
            return new MsgDops(new ByteBufferKaitaiStream(fileName));
        }

        public MsgDops(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgDops(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgDops(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.gdop = this._io.readU2le();
            this.pdop = this._io.readU2le();
            this.tdop = this._io.readU2le();
            this.hdop = this._io.readU2le();
            this.vdop = this._io.readU2le();
            this.flags = this._io.readU1();
        }
        private long tow;
        private int gdop;
        private int pdop;
        private int tdop;
        private int hdop;
        private int vdop;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Geometric Dilution of Precision
         */
        public int gdop() { return gdop; }

        /**
         * Position Dilution of Precision
         */
        public int pdop() { return pdop; }

        /**
         * Time Dilution of Precision
         */
        public int tdop() { return tdop; }

        /**
         * Horizontal Dilution of Precision
         */
        public int hdop() { return hdop; }

        /**
         * Vertical Dilution of Precision
         */
        public int vdop() { return vdop; }

        /**
         * Indicates the position solution with which the DOPS message
         * corresponds
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The position solution message reports absolute Earth Centered Earth
     * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
     * RTK) of the position solution. If the rover receiver knows the surveyed
     * position of the base station and has an RTK solution, this reports a
     * pseudo-absolute position solution using the base station position and
     * the rover's RTK baseline vector. The full GPS time is given by the
     * preceding MSG_GPS_TIME with the matching time-of-week (tow).
     */
    public static class MsgPosEcefDepA extends KaitaiStruct {
        public static MsgPosEcefDepA fromFile(String fileName) throws IOException {
            return new MsgPosEcefDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgPosEcefDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgPosEcefDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgPosEcefDepA(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.x = this._io.readF8le();
            this.y = this._io.readF8le();
            this.z = this._io.readF8le();
            this.accuracy = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private double x;
        private double y;
        private double z;
        private int accuracy;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * ECEF X coordinate
         */
        public double x() { return x; }

        /**
         * ECEF Y coordinate
         */
        public double y() { return y; }

        /**
         * ECEF Z coordinate
         */
        public double z() { return z; }

        /**
         * Position accuracy estimate (not implemented). Defaults to 0.
         */
        public int accuracy() { return accuracy; }

        /**
         * Number of satellites used in solution
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class EstimatedHorizontalErrorEllipse extends KaitaiStruct {
        public static EstimatedHorizontalErrorEllipse fromFile(String fileName) throws IOException {
            return new EstimatedHorizontalErrorEllipse(new ByteBufferKaitaiStream(fileName));
        }

        public EstimatedHorizontalErrorEllipse(KaitaiStream _io) {
            this(_io, null, null);
        }

        public EstimatedHorizontalErrorEllipse(KaitaiStream _io, Navigation.MsgPosLlhAcc _parent) {
            this(_io, _parent, null);
        }

        public EstimatedHorizontalErrorEllipse(KaitaiStream _io, Navigation.MsgPosLlhAcc _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.semiMajor = this._io.readF4le();
            this.semiMinor = this._io.readF4le();
            this.orientation = this._io.readF4le();
        }
        private float semiMajor;
        private float semiMinor;
        private float orientation;
        private Navigation _root;
        private Navigation.MsgPosLlhAcc _parent;

        /**
         * The semi major axis of the estimated horizontal error ellipse at the
         * user-configured confidence level; zero implies invalid.
         */
        public float semiMajor() { return semiMajor; }

        /**
         * The semi minor axis of the estimated horizontal error ellipse at the
         * user-configured confidence level; zero implies invalid.
         */
        public float semiMinor() { return semiMinor; }

        /**
         * The orientation of the semi major axis of the estimated horizontal
         * error ellipse with respect to North.
         */
        public float orientation() { return orientation; }
        public Navigation _root() { return _root; }
        public Navigation.MsgPosLlhAcc _parent() { return _parent; }
    }

    /**
     * This position solution message reports the absolute geodetic coordinates
     * and the status (single point vs pseudo-absolute RTK) of the position
     * solution as well as the estimated horizontal, vertical, cross-track and
     * along-track errors.  The position information and Fix Mode flags  follow
     * the MSG_POS_LLH message. Since the covariance matrix is computed in the
     * local-level North, East, Down frame, the estimated error terms follow
     * that convention.
     * 
     * The estimated errors are reported at a user-configurable confidence
     * level. The user-configured percentile is encoded in the percentile
     * field.
     */
    public static class MsgPosLlhAcc extends KaitaiStruct {
        public static MsgPosLlhAcc fromFile(String fileName) throws IOException {
            return new MsgPosLlhAcc(new ByteBufferKaitaiStream(fileName));
        }

        public MsgPosLlhAcc(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgPosLlhAcc(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgPosLlhAcc(KaitaiStream _io, Sbp.Message _parent, Navigation _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tow = this._io.readU4le();
            this.lat = this._io.readF8le();
            this.lon = this._io.readF8le();
            this.height = this._io.readF8le();
            this.orthometricHeight = this._io.readF8le();
            this.hAccuracy = this._io.readF4le();
            this.vAccuracy = this._io.readF4le();
            this.ctAccuracy = this._io.readF4le();
            this.atAccuracy = this._io.readF4le();
            this.hEllipse = new EstimatedHorizontalErrorEllipse(this._io, this, _root);
            this.confidenceAndGeoid = this._io.readU1();
            this.nSats = this._io.readU1();
            this.flags = this._io.readU1();
        }
        private long tow;
        private double lat;
        private double lon;
        private double height;
        private double orthometricHeight;
        private float hAccuracy;
        private float vAccuracy;
        private float ctAccuracy;
        private float atAccuracy;
        private EstimatedHorizontalErrorEllipse hEllipse;
        private int confidenceAndGeoid;
        private int nSats;
        private int flags;
        private Navigation _root;
        private Sbp.Message _parent;

        /**
         * GPS Time of Week
         */
        public long tow() { return tow; }

        /**
         * Latitude
         */
        public double lat() { return lat; }

        /**
         * Longitude
         */
        public double lon() { return lon; }

        /**
         * Height above WGS84 ellipsoid
         */
        public double height() { return height; }

        /**
         * Height above the geoid (i.e. height above mean sea level). See
         * confidence_and_geoid for geoid model used.
         */
        public double orthometricHeight() { return orthometricHeight; }

        /**
         * Estimated horizontal error at the user-configured confidence level;
         * zero implies invalid.
         */
        public float hAccuracy() { return hAccuracy; }

        /**
         * Estimated vertical error at the user-configured confidence level;
         * zero implies invalid.
         */
        public float vAccuracy() { return vAccuracy; }

        /**
         * Estimated cross-track error at the user-configured confidence level;
         * zero implies invalid.
         */
        public float ctAccuracy() { return ctAccuracy; }

        /**
         * Estimated along-track error at the user-configured confidence level;
         * zero implies invalid.
         */
        public float atAccuracy() { return atAccuracy; }

        /**
         * The estimated horizontal error ellipse at the user-configured
         * confidence level.
         */
        public EstimatedHorizontalErrorEllipse hEllipse() { return hEllipse; }

        /**
         * The lower bits describe the configured confidence level for the
         * estimated position error. The middle bits describe the geoid model
         * used to calculate the orthometric height.
         */
        public int confidenceAndGeoid() { return confidenceAndGeoid; }

        /**
         * Number of satellites used in solution.
         */
        public int nSats() { return nSats; }

        /**
         * Status flags
         */
        public int flags() { return flags; }
        public Navigation _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Navigation _root;
    private KaitaiStruct _parent;
    public Navigation _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
