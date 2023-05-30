// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class Sbp : KaitaiStruct
    {
        public static Sbp FromFile(string fileName)
        {
            return new Sbp(new KaitaiStream(fileName));
        }


        public enum MsgIds
        {
            MsgPrintDep = 16,
            MsgTrackingStateDetailedDep = 17,
            MsgTrackingStateDepB = 19,
            MsgAcqResultDepB = 20,
            MsgAcqResultDepA = 21,
            MsgTrackingStateDepA = 22,
            MsgThreadState = 23,
            MsgUartStateDepa = 24,
            MsgIarState = 25,
            MsgEphemerisDepA = 26,
            MsgMaskSatelliteDep = 27,
            MsgTrackingIqDepA = 28,
            MsgUartState = 29,
            MsgAcqSvProfileDep = 30,
            MsgAcqResultDepC = 31,
            MsgTrackingStateDetailedDepA = 33,
            MsgResetFilters = 34,
            MsgInitBaseDep = 35,
            MsgMaskSatellite = 43,
            MsgTrackingIqDepB = 44,
            MsgTrackingIq = 45,
            MsgAcqSvProfile = 46,
            MsgAcqResult = 47,
            MsgTrackingState = 65,
            MsgObsDepB = 67,
            MsgBasePosLlh = 68,
            MsgObsDepA = 69,
            MsgEphemerisDepB = 70,
            MsgEphemerisDepC = 71,
            MsgBasePosEcef = 72,
            MsgObsDepC = 73,
            MsgObs = 74,
            MsgSpecanDep = 80,
            MsgSpecan = 81,
            MsgMeasurementState = 97,
            MsgSetTime = 104,
            MsgAlmanac = 105,
            MsgAlmanacGpsDep = 112,
            MsgAlmanacGloDep = 113,
            MsgAlmanacGps = 114,
            MsgAlmanacGlo = 115,
            MsgGloBiases = 117,
            MsgEphemerisDepD = 128,
            MsgEphemerisGpsDepE = 129,
            MsgEphemerisSbasDepA = 130,
            MsgEphemerisGloDepA = 131,
            MsgEphemerisSbasDepB = 132,
            MsgEphemerisGloDepB = 133,
            MsgEphemerisGpsDepF = 134,
            MsgEphemerisGloDepC = 135,
            MsgEphemerisGloDepD = 136,
            MsgEphemerisBds = 137,
            MsgEphemerisGps = 138,
            MsgEphemerisGlo = 139,
            MsgEphemerisSbas = 140,
            MsgEphemerisGal = 141,
            MsgEphemerisQzss = 142,
            MsgIono = 144,
            MsgSvConfigurationGpsDep = 145,
            MsgGroupDelayDepA = 146,
            MsgGroupDelayDepB = 147,
            MsgGroupDelay = 148,
            MsgEphemerisGalDepA = 149,
            MsgGnssCapb = 150,
            MsgSvAzEl = 151,
            MsgSettingsWrite = 160,
            MsgSettingsSave = 161,
            MsgSettingsReadByIndexReq = 162,
            MsgFileioReadResp = 163,
            MsgSettingsReadReq = 164,
            MsgSettingsReadResp = 165,
            MsgSettingsReadByIndexDone = 166,
            MsgSettingsReadByIndexResp = 167,
            MsgFileioReadReq = 168,
            MsgFileioReadDirReq = 169,
            MsgFileioReadDirResp = 170,
            MsgFileioWriteResp = 171,
            MsgFileioRemove = 172,
            MsgFileioWriteReq = 173,
            MsgSettingsRegister = 174,
            MsgSettingsWriteResp = 175,
            MsgBootloaderHandshakeDepA = 176,
            MsgBootloaderJumpToApp = 177,
            MsgResetDep = 178,
            MsgBootloaderHandshakeReq = 179,
            MsgBootloaderHandshakeResp = 180,
            MsgDeviceMonitor = 181,
            MsgReset = 182,
            MsgCommandReq = 184,
            MsgCommandResp = 185,
            MsgNetworkStateReq = 186,
            MsgNetworkStateResp = 187,
            MsgCommandOutput = 188,
            MsgNetworkBandwidthUsage = 189,
            MsgCellModemStatus = 190,
            MsgFrontEndGain = 191,
            MsgCwResults = 192,
            MsgCwStart = 193,
            MsgNapDeviceDnaResp = 221,
            MsgNapDeviceDnaReq = 222,
            MsgFlashDone = 224,
            MsgFlashReadResp = 225,
            MsgFlashErase = 226,
            MsgStmFlashLockSector = 227,
            MsgStmFlashUnlockSector = 228,
            MsgStmUniqueIdResp = 229,
            MsgFlashProgram = 230,
            MsgFlashReadReq = 231,
            MsgStmUniqueIdReq = 232,
            MsgM25FlashWriteStatus = 243,
            MsgGpsTimeDepA = 256,
            MsgExtEvent = 257,
            MsgGpsTime = 258,
            MsgUtcTime = 259,
            MsgGpsTimeGnss = 260,
            MsgUtcTimeGnss = 261,
            MsgTelSv = 288,
            MsgSettingsRegisterResp = 431,
            MsgPosEcefDepA = 512,
            MsgPosLlhDepA = 513,
            MsgBaselineEcefDepA = 514,
            MsgBaselineNedDepA = 515,
            MsgVelEcefDepA = 516,
            MsgVelNedDepA = 517,
            MsgDopsDepA = 518,
            MsgBaselineHeadingDepA = 519,
            MsgDops = 520,
            MsgPosEcef = 521,
            MsgPosLlh = 522,
            MsgBaselineEcef = 523,
            MsgBaselineNed = 524,
            MsgVelEcef = 525,
            MsgVelNed = 526,
            MsgBaselineHeading = 527,
            MsgAgeCorrections = 528,
            MsgPosLlhCov = 529,
            MsgVelNedCov = 530,
            MsgVelBody = 531,
            MsgPosEcefCov = 532,
            MsgVelEcefCov = 533,
            MsgProtectionLevelDepA = 534,
            MsgProtectionLevel = 535,
            MsgPosLlhAcc = 536,
            MsgVelCog = 540,
            MsgOrientQuat = 544,
            MsgOrientEuler = 545,
            MsgAngularRate = 546,
            MsgPosEcefGnss = 553,
            MsgPosLlhGnss = 554,
            MsgVelEcefGnss = 557,
            MsgVelNedGnss = 558,
            MsgPosLlhCovGnss = 561,
            MsgVelNedCovGnss = 562,
            MsgPosEcefCovGnss = 564,
            MsgVelEcefCovGnss = 565,
            MsgUtcLeapSecond = 570,
            MsgReferenceFrameParam = 580,
            MsgPoseRelative = 581,
            MsgNdbEvent = 1024,
            MsgLog = 1025,
            MsgFwd = 1026,
            MsgSsrOrbitClockDepA = 1500,
            MsgSsrOrbitClock = 1501,
            MsgSsrOrbitClockBounds = 1502,
            MsgSsrOrbitClockBoundsDegradation = 1503,
            MsgSsrCodeBiases = 1505,
            MsgSsrPhaseBiases = 1510,
            MsgSsrStecCorrectionDepA = 1515,
            MsgSsrCodePhaseBiasesBounds = 1516,
            MsgSsrGriddedCorrectionNoStdDepA = 1520,
            MsgSsrGridDefinitionDepA = 1525,
            MsgSsrTileDefinitionDepA = 1526,
            MsgSsrTileDefinitionDepB = 1527,
            MsgSsrTileDefinition = 1528,
            MsgSsrGriddedCorrectionDepA = 1530,
            MsgSsrStecCorrectionDep = 1531,
            MsgSsrGriddedCorrection = 1532,
            MsgSsrStecCorrection = 1533,
            MsgSsrGriddedCorrectionBounds = 1534,
            MsgSsrSatelliteApcDep = 1540,
            MsgSsrSatelliteApc = 1541,
            MsgOsr = 1600,
            MsgUserData = 2048,
            MsgImuRaw = 2304,
            MsgImuAux = 2305,
            MsgMagRaw = 2306,
            MsgOdometry = 2307,
            MsgWheeltick = 2308,
            MsgSsrFlagHighLevel = 3001,
            MsgSsrFlagSatellites = 3005,
            MsgSsrFlagTropoGridPoints = 3011,
            MsgSsrFlagIonoGridPoints = 3015,
            MsgSsrFlagIonoTileSatLos = 3021,
            MsgSsrFlagIonoGridPointSatLos = 3025,
            MsgAcknowledge = 3026,
            MsgEd25519SignatureDepA = 3073,
            MsgEd25519CertificateDep = 3074,
            MsgEd25519SignatureDepB = 3075,
            MsgEcdsaCertificate = 3076,
            MsgCertificateChain = 3077,
            MsgEcdsaSignature = 3078,
            MsgFileioConfigReq = 4097,
            MsgFileioConfigResp = 4098,
            MsgSbasRaw = 30583,
            MsgLinuxCpuStateDepA = 32512,
            MsgLinuxMemStateDepA = 32513,
            MsgLinuxSysStateDepA = 32514,
            MsgLinuxProcessSocketCounts = 32515,
            MsgLinuxProcessSocketQueues = 32516,
            MsgLinuxSocketUsage = 32517,
            MsgLinuxProcessFdCount = 32518,
            MsgLinuxProcessFdSummary = 32519,
            MsgLinuxCpuState = 32520,
            MsgLinuxMemState = 32521,
            MsgLinuxSysState = 32522,
            MsgStartup = 65280,
            MsgDgnssStatus = 65282,
            MsgInsStatus = 65283,
            MsgCsacTelemetry = 65284,
            MsgCsacTelemetryLabels = 65285,
            MsgInsUpdates = 65286,
            MsgGnssTimeOffset = 65287,
            MsgPpsTime = 65288,
            MsgSensorAidEvent = 65289,
            MsgGroupMeta = 65290,
            MsgSolnMeta = 65294,
            MsgSolnMetaDepA = 65295,
            MsgStatusJournal = 65533,
            MsgStatusReport = 65534,
            MsgHeartbeat = 65535,
        }
        public Sbp(KaitaiStream p__io, KaitaiStruct p__parent = null, Sbp p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
            _message = new List<Message>();
            {
                var i = 0;
                while (!m_io.IsEof) {
                    _message.Add(new Message(m_io, this, m_root));
                    i++;
                }
            }
        }
        public partial class Message : KaitaiStruct
        {
            public static Message FromFile(string fileName)
            {
                return new Message(new KaitaiStream(fileName));
            }

            public Message(KaitaiStream p__io, Sbp p__parent = null, Sbp p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new SbpHeader(m_io, this, m_root);
                switch (Header.MsgType) {
                case Sbp.MsgIds.MsgBaselineEcef: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgBaselineEcef(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisBds: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisBds(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisGloDepD: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGloDepD(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSettingsReadByIndexReq: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsReadByIndexReq(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrFlagHighLevel: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Integrity.MsgSsrFlagHighLevel(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFileioConfigReq: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioConfigReq(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgOdometry: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Vehicle.MsgOdometry(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrStecCorrectionDep: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrStecCorrectionDep(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEd25519SignatureDepB: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Signing.MsgEd25519SignatureDepB(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgStmUniqueIdReq: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgStmUniqueIdReq(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFrontEndGain: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgFrontEndGain(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgBasePosLlh: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgBasePosLlh(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrOrbitClock: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrOrbitClock(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgReset: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgReset(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgStmFlashLockSector: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgStmFlashLockSector(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgLinuxProcessFdSummary: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxProcessFdSummary(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgStatusJournal: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgStatusJournal(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgCsacTelemetry: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgCsacTelemetry(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgAgeCorrections: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgAgeCorrections(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgOrientEuler: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Orientation.MsgOrientEuler(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrSatelliteApcDep: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrSatelliteApcDep(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgBaselineNed: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgBaselineNed(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgVelEcefGnss: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelEcefGnss(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgMeasurementState: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgMeasurementState(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgIono: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgIono(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgBasePosEcef: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgBasePosEcef(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFlashProgram: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgFlashProgram(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgAcqResult: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Acquisition.MsgAcqResult(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgPpsTime: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgPpsTime(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgObs: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgObs(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisSbasDepB: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisSbasDepB(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgTrackingIq: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingIq(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrFlagIonoTileSatLos: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Integrity.MsgSsrFlagIonoTileSatLos(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgTrackingStateDetailedDep: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingStateDetailedDep(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgBootloaderHandshakeDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Bootload.MsgBootloaderHandshakeDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgUtcLeapSecond: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgUtcLeapSecond(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrGriddedCorrectionNoStdDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrGriddedCorrectionNoStdDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgBootloaderHandshakeResp: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Bootload.MsgBootloaderHandshakeResp(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgBaselineHeading: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Orientation.MsgBaselineHeading(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgStatusReport: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgStatusReport(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgVelNedCov: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelNedCov(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSetTime: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgSetTime(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgLinuxCpuState: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxCpuState(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgGpsTimeDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgGpsTimeDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisSbasDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisSbasDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgAcqResultDepB: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Acquisition.MsgAcqResultDepB(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSettingsRegisterResp: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsRegisterResp(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisGal: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGal(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgBootloaderJumpToApp: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Bootload.MsgBootloaderJumpToApp(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrPhaseBiases: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrPhaseBiases(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFileioReadDirResp: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioReadDirResp(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgPosEcefGnss: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosEcefGnss(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgAlmanacGloDep: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgAlmanacGloDep(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgVelEcefDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelEcefDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgThreadState: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgThreadState(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgGpsTime: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgGpsTime(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrCodePhaseBiasesBounds: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrCodePhaseBiasesBounds(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSettingsWriteResp: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsWriteResp(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgTrackingState: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingState(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgVelEcef: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelEcef(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisGloDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGloDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEd25519CertificateDep: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Signing.MsgEd25519CertificateDep(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgBaselineNedDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgBaselineNedDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSpecanDep: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgSpecanDep(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisSbas: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisSbas(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgGroupDelay: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgGroupDelay(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgPosEcef: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosEcef(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgAlmanac: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgAlmanac(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSettingsReadReq: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsReadReq(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrFlagTropoGridPoints: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Integrity.MsgSsrFlagTropoGridPoints(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrGriddedCorrectionBounds: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrGriddedCorrectionBounds(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgStmUniqueIdResp: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgStmUniqueIdResp(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgTelSv: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Telemetry.MsgTelSv(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrFlagSatellites: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Integrity.MsgSsrFlagSatellites(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgImuAux: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Imu.MsgImuAux(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrGridDefinitionDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrGridDefinitionDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgPosLlhAcc: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosLlhAcc(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSvConfigurationGpsDep: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgSvConfigurationGpsDep(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgLinuxMemState: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxMemState(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgLinuxSysState: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxSysState(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSettingsReadByIndexDone: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsReadByIndexDone(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgResetFilters: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgResetFilters(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEcdsaSignature: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Signing.MsgEcdsaSignature(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisGpsDepE: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGpsDepE(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgM25FlashWriteStatus: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgM25FlashWriteStatus(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisGps: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGps(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgCommandOutput: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgCommandOutput(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrFlagIonoGridPoints: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Integrity.MsgSsrFlagIonoGridPoints(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgVelNedCovGnss: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelNedCovGnss(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgNetworkStateResp: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgNetworkStateResp(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrStecCorrectionDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrStecCorrectionDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgCommandReq: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgCommandReq(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgAcknowledge: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Integrity.MsgAcknowledge(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgTrackingIqDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingIqDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisGalDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGalDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSpecan: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgSpecan(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgAcqSvProfileDep: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Acquisition.MsgAcqSvProfileDep(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgUtcTime: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgUtcTime(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisDepD: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisDepD(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgLinuxProcessSocketQueues: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxProcessSocketQueues(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgUtcTimeGnss: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgUtcTimeGnss(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgNdbEvent: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ndb.MsgNdbEvent(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgBootloaderHandshakeReq: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Bootload.MsgBootloaderHandshakeReq(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgUserData: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new User.MsgUserData(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSensorAidEvent: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgSensorAidEvent(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrOrbitClockBounds: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrOrbitClockBounds(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgPosLlhGnss: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosLlhGnss(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgInitBaseDep: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgInitBaseDep(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFileioReadReq: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioReadReq(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgTrackingIqDepB: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingIqDepB(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgAcqResultDepC: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Acquisition.MsgAcqResultDepC(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgCommandResp: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgCommandResp(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFileioRemove: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioRemove(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgObsDepC: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgObsDepC(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrTileDefinitionDepB: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrTileDefinitionDepB(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgCsacTelemetryLabels: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgCsacTelemetryLabels(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgVelNed: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelNed(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSettingsReadByIndexResp: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsReadByIndexResp(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisQzss: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisQzss(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrStecCorrection: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrStecCorrection(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgBaselineEcefDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgBaselineEcefDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgInsUpdates: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgInsUpdates(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgPosEcefCov: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosEcefCov(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgVelNedGnss: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelNedGnss(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgMaskSatellite: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgMaskSatellite(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgGroupDelayDepB: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgGroupDelayDepB(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrOrbitClockBoundsDegradation: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrOrbitClockBoundsDegradation(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFlashErase: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgFlashErase(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgCwStart: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgCwStart(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrOrbitClockDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrOrbitClockDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgDops: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgDops(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgNetworkBandwidthUsage: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgNetworkBandwidthUsage(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEcdsaCertificate: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Signing.MsgEcdsaCertificate(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgPosLlhDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosLlhDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSvAzEl: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgSvAzEl(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFileioReadDirReq: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioReadDirReq(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisDepB: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisDepB(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgVelEcefCov: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelEcefCov(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgDgnssStatus: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgDgnssStatus(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrTileDefinitionDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrTileDefinitionDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgLog: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Logging.MsgLog(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgMaskSatelliteDep: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgMaskSatelliteDep(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgExtEvent: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new ExtEvents.MsgExtEvent(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgCellModemStatus: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgCellModemStatus(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgOrientQuat: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Orientation.MsgOrientQuat(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgHeartbeat: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgHeartbeat(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgAlmanacGpsDep: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgAlmanacGpsDep(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgNapDeviceDnaReq: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Bootload.MsgNapDeviceDnaReq(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgAlmanacGps: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgAlmanacGps(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgVelEcefCovGnss: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelEcefCovGnss(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEd25519SignatureDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Signing.MsgEd25519SignatureDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgAngularRate: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Orientation.MsgAngularRate(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgVelBody: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelBody(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgCertificateChain: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Signing.MsgCertificateChain(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSolnMetaDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new SolutionMeta.MsgSolnMetaDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrGriddedCorrectionDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrGriddedCorrectionDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisGloDepC: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGloDepC(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgLinuxProcessFdCount: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxProcessFdCount(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFileioReadResp: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioReadResp(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgLinuxSysStateDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxSysStateDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSbasRaw: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Sbas.MsgSbasRaw(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgPosEcefCovGnss: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosEcefCovGnss(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrFlagIonoGridPointSatLos: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Integrity.MsgSsrFlagIonoGridPointSatLos(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFileioWriteReq: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioWriteReq(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgAcqSvProfile: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Acquisition.MsgAcqSvProfile(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisGloDepB: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGloDepB(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgLinuxSocketUsage: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxSocketUsage(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgNetworkStateReq: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgNetworkStateReq(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgProtectionLevelDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgProtectionLevelDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgImuRaw: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Imu.MsgImuRaw(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgResetDep: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgResetDep(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgMagRaw: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Mag.MsgMagRaw(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgStartup: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgStartup(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgGloBiases: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgGloBiases(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgTrackingStateDetailedDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingStateDetailedDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgPosLlhCovGnss: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosLlhCovGnss(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSettingsWrite: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsWrite(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSettingsSave: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsSave(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgAlmanacGlo: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgAlmanacGlo(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgStmFlashUnlockSector: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgStmFlashUnlockSector(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgGpsTimeGnss: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgGpsTimeGnss(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFlashReadReq: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgFlashReadReq(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisGlo: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGlo(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgBaselineHeadingDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgBaselineHeadingDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSettingsRegister: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsRegister(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgGnssCapb: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgGnssCapb(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgTrackingStateDepB: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingStateDepB(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFwd: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Logging.MsgFwd(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSolnMeta: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new SolutionMeta.MsgSolnMeta(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgObsDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgObsDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgDeviceMonitor: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgDeviceMonitor(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgLinuxProcessSocketCounts: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxProcessSocketCounts(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgVelCog: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelCog(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgPrintDep: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Logging.MsgPrintDep(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgCwResults: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgCwResults(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgNapDeviceDnaResp: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Bootload.MsgNapDeviceDnaResp(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgDopsDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgDopsDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgPosEcefDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosEcefDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSettingsReadResp: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsReadResp(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgLinuxMemStateDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxMemStateDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisDepC: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisDepC(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFileioWriteResp: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioWriteResp(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgWheeltick: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Vehicle.MsgWheeltick(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgUartStateDepa: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgUartStateDepa(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgReferenceFrameParam: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgReferenceFrameParam(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgPoseRelative: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPoseRelative(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgIarState: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgIarState(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgUartState: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgUartState(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrTileDefinition: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrTileDefinition(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrSatelliteApc: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrSatelliteApc(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgOsr: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgOsr(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgPosLlhCov: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosLlhCov(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgGroupDelayDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgGroupDelayDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgProtectionLevel: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgProtectionLevel(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgObsDepB: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgObsDepB(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgPosLlh: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosLlh(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFlashDone: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgFlashDone(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgAcqResultDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Acquisition.MsgAcqResultDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrCodeBiases: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrCodeBiases(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgSsrGriddedCorrection: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrGriddedCorrection(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgGroupMeta: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgGroupMeta(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFileioConfigResp: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioConfigResp(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgVelNedDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelNedDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgGnssTimeOffset: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgGnssTimeOffset(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgTrackingStateDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingStateDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgInsStatus: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgInsStatus(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgEphemerisGpsDepF: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGpsDepF(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgLinuxCpuStateDepA: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxCpuStateDepA(io___raw_payload, this, m_root);
                    break;
                }
                case Sbp.MsgIds.MsgFlashReadResp: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgFlashReadResp(io___raw_payload, this, m_root);
                    break;
                }
                default: {
                    _payload = m_io.ReadBytes(Header.Length);
                    break;
                }
                }
                _crc = m_io.ReadU2le();
            }
            private SbpHeader _header;
            private object _payload;
            private ushort _crc;
            private Sbp m_root;
            private Sbp m_parent;
            private byte[] __raw_payload;
            public SbpHeader Header { get { return _header; } }
            public object Payload { get { return _payload; } }
            public ushort Crc { get { return _crc; } }
            public Sbp M_Root { get { return m_root; } }
            public Sbp M_Parent { get { return m_parent; } }
            public byte[] M_RawPayload { get { return __raw_payload; } }
        }
        public partial class SbpHeader : KaitaiStruct
        {
            public static SbpHeader FromFile(string fileName)
            {
                return new SbpHeader(new KaitaiStream(fileName));
            }

            public SbpHeader(KaitaiStream p__io, Sbp.Message p__parent = null, Sbp p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _preamble = m_io.ReadBytes(1);
                if (!((KaitaiStream.ByteArrayCompare(Preamble, new byte[] { 85 }) == 0)))
                {
                    throw new ValidationNotEqualError(new byte[] { 85 }, Preamble, M_Io, "/types/sbp_header/seq/0");
                }
                _msgType = ((Sbp.MsgIds) m_io.ReadU2le());
                _sender = m_io.ReadU2le();
                _length = m_io.ReadU1();
            }
            private byte[] _preamble;
            private MsgIds _msgType;
            private ushort _sender;
            private byte _length;
            private Sbp m_root;
            private Sbp.Message m_parent;
            public byte[] Preamble { get { return _preamble; } }
            public MsgIds MsgType { get { return _msgType; } }
            public ushort Sender { get { return _sender; } }
            public byte Length { get { return _length; } }
            public Sbp M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        private List<Message> _message;
        private Sbp m_root;
        private KaitaiStruct m_parent;
        public List<Message> Message { get { return _message; } }
        public Sbp M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
