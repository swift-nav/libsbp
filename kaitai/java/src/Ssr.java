// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.util.ArrayList;

public class Ssr extends KaitaiStruct {
    public static Ssr fromFile(String fileName) throws IOException {
        return new Ssr(new ByteBufferKaitaiStream(fileName));
    }

    public Ssr(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Ssr(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Ssr(KaitaiStream _io, KaitaiStruct _parent, Ssr _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes
     * an RLE encoded validity list.
     */
    public static class GridDefinitionHeaderDepA extends KaitaiStruct {
        public static GridDefinitionHeaderDepA fromFile(String fileName) throws IOException {
            return new GridDefinitionHeaderDepA(new ByteBufferKaitaiStream(fileName));
        }

        public GridDefinitionHeaderDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public GridDefinitionHeaderDepA(KaitaiStream _io, Ssr.MsgSsrGridDefinitionDepA _parent) {
            this(_io, _parent, null);
        }

        public GridDefinitionHeaderDepA(KaitaiStream _io, Ssr.MsgSsrGridDefinitionDepA _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.regionSizeInverse = this._io.readU1();
            this.areaWidth = this._io.readU2le();
            this.latNwCornerEnc = this._io.readU2le();
            this.lonNwCornerEnc = this._io.readU2le();
            this.numMsgs = this._io.readU1();
            this.seqNum = this._io.readU1();
        }
        private int regionSizeInverse;
        private int areaWidth;
        private int latNwCornerEnc;
        private int lonNwCornerEnc;
        private int numMsgs;
        private int seqNum;
        private Ssr _root;
        private Ssr.MsgSsrGridDefinitionDepA _parent;

        /**
         * region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
         */
        public int regionSizeInverse() { return regionSizeInverse; }

        /**
         * grid height (deg) = grid width (deg) = area_width / region_size 0 is
         * an invalid value.
         */
        public int areaWidth() { return areaWidth; }

        /**
         * North-West corner latitude (deg) = region_size * lat_nw_corner_enc -
         * 90
         */
        public int latNwCornerEnc() { return latNwCornerEnc; }

        /**
         * North-West corner longitude (deg) = region_size * lon_nw_corner_enc
         * - 180
         */
        public int lonNwCornerEnc() { return lonNwCornerEnc; }

        /**
         * Number of messages in the dataset
         */
        public int numMsgs() { return numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public int seqNum() { return seqNum; }
        public Ssr _root() { return _root; }
        public Ssr.MsgSsrGridDefinitionDepA _parent() { return _parent; }
    }

    /**
     * STEC residual for the given satellite at the grid point.
     */
    public static class StecResidualNoStd extends KaitaiStruct {
        public static StecResidualNoStd fromFile(String fileName) throws IOException {
            return new StecResidualNoStd(new ByteBufferKaitaiStream(fileName));
        }

        public StecResidualNoStd(KaitaiStream _io) {
            this(_io, null, null);
        }

        public StecResidualNoStd(KaitaiStream _io, Ssr.MsgSsrGriddedCorrectionNoStdDepA _parent) {
            this(_io, _parent, null);
        }

        public StecResidualNoStd(KaitaiStream _io, Ssr.MsgSsrGriddedCorrectionNoStdDepA _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.svId = new Gnss.SvId(this._io, this, _root);
            this.residual = this._io.readS2le();
        }
        private Gnss.SvId svId;
        private short residual;
        private Ssr _root;
        private Ssr.MsgSsrGriddedCorrectionNoStdDepA _parent;

        /**
         * space vehicle identifier
         */
        public Gnss.SvId svId() { return svId; }

        /**
         * STEC residual
         */
        public short residual() { return residual; }
        public Ssr _root() { return _root; }
        public Ssr.MsgSsrGriddedCorrectionNoStdDepA _parent() { return _parent; }
    }

    /**
     * Troposphere vertical delays at the grid point.
     */
    public static class TroposphericDelayCorrectionNoStd extends KaitaiStruct {
        public static TroposphericDelayCorrectionNoStd fromFile(String fileName) throws IOException {
            return new TroposphericDelayCorrectionNoStd(new ByteBufferKaitaiStream(fileName));
        }

        public TroposphericDelayCorrectionNoStd(KaitaiStream _io) {
            this(_io, null, null);
        }

        public TroposphericDelayCorrectionNoStd(KaitaiStream _io, Ssr.MsgSsrGriddedCorrectionNoStdDepA _parent) {
            this(_io, _parent, null);
        }

        public TroposphericDelayCorrectionNoStd(KaitaiStream _io, Ssr.MsgSsrGriddedCorrectionNoStdDepA _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.hydro = this._io.readS2le();
            this.wet = this._io.readS1();
        }
        private short hydro;
        private byte wet;
        private Ssr _root;
        private Ssr.MsgSsrGriddedCorrectionNoStdDepA _parent;

        /**
         * Hydrostatic vertical delay
         */
        public short hydro() { return hydro; }

        /**
         * Wet vertical delay
         */
        public byte wet() { return wet; }
        public Ssr _root() { return _root; }
        public Ssr.MsgSsrGriddedCorrectionNoStdDepA _parent() { return _parent; }
    }

    /**
     * The Slant Total Electron Content per space vehicle, given as polynomial
     * approximation for a given tile. This should be combined with the
     * MSG_SSR_GRIDDED_CORRECTION message to get the state space representation
     * of the atmospheric delay.
     * 
     * It is typically equivalent to the QZSS CLAS Sub Type 8 messages.
     */
    public static class MsgSsrStecCorrectionDep extends KaitaiStruct {
        public static MsgSsrStecCorrectionDep fromFile(String fileName) throws IOException {
            return new MsgSsrStecCorrectionDep(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrStecCorrectionDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrStecCorrectionDep(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrStecCorrectionDep(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new StecHeader(this._io, this, _root);
            this.stecSatList = new ArrayList<StecSatElement>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.stecSatList.add(new StecSatElement(this._io, this, _root));
                    i++;
                }
            }
        }
        private StecHeader header;
        private ArrayList<StecSatElement> stecSatList;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * Header of a STEC polynomial coefficient message.
         */
        public StecHeader header() { return header; }

        /**
         * Array of STEC polynomial coefficients for each space vehicle.
         */
        public ArrayList<StecSatElement> stecSatList() { return stecSatList; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * STEC polynomial and bounds for the given satellite.
     */
    public static class StecSatElementIntegrity extends KaitaiStruct {
        public static StecSatElementIntegrity fromFile(String fileName) throws IOException {
            return new StecSatElementIntegrity(new ByteBufferKaitaiStream(fileName));
        }

        public StecSatElementIntegrity(KaitaiStream _io) {
            this(_io, null, null);
        }

        public StecSatElementIntegrity(KaitaiStream _io, Ssr.MsgSsrGriddedCorrectionBounds _parent) {
            this(_io, _parent, null);
        }

        public StecSatElementIntegrity(KaitaiStream _io, Ssr.MsgSsrGriddedCorrectionBounds _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.stecResidual = new StecResidual(this._io, this, _root);
            this.stecBoundMu = this._io.readU1();
            this.stecBoundSig = this._io.readU1();
            this.stecBoundMuDot = this._io.readU1();
            this.stecBoundSigDot = this._io.readU1();
        }
        private StecResidual stecResidual;
        private int stecBoundMu;
        private int stecBoundSig;
        private int stecBoundMuDot;
        private int stecBoundSigDot;
        private Ssr _root;
        private Ssr.MsgSsrGriddedCorrectionBounds _parent;

        /**
         * STEC residuals (mean, stddev)
         */
        public StecResidual stecResidual() { return stecResidual; }

        /**
         * Error Bound Mean. See Note 1.
         */
        public int stecBoundMu() { return stecBoundMu; }

        /**
         * Error Bound StDev. See Note 1.
         */
        public int stecBoundSig() { return stecBoundSig; }

        /**
         * Error Bound Mean First derivative.
         */
        public int stecBoundMuDot() { return stecBoundMuDot; }

        /**
         * Error Bound StDev First derivative.
         */
        public int stecBoundSigDot() { return stecBoundSigDot; }
        public Ssr _root() { return _root; }
        public Ssr.MsgSsrGriddedCorrectionBounds _parent() { return _parent; }
    }
    public static class MsgSsrOrbitClockDepA extends KaitaiStruct {
        public static MsgSsrOrbitClockDepA fromFile(String fileName) throws IOException {
            return new MsgSsrOrbitClockDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrOrbitClockDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrOrbitClockDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrOrbitClockDepA(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.time = new Gnss.GpsTimeSec(this._io, this, _root);
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.updateInterval = this._io.readU1();
            this.iodSsr = this._io.readU1();
            this.iod = this._io.readU1();
            this.radial = this._io.readS4le();
            this.along = this._io.readS4le();
            this.cross = this._io.readS4le();
            this.dotRadial = this._io.readS4le();
            this.dotAlong = this._io.readS4le();
            this.dotCross = this._io.readS4le();
            this.c0 = this._io.readS4le();
            this.c1 = this._io.readS4le();
            this.c2 = this._io.readS4le();
        }
        private Gnss.GpsTimeSec time;
        private Gnss.GnssSignal sid;
        private int updateInterval;
        private int iodSsr;
        private int iod;
        private int radial;
        private int along;
        private int cross;
        private int dotRadial;
        private int dotAlong;
        private int dotCross;
        private int c0;
        private int c1;
        private int c2;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * GNSS reference time of the correction
         */
        public Gnss.GpsTimeSec time() { return time; }

        /**
         * GNSS signal identifier (16 bit)
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public int updateInterval() { return updateInterval; }

        /**
         * IOD of the SSR correction. A change of Issue Of Data SSR is used to
         * indicate a change in the SSR generating configuration
         */
        public int iodSsr() { return iodSsr; }

        /**
         * Issue of broadcast ephemeris data
         */
        public int iod() { return iod; }

        /**
         * Orbit radial delta correction
         */
        public int radial() { return radial; }

        /**
         * Orbit along delta correction
         */
        public int along() { return along; }

        /**
         * Orbit along delta correction
         */
        public int cross() { return cross; }

        /**
         * Velocity of orbit radial delta correction
         */
        public int dotRadial() { return dotRadial; }

        /**
         * Velocity of orbit along delta correction
         */
        public int dotAlong() { return dotAlong; }

        /**
         * Velocity of orbit cross delta correction
         */
        public int dotCross() { return dotCross; }

        /**
         * C0 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        public int c0() { return c0; }

        /**
         * C1 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        public int c1() { return c1; }

        /**
         * C2 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        public int c2() { return c2; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class MsgSsrStecCorrection extends KaitaiStruct {
        public static MsgSsrStecCorrection fromFile(String fileName) throws IOException {
            return new MsgSsrStecCorrection(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrStecCorrection(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrStecCorrection(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrStecCorrection(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new BoundsHeader(this._io, this, _root);
            this.ssrIodAtmo = this._io.readU1();
            this.tileSetId = this._io.readU2le();
            this.tileId = this._io.readU2le();
            this.nSats = this._io.readU1();
            this.stecSatList = new ArrayList<StecSatElement>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.stecSatList.add(new StecSatElement(this._io, this, _root));
                    i++;
                }
            }
        }
        private BoundsHeader header;
        private int ssrIodAtmo;
        private int tileSetId;
        private int tileId;
        private int nSats;
        private ArrayList<StecSatElement> stecSatList;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * Header of a STEC correction with bounds message.
         */
        public BoundsHeader header() { return header; }

        /**
         * IOD of the SSR atmospheric correction
         */
        public int ssrIodAtmo() { return ssrIodAtmo; }

        /**
         * Tile set ID
         */
        public int tileSetId() { return tileSetId; }

        /**
         * Tile ID
         */
        public int tileId() { return tileId; }

        /**
         * Number of satellites.
         */
        public int nSats() { return nSats; }

        /**
         * Array of STEC polynomial coefficients for each space vehicle.
         */
        public ArrayList<StecSatElement> stecSatList() { return stecSatList; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The precise orbit and clock correction message is to be applied as a
     * delta correction to broadcast ephemeris and is an equivalent to the 1060
     * /1066 RTCM message types.
     */
    public static class MsgSsrOrbitClock extends KaitaiStruct {
        public static MsgSsrOrbitClock fromFile(String fileName) throws IOException {
            return new MsgSsrOrbitClock(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrOrbitClock(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrOrbitClock(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrOrbitClock(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.time = new Gnss.GpsTimeSec(this._io, this, _root);
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.updateInterval = this._io.readU1();
            this.iodSsr = this._io.readU1();
            this.iod = this._io.readU4le();
            this.radial = this._io.readS4le();
            this.along = this._io.readS4le();
            this.cross = this._io.readS4le();
            this.dotRadial = this._io.readS4le();
            this.dotAlong = this._io.readS4le();
            this.dotCross = this._io.readS4le();
            this.c0 = this._io.readS4le();
            this.c1 = this._io.readS4le();
            this.c2 = this._io.readS4le();
        }
        private Gnss.GpsTimeSec time;
        private Gnss.GnssSignal sid;
        private int updateInterval;
        private int iodSsr;
        private long iod;
        private int radial;
        private int along;
        private int cross;
        private int dotRadial;
        private int dotAlong;
        private int dotCross;
        private int c0;
        private int c1;
        private int c2;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * GNSS reference time of the correction
         */
        public Gnss.GpsTimeSec time() { return time; }

        /**
         * GNSS signal identifier (16 bit)
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public int updateInterval() { return updateInterval; }

        /**
         * IOD of the SSR correction. A change of Issue Of Data SSR is used to
         * indicate a change in the SSR generating configuration
         */
        public int iodSsr() { return iodSsr; }

        /**
         * Issue of broadcast ephemeris data or IODCRC (Beidou)
         */
        public long iod() { return iod; }

        /**
         * Orbit radial delta correction
         */
        public int radial() { return radial; }

        /**
         * Orbit along delta correction
         */
        public int along() { return along; }

        /**
         * Orbit along delta correction
         */
        public int cross() { return cross; }

        /**
         * Velocity of orbit radial delta correction
         */
        public int dotRadial() { return dotRadial; }

        /**
         * Velocity of orbit along delta correction
         */
        public int dotAlong() { return dotAlong; }

        /**
         * Velocity of orbit cross delta correction
         */
        public int dotCross() { return dotCross; }

        /**
         * C0 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        public int c0() { return c0; }

        /**
         * C1 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        public int c1() { return c1; }

        /**
         * C2 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        public int c2() { return c2; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class BoundsHeader extends KaitaiStruct {
        public static BoundsHeader fromFile(String fileName) throws IOException {
            return new BoundsHeader(new ByteBufferKaitaiStream(fileName));
        }

        public BoundsHeader(KaitaiStream _io) {
            this(_io, null, null);
        }

        public BoundsHeader(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public BoundsHeader(KaitaiStream _io, KaitaiStruct _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.time = new Gnss.GpsTimeSec(this._io, this, _root);
            this.numMsgs = this._io.readU1();
            this.seqNum = this._io.readU1();
            this.updateInterval = this._io.readU1();
            this.solId = this._io.readU1();
        }
        private Gnss.GpsTimeSec time;
        private int numMsgs;
        private int seqNum;
        private int updateInterval;
        private int solId;
        private Ssr _root;
        private KaitaiStruct _parent;

        /**
         * GNSS reference time of the bound
         */
        public Gnss.GpsTimeSec time() { return time; }

        /**
         * Number of messages in the dataset
         */
        public int numMsgs() { return numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public int seqNum() { return seqNum; }

        /**
         * Update interval between consecutive bounds. Similar to RTCM DF391.
         */
        public int updateInterval() { return updateInterval; }

        /**
         * SSR Solution ID.
         */
        public int solId() { return solId; }
        public Ssr _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * STEC residuals are per space vehicle, troposphere is not.
     * 
     * It is typically equivalent to the QZSS CLAS Sub Type 9 messages.
     */
    public static class MsgSsrGriddedCorrection extends KaitaiStruct {
        public static MsgSsrGriddedCorrection fromFile(String fileName) throws IOException {
            return new MsgSsrGriddedCorrection(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrGriddedCorrection(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrGriddedCorrection(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrGriddedCorrection(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new GriddedCorrectionHeader(this._io, this, _root);
            this.index = this._io.readU2le();
            this.tropoDelayCorrection = new TroposphericDelayCorrection(this._io, this, _root);
            this.stecResiduals = new ArrayList<StecResidual>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.stecResiduals.add(new StecResidual(this._io, this, _root));
                    i++;
                }
            }
        }
        private GriddedCorrectionHeader header;
        private int index;
        private TroposphericDelayCorrection tropoDelayCorrection;
        private ArrayList<StecResidual> stecResiduals;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * Header of a gridded correction message
         */
        public GriddedCorrectionHeader header() { return header; }

        /**
         * Index of the grid point.
         */
        public int index() { return index; }

        /**
         * Wet and hydrostatic vertical delays (mean, stddev).
         */
        public TroposphericDelayCorrection tropoDelayCorrection() { return tropoDelayCorrection; }

        /**
         * STEC residuals for each satellite (mean, stddev).
         */
        public ArrayList<StecResidual> stecResiduals() { return stecResiduals; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * STEC residual (mean and standard deviation) for the given satellite at
     * the grid point.
     */
    public static class StecResidual extends KaitaiStruct {
        public static StecResidual fromFile(String fileName) throws IOException {
            return new StecResidual(new ByteBufferKaitaiStream(fileName));
        }

        public StecResidual(KaitaiStream _io) {
            this(_io, null, null);
        }

        public StecResidual(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public StecResidual(KaitaiStream _io, KaitaiStruct _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.svId = new Gnss.SvId(this._io, this, _root);
            this.residual = this._io.readS2le();
            this.stddev = this._io.readU1();
        }
        private Gnss.SvId svId;
        private short residual;
        private int stddev;
        private Ssr _root;
        private KaitaiStruct _parent;

        /**
         * space vehicle identifier
         */
        public Gnss.SvId svId() { return svId; }

        /**
         * STEC residual
         */
        public short residual() { return residual; }

        /**
         * Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
         * value/16) - 1) * 10
         */
        public int stddev() { return stddev; }
        public Ssr _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }
    public static class CodePhaseBiasesSatSig extends KaitaiStruct {
        public static CodePhaseBiasesSatSig fromFile(String fileName) throws IOException {
            return new CodePhaseBiasesSatSig(new ByteBufferKaitaiStream(fileName));
        }

        public CodePhaseBiasesSatSig(KaitaiStream _io) {
            this(_io, null, null);
        }

        public CodePhaseBiasesSatSig(KaitaiStream _io, Ssr.MsgSsrCodePhaseBiasesBounds _parent) {
            this(_io, _parent, null);
        }

        public CodePhaseBiasesSatSig(KaitaiStream _io, Ssr.MsgSsrCodePhaseBiasesBounds _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.satId = this._io.readU1();
            this.signalId = this._io.readU1();
            this.codeBiasBoundMu = this._io.readU1();
            this.codeBiasBoundSig = this._io.readU1();
            this.phaseBiasBoundMu = this._io.readU1();
            this.phaseBiasBoundSig = this._io.readU1();
        }
        private int satId;
        private int signalId;
        private int codeBiasBoundMu;
        private int codeBiasBoundSig;
        private int phaseBiasBoundMu;
        private int phaseBiasBoundSig;
        private Ssr _root;
        private Ssr.MsgSsrCodePhaseBiasesBounds _parent;

        /**
         * Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
         * or DF488 (BDS) depending on the constellation.
         */
        public int satId() { return satId; }

        /**
         * Signal and Tracking Mode Identifier. Similar to either RTCM DF380
         * (GPS), DF382 (Galileo) or DF467 (BDS) depending on the
         * constellation.
         */
        public int signalId() { return signalId; }

        /**
         * Code Bias Mean. Range: 0-1.275 m
         */
        public int codeBiasBoundMu() { return codeBiasBoundMu; }

        /**
         * Code Bias Standard Deviation.  Range: 0-1.275 m
         */
        public int codeBiasBoundSig() { return codeBiasBoundSig; }

        /**
         * Phase Bias Mean. Range: 0-1.275 m
         */
        public int phaseBiasBoundMu() { return phaseBiasBoundMu; }

        /**
         * Phase Bias Standard Deviation.  Range: 0-1.275 m
         */
        public int phaseBiasBoundSig() { return phaseBiasBoundSig; }
        public Ssr _root() { return _root; }
        public Ssr.MsgSsrCodePhaseBiasesBounds _parent() { return _parent; }
    }

    /**
     * Contains phase center offset and elevation variation corrections for one
     * signal on a satellite.
     */
    public static class SatelliteApc extends KaitaiStruct {
        public static SatelliteApc fromFile(String fileName) throws IOException {
            return new SatelliteApc(new ByteBufferKaitaiStream(fileName));
        }

        public SatelliteApc(KaitaiStream _io) {
            this(_io, null, null);
        }

        public SatelliteApc(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public SatelliteApc(KaitaiStream _io, KaitaiStruct _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.satInfo = this._io.readU1();
            this.svn = this._io.readU2le();
            this.pco = new ArrayList<Short>();
            for (int i = 0; i < 3; i++) {
                this.pco.add(this._io.readS2le());
            }
            this.pcv = new ArrayList<Byte>();
            for (int i = 0; i < 21; i++) {
                this.pcv.add(this._io.readS1());
            }
        }
        private Gnss.GnssSignal sid;
        private int satInfo;
        private int svn;
        private ArrayList<Short> pco;
        private ArrayList<Byte> pcv;
        private Ssr _root;
        private KaitaiStruct _parent;

        /**
         * GNSS signal identifier (16 bit)
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * Additional satellite information
         */
        public int satInfo() { return satInfo; }

        /**
         * Satellite Code, as defined by IGS. Typically the space vehicle
         * number.
         */
        public int svn() { return svn; }

        /**
         * Mean phase center offset, X Y and Z axes. See IGS ANTEX file format
         * description for coordinate system definition.
         */
        public ArrayList<Short> pco() { return pco; }

        /**
         * Elevation dependent phase center variations. First element is 0
         * degrees separation from the Z axis, subsequent elements represent
         * elevation variations in 1 degree increments.
         */
        public ArrayList<Byte> pcv() { return pcv; }
        public Ssr _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * The LPP message contains nested variable length arrays which are not
     * supported in SBP, so each grid point will be identified by the index.
     */
    public static class GriddedCorrectionHeader extends KaitaiStruct {
        public static GriddedCorrectionHeader fromFile(String fileName) throws IOException {
            return new GriddedCorrectionHeader(new ByteBufferKaitaiStream(fileName));
        }

        public GriddedCorrectionHeader(KaitaiStream _io) {
            this(_io, null, null);
        }

        public GriddedCorrectionHeader(KaitaiStream _io, Ssr.MsgSsrGriddedCorrection _parent) {
            this(_io, _parent, null);
        }

        public GriddedCorrectionHeader(KaitaiStream _io, Ssr.MsgSsrGriddedCorrection _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tileSetId = this._io.readU2le();
            this.tileId = this._io.readU2le();
            this.time = new Gnss.GpsTimeSec(this._io, this, _root);
            this.numMsgs = this._io.readU2le();
            this.seqNum = this._io.readU2le();
            this.updateInterval = this._io.readU1();
            this.iodAtmo = this._io.readU1();
            this.tropoQualityIndicator = this._io.readU1();
        }
        private int tileSetId;
        private int tileId;
        private Gnss.GpsTimeSec time;
        private int numMsgs;
        private int seqNum;
        private int updateInterval;
        private int iodAtmo;
        private int tropoQualityIndicator;
        private Ssr _root;
        private Ssr.MsgSsrGriddedCorrection _parent;

        /**
         * Unique identifier of the tile set this tile belongs to.
         */
        public int tileSetId() { return tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         */
        public int tileId() { return tileId; }

        /**
         * GNSS reference time of the correction
         */
        public Gnss.GpsTimeSec time() { return time; }

        /**
         * Number of messages in the dataset
         */
        public int numMsgs() { return numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public int seqNum() { return seqNum; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public int updateInterval() { return updateInterval; }

        /**
         * IOD of the SSR atmospheric correction
         */
        public int iodAtmo() { return iodAtmo; }

        /**
         * Quality of the troposphere data. Encoded following RTCM DF389
         * specification in units of m.
         */
        public int tropoQualityIndicator() { return tropoQualityIndicator; }
        public Ssr _root() { return _root; }
        public Ssr.MsgSsrGriddedCorrection _parent() { return _parent; }
    }

    /**
     * STEC polynomial for the given satellite.
     */
    public static class StecSatElement extends KaitaiStruct {
        public static StecSatElement fromFile(String fileName) throws IOException {
            return new StecSatElement(new ByteBufferKaitaiStream(fileName));
        }

        public StecSatElement(KaitaiStream _io) {
            this(_io, null, null);
        }

        public StecSatElement(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public StecSatElement(KaitaiStream _io, KaitaiStruct _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.svId = new Gnss.SvId(this._io, this, _root);
            this.stecQualityIndicator = this._io.readU1();
            this.stecCoeff = new ArrayList<Short>();
            for (int i = 0; i < 4; i++) {
                this.stecCoeff.add(this._io.readS2le());
            }
        }
        private Gnss.SvId svId;
        private int stecQualityIndicator;
        private ArrayList<Short> stecCoeff;
        private Ssr _root;
        private KaitaiStruct _parent;

        /**
         * Unique space vehicle identifier
         */
        public Gnss.SvId svId() { return svId; }

        /**
         * Quality of the STEC data. Encoded following RTCM DF389 specification
         * but in units of TECU instead of m.
         */
        public int stecQualityIndicator() { return stecQualityIndicator; }

        /**
         * Coefficients of the STEC polynomial in the order of C00, C01, C10,
         * C11. C00 = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2
         */
        public ArrayList<Short> stecCoeff() { return stecCoeff; }
        public Ssr _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * A full set of STEC information will likely span multiple SBP messages,
     * since SBP message a limited to 255 bytes.  The header is used to tie
     * multiple SBP messages into a sequence.
     */
    public static class StecHeaderDepA extends KaitaiStruct {
        public static StecHeaderDepA fromFile(String fileName) throws IOException {
            return new StecHeaderDepA(new ByteBufferKaitaiStream(fileName));
        }

        public StecHeaderDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public StecHeaderDepA(KaitaiStream _io, Ssr.MsgSsrStecCorrectionDepA _parent) {
            this(_io, _parent, null);
        }

        public StecHeaderDepA(KaitaiStream _io, Ssr.MsgSsrStecCorrectionDepA _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.time = new Gnss.GpsTimeSec(this._io, this, _root);
            this.numMsgs = this._io.readU1();
            this.seqNum = this._io.readU1();
            this.updateInterval = this._io.readU1();
            this.iodAtmo = this._io.readU1();
        }
        private Gnss.GpsTimeSec time;
        private int numMsgs;
        private int seqNum;
        private int updateInterval;
        private int iodAtmo;
        private Ssr _root;
        private Ssr.MsgSsrStecCorrectionDepA _parent;

        /**
         * GNSS reference time of the correction
         */
        public Gnss.GpsTimeSec time() { return time; }

        /**
         * Number of messages in the dataset
         */
        public int numMsgs() { return numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public int seqNum() { return seqNum; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public int updateInterval() { return updateInterval; }

        /**
         * IOD of the SSR atmospheric correction
         */
        public int iodAtmo() { return iodAtmo; }
        public Ssr _root() { return _root; }
        public Ssr.MsgSsrStecCorrectionDepA _parent() { return _parent; }
    }

    /**
     * A full set of STEC information will likely span multiple SBP messages,
     * since SBP message a limited to 255 bytes.  The header is used to tie
     * multiple SBP messages into a sequence.
     */
    public static class StecHeader extends KaitaiStruct {
        public static StecHeader fromFile(String fileName) throws IOException {
            return new StecHeader(new ByteBufferKaitaiStream(fileName));
        }

        public StecHeader(KaitaiStream _io) {
            this(_io, null, null);
        }

        public StecHeader(KaitaiStream _io, Ssr.MsgSsrStecCorrectionDep _parent) {
            this(_io, _parent, null);
        }

        public StecHeader(KaitaiStream _io, Ssr.MsgSsrStecCorrectionDep _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tileSetId = this._io.readU2le();
            this.tileId = this._io.readU2le();
            this.time = new Gnss.GpsTimeSec(this._io, this, _root);
            this.numMsgs = this._io.readU1();
            this.seqNum = this._io.readU1();
            this.updateInterval = this._io.readU1();
            this.iodAtmo = this._io.readU1();
        }
        private int tileSetId;
        private int tileId;
        private Gnss.GpsTimeSec time;
        private int numMsgs;
        private int seqNum;
        private int updateInterval;
        private int iodAtmo;
        private Ssr _root;
        private Ssr.MsgSsrStecCorrectionDep _parent;

        /**
         * Unique identifier of the tile set this tile belongs to.
         */
        public int tileSetId() { return tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         */
        public int tileId() { return tileId; }

        /**
         * GNSS reference time of the correction
         */
        public Gnss.GpsTimeSec time() { return time; }

        /**
         * Number of messages in the dataset
         */
        public int numMsgs() { return numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public int seqNum() { return seqNum; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public int updateInterval() { return updateInterval; }

        /**
         * IOD of the SSR atmospheric correction
         */
        public int iodAtmo() { return iodAtmo; }
        public Ssr _root() { return _root; }
        public Ssr.MsgSsrStecCorrectionDep _parent() { return _parent; }
    }
    public static class MsgSsrStecCorrectionDepA extends KaitaiStruct {
        public static MsgSsrStecCorrectionDepA fromFile(String fileName) throws IOException {
            return new MsgSsrStecCorrectionDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrStecCorrectionDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrStecCorrectionDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrStecCorrectionDepA(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new StecHeaderDepA(this._io, this, _root);
            this.stecSatList = new ArrayList<StecSatElement>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.stecSatList.add(new StecSatElement(this._io, this, _root));
                    i++;
                }
            }
        }
        private StecHeaderDepA header;
        private ArrayList<StecSatElement> stecSatList;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * Header of a STEC message
         */
        public StecHeaderDepA header() { return header; }

        /**
         * Array of STEC information for each space vehicle
         */
        public ArrayList<StecSatElement> stecSatList() { return stecSatList; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The 3GPP message contains nested variable length arrays which are not
     * supported in SBP, so each grid point will be identified by the index.
     */
    public static class GriddedCorrectionHeaderDepA extends KaitaiStruct {
        public static GriddedCorrectionHeaderDepA fromFile(String fileName) throws IOException {
            return new GriddedCorrectionHeaderDepA(new ByteBufferKaitaiStream(fileName));
        }

        public GriddedCorrectionHeaderDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public GriddedCorrectionHeaderDepA(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public GriddedCorrectionHeaderDepA(KaitaiStream _io, KaitaiStruct _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.time = new Gnss.GpsTimeSec(this._io, this, _root);
            this.numMsgs = this._io.readU2le();
            this.seqNum = this._io.readU2le();
            this.updateInterval = this._io.readU1();
            this.iodAtmo = this._io.readU1();
            this.tropoQualityIndicator = this._io.readU1();
        }
        private Gnss.GpsTimeSec time;
        private int numMsgs;
        private int seqNum;
        private int updateInterval;
        private int iodAtmo;
        private int tropoQualityIndicator;
        private Ssr _root;
        private KaitaiStruct _parent;

        /**
         * GNSS reference time of the correction
         */
        public Gnss.GpsTimeSec time() { return time; }

        /**
         * Number of messages in the dataset
         */
        public int numMsgs() { return numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public int seqNum() { return seqNum; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public int updateInterval() { return updateInterval; }

        /**
         * IOD of the SSR atmospheric correction
         */
        public int iodAtmo() { return iodAtmo; }

        /**
         * Quality of the troposphere data. Encoded following RTCM DF389
         * specification in units of m.
         */
        public int tropoQualityIndicator() { return tropoQualityIndicator; }
        public Ssr _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * Note 1: Range: 0-17.5 m. i<=200, mean=0.01i; 200<i<=230,
     * mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
     * 
     * Note 2: Range: 0-17.5 m. i<=200, std=0.01i; 200<i<=230, std=2+0.1(i-200)
     * i>230, std=5+0.5(i-230).
     */
    public static class MsgSsrOrbitClockBounds extends KaitaiStruct {
        public static MsgSsrOrbitClockBounds fromFile(String fileName) throws IOException {
            return new MsgSsrOrbitClockBounds(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrOrbitClockBounds(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrOrbitClockBounds(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrOrbitClockBounds(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new BoundsHeader(this._io, this, _root);
            this.ssrIod = this._io.readU1();
            this.constId = this._io.readU1();
            this.nSats = this._io.readU1();
            this.orbitClockBounds = new ArrayList<OrbitClockBound>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.orbitClockBounds.add(new OrbitClockBound(this._io, this, _root));
                    i++;
                }
            }
        }
        private BoundsHeader header;
        private int ssrIod;
        private int constId;
        private int nSats;
        private ArrayList<OrbitClockBound> orbitClockBounds;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * Header of a bounds message.
         */
        public BoundsHeader header() { return header; }

        /**
         * IOD of the SSR bound.
         */
        public int ssrIod() { return ssrIod; }

        /**
         * Constellation ID to which the SVs belong.
         */
        public int constId() { return constId; }

        /**
         * Number of satellites.
         */
        public int nSats() { return nSats; }

        /**
         * Orbit and Clock Bounds per Satellite
         */
        public ArrayList<OrbitClockBound> orbitClockBounds() { return orbitClockBounds; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Note 1: Range: 0-17.5 m. i<= 200, mean = 0.01i; 200<i<=230,
     * mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
     */
    public static class MsgSsrGriddedCorrectionBounds extends KaitaiStruct {
        public static MsgSsrGriddedCorrectionBounds fromFile(String fileName) throws IOException {
            return new MsgSsrGriddedCorrectionBounds(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrGriddedCorrectionBounds(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrGriddedCorrectionBounds(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrGriddedCorrectionBounds(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new BoundsHeader(this._io, this, _root);
            this.ssrIodAtmo = this._io.readU1();
            this.tileSetId = this._io.readU2le();
            this.tileId = this._io.readU2le();
            this.tropoQi = this._io.readU1();
            this.gridPointId = this._io.readU2le();
            this.tropoDelayCorrection = new TroposphericDelayCorrection(this._io, this, _root);
            this.tropoVHydroBoundMu = this._io.readU1();
            this.tropoVHydroBoundSig = this._io.readU1();
            this.tropoVWetBoundMu = this._io.readU1();
            this.tropoVWetBoundSig = this._io.readU1();
            this.nSats = this._io.readU1();
            this.stecSatList = new ArrayList<StecSatElementIntegrity>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.stecSatList.add(new StecSatElementIntegrity(this._io, this, _root));
                    i++;
                }
            }
        }
        private BoundsHeader header;
        private int ssrIodAtmo;
        private int tileSetId;
        private int tileId;
        private int tropoQi;
        private int gridPointId;
        private TroposphericDelayCorrection tropoDelayCorrection;
        private int tropoVHydroBoundMu;
        private int tropoVHydroBoundSig;
        private int tropoVWetBoundMu;
        private int tropoVWetBoundSig;
        private int nSats;
        private ArrayList<StecSatElementIntegrity> stecSatList;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * Header of a bounds message.
         */
        public BoundsHeader header() { return header; }

        /**
         * IOD of the correction.
         */
        public int ssrIodAtmo() { return ssrIodAtmo; }

        /**
         * Set this tile belongs to.
         */
        public int tileSetId() { return tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         */
        public int tileId() { return tileId; }

        /**
         * Tropo Quality Indicator. Similar to RTCM DF389.
         */
        public int tropoQi() { return tropoQi; }

        /**
         * Index of the Grid Point.
         */
        public int gridPointId() { return gridPointId; }

        /**
         * Tropospheric delay at grid point.
         */
        public TroposphericDelayCorrection tropoDelayCorrection() { return tropoDelayCorrection; }

        /**
         * Vertical Hydrostatic Error Bound Mean.
         */
        public int tropoVHydroBoundMu() { return tropoVHydroBoundMu; }

        /**
         * Vertical Hydrostatic Error Bound StDev.
         */
        public int tropoVHydroBoundSig() { return tropoVHydroBoundSig; }

        /**
         * Vertical Wet Error Bound Mean.
         */
        public int tropoVWetBoundMu() { return tropoVWetBoundMu; }

        /**
         * Vertical Wet Error Bound StDev.
         */
        public int tropoVWetBoundSig() { return tropoVWetBoundSig; }

        /**
         * Number of satellites.
         */
        public int nSats() { return nSats; }

        /**
         * Array of STEC polynomial coefficients and its bounds for each space
         * vehicle.
         */
        public ArrayList<StecSatElementIntegrity> stecSatList() { return stecSatList; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class MsgSsrGridDefinitionDepA extends KaitaiStruct {
        public static MsgSsrGridDefinitionDepA fromFile(String fileName) throws IOException {
            return new MsgSsrGridDefinitionDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrGridDefinitionDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrGridDefinitionDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrGridDefinitionDepA(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new GridDefinitionHeaderDepA(this._io, this, _root);
            this.rleList = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.rleList.add(this._io.readU1());
                    i++;
                }
            }
        }
        private GridDefinitionHeaderDepA header;
        private ArrayList<Integer> rleList;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * Header of a Gridded Correction message
         */
        public GridDefinitionHeaderDepA header() { return header; }

        /**
         * Run Length Encode list of quadrants that contain valid data. The
         * spec describes the encoding scheme in detail, but essentially the
         * index of the quadrants that contain transitions between valid and
         * invalid (and vice versa) are encoded as u8 integers.
         */
        public ArrayList<Integer> rleList() { return rleList; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Code biases are to be added to pseudorange. The corrections conform with
     * RTCMv3 MT 1059 / 1065.
     */
    public static class CodeBiasesContent extends KaitaiStruct {
        public static CodeBiasesContent fromFile(String fileName) throws IOException {
            return new CodeBiasesContent(new ByteBufferKaitaiStream(fileName));
        }

        public CodeBiasesContent(KaitaiStream _io) {
            this(_io, null, null);
        }

        public CodeBiasesContent(KaitaiStream _io, Ssr.MsgSsrCodeBiases _parent) {
            this(_io, _parent, null);
        }

        public CodeBiasesContent(KaitaiStream _io, Ssr.MsgSsrCodeBiases _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.code = this._io.readU1();
            this.value = this._io.readS2le();
        }
        private int code;
        private short value;
        private Ssr _root;
        private Ssr.MsgSsrCodeBiases _parent;

        /**
         * Signal encoded following RTCM specifications (DF380, DF381, DF382
         * and DF467).
         */
        public int code() { return code; }

        /**
         * Code bias value
         */
        public short value() { return value; }
        public Ssr _root() { return _root; }
        public Ssr.MsgSsrCodeBiases _parent() { return _parent; }
    }
    public static class MsgSsrSatelliteApc extends KaitaiStruct {
        public static MsgSsrSatelliteApc fromFile(String fileName) throws IOException {
            return new MsgSsrSatelliteApc(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrSatelliteApc(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrSatelliteApc(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrSatelliteApc(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.time = new Gnss.GpsTimeSec(this._io, this, _root);
            this.updateInterval = this._io.readU1();
            this.solId = this._io.readU1();
            this.iodSsr = this._io.readU1();
            this.apc = new ArrayList<SatelliteApc>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.apc.add(new SatelliteApc(this._io, this, _root));
                    i++;
                }
            }
        }
        private Gnss.GpsTimeSec time;
        private int updateInterval;
        private int solId;
        private int iodSsr;
        private ArrayList<SatelliteApc> apc;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * GNSS reference time of the correction
         */
        public Gnss.GpsTimeSec time() { return time; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public int updateInterval() { return updateInterval; }

        /**
         * SSR Solution ID. Similar to RTCM DF415.
         */
        public int solId() { return solId; }

        /**
         * IOD of the SSR correction. A change of Issue Of Data SSR is used to
         * indicate a change in the SSR generating configuration
         */
        public int iodSsr() { return iodSsr; }

        /**
         * Satellite antenna phase center corrections
         */
        public ArrayList<SatelliteApc> apc() { return apc; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Phase biases are to be added to carrier phase measurements.
     */
    public static class PhaseBiasesContent extends KaitaiStruct {
        public static PhaseBiasesContent fromFile(String fileName) throws IOException {
            return new PhaseBiasesContent(new ByteBufferKaitaiStream(fileName));
        }

        public PhaseBiasesContent(KaitaiStream _io) {
            this(_io, null, null);
        }

        public PhaseBiasesContent(KaitaiStream _io, Ssr.MsgSsrPhaseBiases _parent) {
            this(_io, _parent, null);
        }

        public PhaseBiasesContent(KaitaiStream _io, Ssr.MsgSsrPhaseBiases _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.code = this._io.readU1();
            this.integerIndicator = this._io.readU1();
            this.widelaneIntegerIndicator = this._io.readU1();
            this.discontinuityCounter = this._io.readU1();
            this.bias = this._io.readS4le();
        }
        private int code;
        private int integerIndicator;
        private int widelaneIntegerIndicator;
        private int discontinuityCounter;
        private int bias;
        private Ssr _root;
        private Ssr.MsgSsrPhaseBiases _parent;

        /**
         * Signal encoded following RTCM specifications (DF380, DF381, DF382
         * and DF467)
         */
        public int code() { return code; }

        /**
         * Indicator for integer property
         */
        public int integerIndicator() { return integerIndicator; }

        /**
         * Indicator for two groups of Wide-Lane(s) integer property
         */
        public int widelaneIntegerIndicator() { return widelaneIntegerIndicator; }

        /**
         * Signal phase discontinuity counter. Increased for every
         * discontinuity in phase.
         */
        public int discontinuityCounter() { return discontinuityCounter; }

        /**
         * Phase bias for specified signal
         */
        public int bias() { return bias; }
        public Ssr _root() { return _root; }
        public Ssr.MsgSsrPhaseBiases _parent() { return _parent; }
    }

    /**
     * Provides the correction point coordinates for the atmospheric correction
     * values in the MSG_SSR_STEC_CORRECTION_DEP and MSG_SSR_GRIDDED_CORRECTION
     * messages.
     * 
     * Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
     * element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
     * correction points, not lists of points.
     */
    public static class MsgSsrTileDefinitionDepA extends KaitaiStruct {
        public static MsgSsrTileDefinitionDepA fromFile(String fileName) throws IOException {
            return new MsgSsrTileDefinitionDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrTileDefinitionDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrTileDefinitionDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrTileDefinitionDepA(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.tileSetId = this._io.readU2le();
            this.tileId = this._io.readU2le();
            this.cornerNwLat = this._io.readS2le();
            this.cornerNwLon = this._io.readS2le();
            this.spacingLat = this._io.readU2le();
            this.spacingLon = this._io.readU2le();
            this.rows = this._io.readU2le();
            this.cols = this._io.readU2le();
            this.bitmask = this._io.readU8le();
        }
        private int tileSetId;
        private int tileId;
        private short cornerNwLat;
        private short cornerNwLon;
        private int spacingLat;
        private int spacingLon;
        private int rows;
        private int cols;
        private long bitmask;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * Unique identifier of the tile set this tile belongs to.
         */
        public int tileSetId() { return tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
         */
        public int tileId() { return tileId; }

        /**
         * North-West corner correction point latitude.
         * 
         * The relation between the latitude X in the range [-90, 90] and the
         * coded number N is:
         * 
         * N = floor((X / 90) * 2^14)
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
         */
        public short cornerNwLat() { return cornerNwLat; }

        /**
         * North-West corner correction point longitude.
         * 
         * The relation between the longitude X in the range [-180, 180] and
         * the coded number N is:
         * 
         * N = floor((X / 180) * 2^15)
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
         */
        public short cornerNwLon() { return cornerNwLon; }

        /**
         * Spacing of the correction points in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
         */
        public int spacingLat() { return spacingLat; }

        /**
         * Spacing of the correction points in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
         */
        public int spacingLon() { return spacingLon; }

        /**
         * Number of steps in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
         */
        public int rows() { return rows; }

        /**
         * Number of steps in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
         */
        public int cols() { return cols; }

        /**
         * Specifies the availability of correction data at the correction
         * points in the array.
         * 
         * If a specific bit is enabled (set to 1), the correction is not
         * available. Only the first rows * cols bits are used, the remainder
         * are set to 0. If there are more then 64 correction points the
         * remaining corrections are always available.
         * 
         * Starting with the northwest corner of the array (top left on a north
         * oriented map) the correction points are enumerated with row
         * precedence - first row west to east, second row west to east, until
         * last row west to east - ending with the southeast corner of the
         * array.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
         * the definition of the bits is inverted.
         */
        public long bitmask() { return bitmask; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Orbit and clock bound.
     */
    public static class OrbitClockBound extends KaitaiStruct {
        public static OrbitClockBound fromFile(String fileName) throws IOException {
            return new OrbitClockBound(new ByteBufferKaitaiStream(fileName));
        }

        public OrbitClockBound(KaitaiStream _io) {
            this(_io, null, null);
        }

        public OrbitClockBound(KaitaiStream _io, Ssr.MsgSsrOrbitClockBounds _parent) {
            this(_io, _parent, null);
        }

        public OrbitClockBound(KaitaiStream _io, Ssr.MsgSsrOrbitClockBounds _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.satId = this._io.readU1();
            this.orbRadialBoundMu = this._io.readU1();
            this.orbAlongBoundMu = this._io.readU1();
            this.orbCrossBoundMu = this._io.readU1();
            this.orbRadialBoundSig = this._io.readU1();
            this.orbAlongBoundSig = this._io.readU1();
            this.orbCrossBoundSig = this._io.readU1();
            this.clockBoundMu = this._io.readU1();
            this.clockBoundSig = this._io.readU1();
        }
        private int satId;
        private int orbRadialBoundMu;
        private int orbAlongBoundMu;
        private int orbCrossBoundMu;
        private int orbRadialBoundSig;
        private int orbAlongBoundSig;
        private int orbCrossBoundSig;
        private int clockBoundMu;
        private int clockBoundSig;
        private Ssr _root;
        private Ssr.MsgSsrOrbitClockBounds _parent;

        /**
         * Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
         * or DF488 (BDS) depending on the constellation.
         */
        public int satId() { return satId; }

        /**
         * Mean Radial. See Note 1.
         */
        public int orbRadialBoundMu() { return orbRadialBoundMu; }

        /**
         * Mean Along-Track. See Note 1.
         */
        public int orbAlongBoundMu() { return orbAlongBoundMu; }

        /**
         * Mean Cross-Track. See Note 1.
         */
        public int orbCrossBoundMu() { return orbCrossBoundMu; }

        /**
         * Standard Deviation Radial. See Note 2.
         */
        public int orbRadialBoundSig() { return orbRadialBoundSig; }

        /**
         * Standard Deviation Along-Track. See Note 2.
         */
        public int orbAlongBoundSig() { return orbAlongBoundSig; }

        /**
         * Standard Deviation Cross-Track. See Note 2.
         */
        public int orbCrossBoundSig() { return orbCrossBoundSig; }

        /**
         * Clock Bound Mean. See Note 1.
         */
        public int clockBoundMu() { return clockBoundMu; }

        /**
         * Clock Bound Standard Deviation. See Note 2.
         */
        public int clockBoundSig() { return clockBoundSig; }
        public Ssr _root() { return _root; }
        public Ssr.MsgSsrOrbitClockBounds _parent() { return _parent; }
    }
    public static class MsgSsrGriddedCorrectionDepA extends KaitaiStruct {
        public static MsgSsrGriddedCorrectionDepA fromFile(String fileName) throws IOException {
            return new MsgSsrGriddedCorrectionDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrGriddedCorrectionDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrGriddedCorrectionDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrGriddedCorrectionDepA(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new GriddedCorrectionHeaderDepA(this._io, this, _root);
            this.index = this._io.readU2le();
            this.tropoDelayCorrection = new TroposphericDelayCorrection(this._io, this, _root);
            this.stecResiduals = new ArrayList<StecResidual>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.stecResiduals.add(new StecResidual(this._io, this, _root));
                    i++;
                }
            }
        }
        private GriddedCorrectionHeaderDepA header;
        private int index;
        private TroposphericDelayCorrection tropoDelayCorrection;
        private ArrayList<StecResidual> stecResiduals;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * Header of a Gridded Correction message
         */
        public GriddedCorrectionHeaderDepA header() { return header; }

        /**
         * Index of the grid point
         */
        public int index() { return index; }

        /**
         * Wet and hydrostatic vertical delays (mean, stddev)
         */
        public TroposphericDelayCorrection tropoDelayCorrection() { return tropoDelayCorrection; }

        /**
         * STEC residuals for each satellite (mean, stddev)
         */
        public ArrayList<StecResidual> stecResiduals() { return stecResiduals; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class MsgSsrOrbitClockBoundsDegradation extends KaitaiStruct {
        public static MsgSsrOrbitClockBoundsDegradation fromFile(String fileName) throws IOException {
            return new MsgSsrOrbitClockBoundsDegradation(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrOrbitClockBoundsDegradation(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrOrbitClockBoundsDegradation(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrOrbitClockBoundsDegradation(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new BoundsHeader(this._io, this, _root);
            this.ssrIod = this._io.readU1();
            this.constId = this._io.readU1();
            this.satBitmask = this._io.readU8le();
            this.orbitClockBoundsDegradation = new OrbitClockBoundDegradation(this._io, this, _root);
        }
        private BoundsHeader header;
        private int ssrIod;
        private int constId;
        private long satBitmask;
        private OrbitClockBoundDegradation orbitClockBoundsDegradation;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * Header of a bounds message.
         */
        public BoundsHeader header() { return header; }

        /**
         * IOD of the SSR bound degradation parameter.
         */
        public int ssrIod() { return ssrIod; }

        /**
         * Constellation ID to which the SVs belong.
         */
        public int constId() { return constId; }

        /**
         * Satellite Bit Mask. Put 1 for each satellite where the following
         * degradation parameters are applicable, 0 otherwise. Encoded
         * following RTCM DF394 specification.
         */
        public long satBitmask() { return satBitmask; }

        /**
         * Orbit and Clock Bounds Degradation Parameters
         */
        public OrbitClockBoundDegradation orbitClockBoundsDegradation() { return orbitClockBoundsDegradation; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class MsgSsrGriddedCorrectionNoStdDepA extends KaitaiStruct {
        public static MsgSsrGriddedCorrectionNoStdDepA fromFile(String fileName) throws IOException {
            return new MsgSsrGriddedCorrectionNoStdDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrGriddedCorrectionNoStdDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrGriddedCorrectionNoStdDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrGriddedCorrectionNoStdDepA(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new GriddedCorrectionHeaderDepA(this._io, this, _root);
            this.index = this._io.readU2le();
            this.tropoDelayCorrection = new TroposphericDelayCorrectionNoStd(this._io, this, _root);
            this.stecResiduals = new ArrayList<StecResidualNoStd>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.stecResiduals.add(new StecResidualNoStd(this._io, this, _root));
                    i++;
                }
            }
        }
        private GriddedCorrectionHeaderDepA header;
        private int index;
        private TroposphericDelayCorrectionNoStd tropoDelayCorrection;
        private ArrayList<StecResidualNoStd> stecResiduals;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * Header of a Gridded Correction message
         */
        public GriddedCorrectionHeaderDepA header() { return header; }

        /**
         * Index of the grid point
         */
        public int index() { return index; }

        /**
         * Wet and hydrostatic vertical delays
         */
        public TroposphericDelayCorrectionNoStd tropoDelayCorrection() { return tropoDelayCorrection; }

        /**
         * STEC residuals for each satellite
         */
        public ArrayList<StecResidualNoStd> stecResiduals() { return stecResiduals; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class MsgSsrCodePhaseBiasesBounds extends KaitaiStruct {
        public static MsgSsrCodePhaseBiasesBounds fromFile(String fileName) throws IOException {
            return new MsgSsrCodePhaseBiasesBounds(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrCodePhaseBiasesBounds(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrCodePhaseBiasesBounds(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrCodePhaseBiasesBounds(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.header = new BoundsHeader(this._io, this, _root);
            this.ssrIod = this._io.readU1();
            this.constId = this._io.readU1();
            this.nSatsSignals = this._io.readU1();
            this.satellitesSignals = new ArrayList<CodePhaseBiasesSatSig>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.satellitesSignals.add(new CodePhaseBiasesSatSig(this._io, this, _root));
                    i++;
                }
            }
        }
        private BoundsHeader header;
        private int ssrIod;
        private int constId;
        private int nSatsSignals;
        private ArrayList<CodePhaseBiasesSatSig> satellitesSignals;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * Header of a bounds message.
         */
        public BoundsHeader header() { return header; }

        /**
         * IOD of the SSR bound.
         */
        public int ssrIod() { return ssrIod; }

        /**
         * Constellation ID to which the SVs belong.
         */
        public int constId() { return constId; }

        /**
         * Number of satellite-signal couples.
         */
        public int nSatsSignals() { return nSatsSignals; }

        /**
         * Code and Phase Biases Bounds per Satellite-Signal couple.
         */
        public ArrayList<CodePhaseBiasesSatSig> satellitesSignals() { return satellitesSignals; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The precise code biases message is to be added to the pseudorange of the
     * corresponding signal to get corrected pseudorange. It is an equivalent
     * to the 1059 / 1065 RTCM message types.
     */
    public static class MsgSsrCodeBiases extends KaitaiStruct {
        public static MsgSsrCodeBiases fromFile(String fileName) throws IOException {
            return new MsgSsrCodeBiases(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrCodeBiases(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrCodeBiases(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrCodeBiases(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.time = new Gnss.GpsTimeSec(this._io, this, _root);
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.updateInterval = this._io.readU1();
            this.iodSsr = this._io.readU1();
            this.biases = new ArrayList<CodeBiasesContent>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.biases.add(new CodeBiasesContent(this._io, this, _root));
                    i++;
                }
            }
        }
        private Gnss.GpsTimeSec time;
        private Gnss.GnssSignal sid;
        private int updateInterval;
        private int iodSsr;
        private ArrayList<CodeBiasesContent> biases;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * GNSS reference time of the correction
         */
        public Gnss.GpsTimeSec time() { return time; }

        /**
         * GNSS signal identifier (16 bit)
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public int updateInterval() { return updateInterval; }

        /**
         * IOD of the SSR correction. A change of Issue Of Data SSR is used to
         * indicate a change in the SSR generating configuration
         */
        public int iodSsr() { return iodSsr; }

        /**
         * Code biases for the different satellite signals
         */
        public ArrayList<CodeBiasesContent> biases() { return biases; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Provides the correction point coordinates for the atmospheric correction
     * values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
     * messages.
     * 
     * Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
     * element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
     * correction points, not lists of points.
     */
    public static class MsgSsrTileDefinition extends KaitaiStruct {
        public static MsgSsrTileDefinition fromFile(String fileName) throws IOException {
            return new MsgSsrTileDefinition(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrTileDefinition(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrTileDefinition(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrTileDefinition(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.time = new Gnss.GpsTimeSec(this._io, this, _root);
            this.updateInterval = this._io.readU1();
            this.solId = this._io.readU1();
            this.iodAtmo = this._io.readU1();
            this.tileSetId = this._io.readU2le();
            this.tileId = this._io.readU2le();
            this.cornerNwLat = this._io.readS2le();
            this.cornerNwLon = this._io.readS2le();
            this.spacingLat = this._io.readU2le();
            this.spacingLon = this._io.readU2le();
            this.rows = this._io.readU2le();
            this.cols = this._io.readU2le();
            this.bitmask = this._io.readU8le();
        }
        private Gnss.GpsTimeSec time;
        private int updateInterval;
        private int solId;
        private int iodAtmo;
        private int tileSetId;
        private int tileId;
        private short cornerNwLat;
        private short cornerNwLon;
        private int spacingLat;
        private int spacingLon;
        private int rows;
        private int cols;
        private long bitmask;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * GNSS reference time of the correction
         */
        public Gnss.GpsTimeSec time() { return time; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public int updateInterval() { return updateInterval; }

        /**
         * SSR Solution ID. Similar to RTCM DF415.
         */
        public int solId() { return solId; }

        /**
         * IOD of the SSR atmospheric correction.
         */
        public int iodAtmo() { return iodAtmo; }

        /**
         * Unique identifier of the tile set this tile belongs to.
         */
        public int tileSetId() { return tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
         */
        public int tileId() { return tileId; }

        /**
         * North-West corner correction point latitude.
         * 
         * The relation between the latitude X in the range [-90, 90] and the
         * coded number N is:  N = floor((X / 90) * 2^14)
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
         */
        public short cornerNwLat() { return cornerNwLat; }

        /**
         * North-West corner correction point longitude.
         * 
         * The relation between the longitude X in the range [-180, 180] and
         * the coded number N is: N = floor((X / 180) * 2^15)
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
         */
        public short cornerNwLon() { return cornerNwLon; }

        /**
         * Spacing of the correction points in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
         */
        public int spacingLat() { return spacingLat; }

        /**
         * Spacing of the correction points in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
         */
        public int spacingLon() { return spacingLon; }

        /**
         * Number of steps in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
         */
        public int rows() { return rows; }

        /**
         * Number of steps in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
         */
        public int cols() { return cols; }

        /**
         * Specifies the absence of correction data at the correction points in
         * the array (grid).
         * 
         * Only the first rows * cols bits are used, and if a specific bit is
         * enabled (set to 1), the correction is not available. If there are
         * more than 64 correction points the remaining corrections are always
         * available.
         * 
         * The correction points are packed by rows, starting with the
         * northwest corner of the array (top-left on a north oriented map),
         * with each row spanning west to east, ending with the southeast
         * corner of the array.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
         * the definition of the bits is inverted.
         */
        public long bitmask() { return bitmask; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Orbit and clock bound degradation.
     */
    public static class OrbitClockBoundDegradation extends KaitaiStruct {
        public static OrbitClockBoundDegradation fromFile(String fileName) throws IOException {
            return new OrbitClockBoundDegradation(new ByteBufferKaitaiStream(fileName));
        }

        public OrbitClockBoundDegradation(KaitaiStream _io) {
            this(_io, null, null);
        }

        public OrbitClockBoundDegradation(KaitaiStream _io, Ssr.MsgSsrOrbitClockBoundsDegradation _parent) {
            this(_io, _parent, null);
        }

        public OrbitClockBoundDegradation(KaitaiStream _io, Ssr.MsgSsrOrbitClockBoundsDegradation _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.orbRadialBoundMuDot = this._io.readU1();
            this.orbAlongBoundMuDot = this._io.readU1();
            this.orbCrossBoundMuDot = this._io.readU1();
            this.orbRadialBoundSigDot = this._io.readU1();
            this.orbAlongBoundSigDot = this._io.readU1();
            this.orbCrossBoundSigDot = this._io.readU1();
            this.clockBoundMuDot = this._io.readU1();
            this.clockBoundSigDot = this._io.readU1();
        }
        private int orbRadialBoundMuDot;
        private int orbAlongBoundMuDot;
        private int orbCrossBoundMuDot;
        private int orbRadialBoundSigDot;
        private int orbAlongBoundSigDot;
        private int orbCrossBoundSigDot;
        private int clockBoundMuDot;
        private int clockBoundSigDot;
        private Ssr _root;
        private Ssr.MsgSsrOrbitClockBoundsDegradation _parent;

        /**
         * Orbit Bound Mean Radial First derivative. Range: 0-0.255 m/s
         */
        public int orbRadialBoundMuDot() { return orbRadialBoundMuDot; }

        /**
         * Orbit Bound Mean Along-Track First derivative. Range: 0-0.255 m/s
         */
        public int orbAlongBoundMuDot() { return orbAlongBoundMuDot; }

        /**
         * Orbit Bound Mean Cross-Track First derivative. Range: 0-0.255 m/s
         */
        public int orbCrossBoundMuDot() { return orbCrossBoundMuDot; }

        /**
         * Orbit Bound Standard Deviation Radial First derivative. Range:
         * 0-0.255 m/s
         */
        public int orbRadialBoundSigDot() { return orbRadialBoundSigDot; }

        /**
         * Orbit Bound Standard Deviation Along-Track First derivative. Range:
         * 0-0.255 m/s
         */
        public int orbAlongBoundSigDot() { return orbAlongBoundSigDot; }

        /**
         * Orbit Bound Standard Deviation Cross-Track First derivative. Range:
         * 0-0.255 m/s
         */
        public int orbCrossBoundSigDot() { return orbCrossBoundSigDot; }

        /**
         * Clock Bound Mean First derivative. Range: 0-0.255 m/s
         */
        public int clockBoundMuDot() { return clockBoundMuDot; }

        /**
         * Clock Bound Standard Deviation First derivative. Range: 0-0.255 m/s
         */
        public int clockBoundSigDot() { return clockBoundSigDot; }
        public Ssr _root() { return _root; }
        public Ssr.MsgSsrOrbitClockBoundsDegradation _parent() { return _parent; }
    }
    public static class MsgSsrSatelliteApcDep extends KaitaiStruct {
        public static MsgSsrSatelliteApcDep fromFile(String fileName) throws IOException {
            return new MsgSsrSatelliteApcDep(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrSatelliteApcDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrSatelliteApcDep(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrSatelliteApcDep(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.apc = new ArrayList<SatelliteApc>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.apc.add(new SatelliteApc(this._io, this, _root));
                    i++;
                }
            }
        }
        private ArrayList<SatelliteApc> apc;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * Satellite antenna phase center corrections
         */
        public ArrayList<SatelliteApc> apc() { return apc; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Troposphere vertical delays (mean and standard deviation) at the grid
     * point.
     */
    public static class TroposphericDelayCorrection extends KaitaiStruct {
        public static TroposphericDelayCorrection fromFile(String fileName) throws IOException {
            return new TroposphericDelayCorrection(new ByteBufferKaitaiStream(fileName));
        }

        public TroposphericDelayCorrection(KaitaiStream _io) {
            this(_io, null, null);
        }

        public TroposphericDelayCorrection(KaitaiStream _io, KaitaiStruct _parent) {
            this(_io, _parent, null);
        }

        public TroposphericDelayCorrection(KaitaiStream _io, KaitaiStruct _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.hydro = this._io.readS2le();
            this.wet = this._io.readS1();
            this.stddev = this._io.readU1();
        }
        private short hydro;
        private byte wet;
        private int stddev;
        private Ssr _root;
        private KaitaiStruct _parent;

        /**
         * Hydrostatic vertical delay. Add 2.3 m to get actual value.
         */
        public short hydro() { return hydro; }

        /**
         * Wet vertical delay. Add 0.252 m to get actual value.
         */
        public byte wet() { return wet; }

        /**
         * Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
         * value/16) - 1)
         */
        public int stddev() { return stddev; }
        public Ssr _root() { return _root; }
        public KaitaiStruct _parent() { return _parent; }
    }

    /**
     * Provides the correction point coordinates for the atmospheric correction
     * values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
     * messages.
     * 
     * Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
     * element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
     * correction points, not lists of points.
     */
    public static class MsgSsrTileDefinitionDepB extends KaitaiStruct {
        public static MsgSsrTileDefinitionDepB fromFile(String fileName) throws IOException {
            return new MsgSsrTileDefinitionDepB(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrTileDefinitionDepB(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrTileDefinitionDepB(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrTileDefinitionDepB(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.ssrSolId = this._io.readU1();
            this.tileSetId = this._io.readU2le();
            this.tileId = this._io.readU2le();
            this.cornerNwLat = this._io.readS2le();
            this.cornerNwLon = this._io.readS2le();
            this.spacingLat = this._io.readU2le();
            this.spacingLon = this._io.readU2le();
            this.rows = this._io.readU2le();
            this.cols = this._io.readU2le();
            this.bitmask = this._io.readU8le();
        }
        private int ssrSolId;
        private int tileSetId;
        private int tileId;
        private short cornerNwLat;
        private short cornerNwLon;
        private int spacingLat;
        private int spacingLon;
        private int rows;
        private int cols;
        private long bitmask;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * SSR Solution ID.
         */
        public int ssrSolId() { return ssrSolId; }

        /**
         * Unique identifier of the tile set this tile belongs to.
         */
        public int tileSetId() { return tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
         */
        public int tileId() { return tileId; }

        /**
         * North-West corner correction point latitude.
         * 
         * The relation between the latitude X in the range [-90, 90] and the
         * coded number N is:
         * 
         * N = floor((X / 90) * 2^14)
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
         */
        public short cornerNwLat() { return cornerNwLat; }

        /**
         * North-West corner correction point longitude.
         * 
         * The relation between the longitude X in the range [-180, 180] and
         * the coded number N is:
         * 
         * N = floor((X / 180) * 2^15)
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
         */
        public short cornerNwLon() { return cornerNwLon; }

        /**
         * Spacing of the correction points in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
         */
        public int spacingLat() { return spacingLat; }

        /**
         * Spacing of the correction points in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
         */
        public int spacingLon() { return spacingLon; }

        /**
         * Number of steps in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
         */
        public int rows() { return rows; }

        /**
         * Number of steps in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
         */
        public int cols() { return cols; }

        /**
         * Specifies the availability of correction data at the correction
         * points in the array.
         * 
         * If a specific bit is enabled (set to 1), the correction is not
         * available. Only the first rows * cols bits are used, the remainder
         * are set to 0. If there are more then 64 correction points the
         * remaining corrections are always available.
         * 
         * Starting with the northwest corner of the array (top left on a north
         * oriented map) the correction points are enumerated with row
         * precedence - first row west to east, second row west to east, until
         * last row west to east - ending with the southeast corner of the
         * array.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
         * the definition of the bits is inverted.
         */
        public long bitmask() { return bitmask; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The precise phase biases message contains the biases to be added to the
     * carrier phase of the corresponding signal to get corrected carrier phase
     * measurement, as well as the satellite yaw angle to be applied to compute
     * the phase wind-up correction. It is typically an equivalent to the 1265
     * RTCM message types.
     */
    public static class MsgSsrPhaseBiases extends KaitaiStruct {
        public static MsgSsrPhaseBiases fromFile(String fileName) throws IOException {
            return new MsgSsrPhaseBiases(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSsrPhaseBiases(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSsrPhaseBiases(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSsrPhaseBiases(KaitaiStream _io, Sbp.Message _parent, Ssr _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.time = new Gnss.GpsTimeSec(this._io, this, _root);
            this.sid = new Gnss.GnssSignal(this._io, this, _root);
            this.updateInterval = this._io.readU1();
            this.iodSsr = this._io.readU1();
            this.dispersiveBias = this._io.readU1();
            this.mwConsistency = this._io.readU1();
            this.yaw = this._io.readU2le();
            this.yawRate = this._io.readS1();
            this.biases = new ArrayList<PhaseBiasesContent>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.biases.add(new PhaseBiasesContent(this._io, this, _root));
                    i++;
                }
            }
        }
        private Gnss.GpsTimeSec time;
        private Gnss.GnssSignal sid;
        private int updateInterval;
        private int iodSsr;
        private int dispersiveBias;
        private int mwConsistency;
        private int yaw;
        private byte yawRate;
        private ArrayList<PhaseBiasesContent> biases;
        private Ssr _root;
        private Sbp.Message _parent;

        /**
         * GNSS reference time of the correction
         */
        public Gnss.GpsTimeSec time() { return time; }

        /**
         * GNSS signal identifier (16 bit)
         */
        public Gnss.GnssSignal sid() { return sid; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public int updateInterval() { return updateInterval; }

        /**
         * IOD of the SSR correction. A change of Issue Of Data SSR is used to
         * indicate a change in the SSR generating configuration
         */
        public int iodSsr() { return iodSsr; }

        /**
         * Indicator for the dispersive phase biases property.
         */
        public int dispersiveBias() { return dispersiveBias; }

        /**
         * Consistency indicator for Melbourne-Wubbena linear combinations
         */
        public int mwConsistency() { return mwConsistency; }

        /**
         * Satellite yaw angle
         */
        public int yaw() { return yaw; }

        /**
         * Satellite yaw angle rate
         */
        public byte yawRate() { return yawRate; }

        /**
         * Phase biases corrections for a satellite being tracked.
         */
        public ArrayList<PhaseBiasesContent> biases() { return biases; }
        public Ssr _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Ssr _root;
    private KaitaiStruct _parent;
    public Ssr _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
