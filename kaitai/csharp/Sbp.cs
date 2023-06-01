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
            MsgCertificateChainDep = 3077,
            MsgEcdsaSignatureDepA = 3078,
            MsgEcdsaSignatureDepB = 3079,
            MsgEcdsaSignature = 3080,
            MsgCertificateChain = 3081,
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
                case 525: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelEcef(io___raw_payload, this, m_root);
                    break;
                }
                case 141: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGal(io___raw_payload, this, m_root);
                    break;
                }
                case 243: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgM25FlashWriteStatus(io___raw_payload, this, m_root);
                    break;
                }
                case 2048: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new User.MsgUserData(io___raw_payload, this, m_root);
                    break;
                }
                case 3079: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Signing.MsgEcdsaSignatureDepB(io___raw_payload, this, m_root);
                    break;
                }
                case 184: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgCommandReq(io___raw_payload, this, m_root);
                    break;
                }
                case 105: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgAlmanac(io___raw_payload, this, m_root);
                    break;
                }
                case 142: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisQzss(io___raw_payload, this, m_root);
                    break;
                }
                case 112: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgAlmanacGpsDep(io___raw_payload, this, m_root);
                    break;
                }
                case 177: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Bootload.MsgBootloaderJumpToApp(io___raw_payload, this, m_root);
                    break;
                }
                case 163: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioReadResp(io___raw_payload, this, m_root);
                    break;
                }
                case 257: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new ExtEvents.MsgExtEvent(io___raw_payload, this, m_root);
                    break;
                }
                case 4097: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioConfigReq(io___raw_payload, this, m_root);
                    break;
                }
                case 17: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingStateDetailedDep(io___raw_payload, this, m_root);
                    break;
                }
                case 260: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgGpsTimeGnss(io___raw_payload, this, m_root);
                    break;
                }
                case 1525: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrGridDefinitionDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 131: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGloDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 167: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsReadByIndexResp(io___raw_payload, this, m_root);
                    break;
                }
                case 146: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgGroupDelayDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 47: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Acquisition.MsgAcqResult(io___raw_payload, this, m_root);
                    break;
                }
                case 136: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGloDepD(io___raw_payload, this, m_root);
                    break;
                }
                case 73: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgObsDepC(io___raw_payload, this, m_root);
                    break;
                }
                case 65283: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgInsStatus(io___raw_payload, this, m_root);
                    break;
                }
                case 32513: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxMemStateDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 545: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Orientation.MsgOrientEuler(io___raw_payload, this, m_root);
                    break;
                }
                case 65534: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgStatusReport(io___raw_payload, this, m_root);
                    break;
                }
                case 533: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelEcefCov(io___raw_payload, this, m_root);
                    break;
                }
                case 513: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosLlhDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 46: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Acquisition.MsgAcqSvProfile(io___raw_payload, this, m_root);
                    break;
                }
                case 81: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgSpecan(io___raw_payload, this, m_root);
                    break;
                }
                case 169: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioReadDirReq(io___raw_payload, this, m_root);
                    break;
                }
                case 162: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsReadByIndexReq(io___raw_payload, this, m_root);
                    break;
                }
                case 546: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Orientation.MsgAngularRate(io___raw_payload, this, m_root);
                    break;
                }
                case 531: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelBody(io___raw_payload, this, m_root);
                    break;
                }
                case 224: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgFlashDone(io___raw_payload, this, m_root);
                    break;
                }
                case 24: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgUartStateDepa(io___raw_payload, this, m_root);
                    break;
                }
                case 230: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgFlashProgram(io___raw_payload, this, m_root);
                    break;
                }
                case 65285: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgCsacTelemetryLabels(io___raw_payload, this, m_root);
                    break;
                }
                case 35: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgInitBaseDep(io___raw_payload, this, m_root);
                    break;
                }
                case 1528: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrTileDefinition(io___raw_payload, this, m_root);
                    break;
                }
                case 519: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgBaselineHeadingDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 20: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Acquisition.MsgAcqResultDepB(io___raw_payload, this, m_root);
                    break;
                }
                case 570: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgUtcLeapSecond(io___raw_payload, this, m_root);
                    break;
                }
                case 32520: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxCpuState(io___raw_payload, this, m_root);
                    break;
                }
                case 1505: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrCodeBiases(io___raw_payload, this, m_root);
                    break;
                }
                case 113: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgAlmanacGloDep(io___raw_payload, this, m_root);
                    break;
                }
                case 1515: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrStecCorrectionDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 558: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelNedGnss(io___raw_payload, this, m_root);
                    break;
                }
                case 530: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelNedCov(io___raw_payload, this, m_root);
                    break;
                }
                case 288: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Telemetry.MsgTelSv(io___raw_payload, this, m_root);
                    break;
                }
                case 1026: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Logging.MsgFwd(io___raw_payload, this, m_root);
                    break;
                }
                case 65286: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgInsUpdates(io___raw_payload, this, m_root);
                    break;
                }
                case 65284: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgCsacTelemetry(io___raw_payload, this, m_root);
                    break;
                }
                case 191: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgFrontEndGain(io___raw_payload, this, m_root);
                    break;
                }
                case 520: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgDops(io___raw_payload, this, m_root);
                    break;
                }
                case 27: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgMaskSatelliteDep(io___raw_payload, this, m_root);
                    break;
                }
                case 1516: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrCodePhaseBiasesBounds(io___raw_payload, this, m_root);
                    break;
                }
                case 150: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgGnssCapb(io___raw_payload, this, m_root);
                    break;
                }
                case 97: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgMeasurementState(io___raw_payload, this, m_root);
                    break;
                }
                case 529: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosLlhCov(io___raw_payload, this, m_root);
                    break;
                }
                case 431: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsRegisterResp(io___raw_payload, this, m_root);
                    break;
                }
                case 65533: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgStatusJournal(io___raw_payload, this, m_root);
                    break;
                }
                case 145: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgSvConfigurationGpsDep(io___raw_payload, this, m_root);
                    break;
                }
                case 32522: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxSysState(io___raw_payload, this, m_root);
                    break;
                }
                case 3076: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Signing.MsgEcdsaCertificate(io___raw_payload, this, m_root);
                    break;
                }
                case 144: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgIono(io___raw_payload, this, m_root);
                    break;
                }
                case 65294: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new SolutionMeta.MsgSolnMeta(io___raw_payload, this, m_root);
                    break;
                }
                case 532: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosEcefCov(io___raw_payload, this, m_root);
                    break;
                }
                case 45: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingIq(io___raw_payload, this, m_root);
                    break;
                }
                case 561: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosLlhCovGnss(io___raw_payload, this, m_root);
                    break;
                }
                case 1502: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrOrbitClockBounds(io___raw_payload, this, m_root);
                    break;
                }
                case 149: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGalDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 115: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgAlmanacGlo(io___raw_payload, this, m_root);
                    break;
                }
                case 32512: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxCpuStateDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 32521: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxMemState(io___raw_payload, this, m_root);
                    break;
                }
                case 522: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosLlh(io___raw_payload, this, m_root);
                    break;
                }
                case 104: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgSetTime(io___raw_payload, this, m_root);
                    break;
                }
                case 32519: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxProcessFdSummary(io___raw_payload, this, m_root);
                    break;
                }
                case 4098: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioConfigResp(io___raw_payload, this, m_root);
                    break;
                }
                case 32517: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxSocketUsage(io___raw_payload, this, m_root);
                    break;
                }
                case 2306: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Mag.MsgMagRaw(io___raw_payload, this, m_root);
                    break;
                }
                case 67: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgObsDepB(io___raw_payload, this, m_root);
                    break;
                }
                case 69: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgObsDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 512: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosEcefDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 137: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisBds(io___raw_payload, this, m_root);
                    break;
                }
                case 65288: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgPpsTime(io___raw_payload, this, m_root);
                    break;
                }
                case 3074: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Signing.MsgEd25519CertificateDep(io___raw_payload, this, m_root);
                    break;
                }
                case 562: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelNedCovGnss(io___raw_payload, this, m_root);
                    break;
                }
                case 580: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgReferenceFrameParam(io___raw_payload, this, m_root);
                    break;
                }
                case 524: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgBaselineNed(io___raw_payload, this, m_root);
                    break;
                }
                case 161: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsSave(io___raw_payload, this, m_root);
                    break;
                }
                case 138: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGps(io___raw_payload, this, m_root);
                    break;
                }
                case 544: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Orientation.MsgOrientQuat(io___raw_payload, this, m_root);
                    break;
                }
                case 192: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgCwResults(io___raw_payload, this, m_root);
                    break;
                }
                case 165: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsReadResp(io___raw_payload, this, m_root);
                    break;
                }
                case 33: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingStateDetailedDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 1527: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrTileDefinitionDepB(io___raw_payload, this, m_root);
                    break;
                }
                case 65535: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgHeartbeat(io___raw_payload, this, m_root);
                    break;
                }
                case 3081: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Signing.MsgCertificateChain(io___raw_payload, this, m_root);
                    break;
                }
                case 514: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgBaselineEcefDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 185: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgCommandResp(io___raw_payload, this, m_root);
                    break;
                }
                case 180: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Bootload.MsgBootloaderHandshakeResp(io___raw_payload, this, m_root);
                    break;
                }
                case 19: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingStateDepB(io___raw_payload, this, m_root);
                    break;
                }
                case 3015: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Integrity.MsgSsrFlagIonoGridPoints(io___raw_payload, this, m_root);
                    break;
                }
                case 186: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgNetworkStateReq(io___raw_payload, this, m_root);
                    break;
                }
                case 32518: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxProcessFdCount(io___raw_payload, this, m_root);
                    break;
                }
                case 1530: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrGriddedCorrectionDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 1541: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrSatelliteApc(io___raw_payload, this, m_root);
                    break;
                }
                case 30583: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Sbas.MsgSbasRaw(io___raw_payload, this, m_root);
                    break;
                }
                case 23: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgThreadState(io___raw_payload, this, m_root);
                    break;
                }
                case 221: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Bootload.MsgNapDeviceDnaResp(io___raw_payload, this, m_root);
                    break;
                }
                case 227: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgStmFlashLockSector(io___raw_payload, this, m_root);
                    break;
                }
                case 188: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgCommandOutput(io___raw_payload, this, m_root);
                    break;
                }
                case 65282: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgDgnssStatus(io___raw_payload, this, m_root);
                    break;
                }
                case 178: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgResetDep(io___raw_payload, this, m_root);
                    break;
                }
                case 1533: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrStecCorrection(io___raw_payload, this, m_root);
                    break;
                }
                case 3011: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Integrity.MsgSsrFlagTropoGridPoints(io___raw_payload, this, m_root);
                    break;
                }
                case 3005: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Integrity.MsgSsrFlagSatellites(io___raw_payload, this, m_root);
                    break;
                }
                case 160: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsWrite(io___raw_payload, this, m_root);
                    break;
                }
                case 540: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelCog(io___raw_payload, this, m_root);
                    break;
                }
                case 174: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsRegister(io___raw_payload, this, m_root);
                    break;
                }
                case 176: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Bootload.MsgBootloaderHandshakeDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 1024: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ndb.MsgNdbEvent(io___raw_payload, this, m_root);
                    break;
                }
                case 166: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsReadByIndexDone(io___raw_payload, this, m_root);
                    break;
                }
                case 114: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgAlmanacGps(io___raw_payload, this, m_root);
                    break;
                }
                case 564: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosEcefCovGnss(io___raw_payload, this, m_root);
                    break;
                }
                case 259: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgUtcTime(io___raw_payload, this, m_root);
                    break;
                }
                case 181: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgDeviceMonitor(io___raw_payload, this, m_root);
                    break;
                }
                case 521: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosEcef(io___raw_payload, this, m_root);
                    break;
                }
                case 2307: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Vehicle.MsgOdometry(io___raw_payload, this, m_root);
                    break;
                }
                case 148: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgGroupDelay(io___raw_payload, this, m_root);
                    break;
                }
                case 117: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgGloBiases(io___raw_payload, this, m_root);
                    break;
                }
                case 3025: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Integrity.MsgSsrFlagIonoGridPointSatLos(io___raw_payload, this, m_root);
                    break;
                }
                case 65: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingState(io___raw_payload, this, m_root);
                    break;
                }
                case 1534: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrGriddedCorrectionBounds(io___raw_payload, this, m_root);
                    break;
                }
                case 44: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingIqDepB(io___raw_payload, this, m_root);
                    break;
                }
                case 3073: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Signing.MsgEd25519SignatureDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 231: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgFlashReadReq(io___raw_payload, this, m_root);
                    break;
                }
                case 140: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisSbas(io___raw_payload, this, m_root);
                    break;
                }
                case 226: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgFlashErase(io___raw_payload, this, m_root);
                    break;
                }
                case 515: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgBaselineNedDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 2308: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Vehicle.MsgWheeltick(io___raw_payload, this, m_root);
                    break;
                }
                case 535: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgProtectionLevel(io___raw_payload, this, m_root);
                    break;
                }
                case 179: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Bootload.MsgBootloaderHandshakeReq(io___raw_payload, this, m_root);
                    break;
                }
                case 172: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioRemove(io___raw_payload, this, m_root);
                    break;
                }
                case 130: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisSbasDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 187: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgNetworkStateResp(io___raw_payload, this, m_root);
                    break;
                }
                case 1501: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrOrbitClock(io___raw_payload, this, m_root);
                    break;
                }
                case 21: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Acquisition.MsgAcqResultDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 1500: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrOrbitClockDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 225: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgFlashReadResp(io___raw_payload, this, m_root);
                    break;
                }
                case 534: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgProtectionLevelDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 232: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgStmUniqueIdReq(io___raw_payload, this, m_root);
                    break;
                }
                case 2304: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Imu.MsgImuRaw(io___raw_payload, this, m_root);
                    break;
                }
                case 229: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgStmUniqueIdResp(io___raw_payload, this, m_root);
                    break;
                }
                case 32515: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxProcessSocketCounts(io___raw_payload, this, m_root);
                    break;
                }
                case 65295: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new SolutionMeta.MsgSolnMetaDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 3075: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Signing.MsgEd25519SignatureDepB(io___raw_payload, this, m_root);
                    break;
                }
                case 258: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgGpsTime(io___raw_payload, this, m_root);
                    break;
                }
                case 32516: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxProcessSocketQueues(io___raw_payload, this, m_root);
                    break;
                }
                case 170: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioReadDirResp(io___raw_payload, this, m_root);
                    break;
                }
                case 256: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgGpsTimeDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 32514: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Linux.MsgLinuxSysStateDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 518: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgDopsDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 553: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosEcefGnss(io___raw_payload, this, m_root);
                    break;
                }
                case 517: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelNedDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 164: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsReadReq(io___raw_payload, this, m_root);
                    break;
                }
                case 182: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgReset(io___raw_payload, this, m_root);
                    break;
                }
                case 189: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgNetworkBandwidthUsage(io___raw_payload, this, m_root);
                    break;
                }
                case 72: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgBasePosEcef(io___raw_payload, this, m_root);
                    break;
                }
                case 71: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisDepC(io___raw_payload, this, m_root);
                    break;
                }
                case 1025: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Logging.MsgLog(io___raw_payload, this, m_root);
                    break;
                }
                case 168: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioReadReq(io___raw_payload, this, m_root);
                    break;
                }
                case 581: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPoseRelative(io___raw_payload, this, m_root);
                    break;
                }
                case 171: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioWriteResp(io___raw_payload, this, m_root);
                    break;
                }
                case 70: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisDepB(io___raw_payload, this, m_root);
                    break;
                }
                case 28: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingIqDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 193: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgCwStart(io___raw_payload, this, m_root);
                    break;
                }
                case 133: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGloDepB(io___raw_payload, this, m_root);
                    break;
                }
                case 129: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGpsDepE(io___raw_payload, this, m_root);
                    break;
                }
                case 74: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgObs(io___raw_payload, this, m_root);
                    break;
                }
                case 3080: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Signing.MsgEcdsaSignature(io___raw_payload, this, m_root);
                    break;
                }
                case 151: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgSvAzEl(io___raw_payload, this, m_root);
                    break;
                }
                case 16: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Logging.MsgPrintDep(io___raw_payload, this, m_root);
                    break;
                }
                case 147: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgGroupDelayDepB(io___raw_payload, this, m_root);
                    break;
                }
                case 527: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Orientation.MsgBaselineHeading(io___raw_payload, this, m_root);
                    break;
                }
                case 134: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGpsDepF(io___raw_payload, this, m_root);
                    break;
                }
                case 3078: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Signing.MsgEcdsaSignatureDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 80: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgSpecanDep(io___raw_payload, this, m_root);
                    break;
                }
                case 68: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgBasePosLlh(io___raw_payload, this, m_root);
                    break;
                }
                case 1532: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrGriddedCorrection(io___raw_payload, this, m_root);
                    break;
                }
                case 1503: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrOrbitClockBoundsDegradation(io___raw_payload, this, m_root);
                    break;
                }
                case 516: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelEcefDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 26: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 139: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGlo(io___raw_payload, this, m_root);
                    break;
                }
                case 65280: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgStartup(io___raw_payload, this, m_root);
                    break;
                }
                case 31: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Acquisition.MsgAcqResultDepC(io___raw_payload, this, m_root);
                    break;
                }
                case 565: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelEcefCovGnss(io___raw_payload, this, m_root);
                    break;
                }
                case 135: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisGloDepC(io___raw_payload, this, m_root);
                    break;
                }
                case 3026: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Integrity.MsgAcknowledge(io___raw_payload, this, m_root);
                    break;
                }
                case 34: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgResetFilters(io___raw_payload, this, m_root);
                    break;
                }
                case 1600: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgOsr(io___raw_payload, this, m_root);
                    break;
                }
                case 536: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosLlhAcc(io___raw_payload, this, m_root);
                    break;
                }
                case 65287: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgGnssTimeOffset(io___raw_payload, this, m_root);
                    break;
                }
                case 1526: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrTileDefinitionDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 1540: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrSatelliteApcDep(io___raw_payload, this, m_root);
                    break;
                }
                case 29: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgUartState(io___raw_payload, this, m_root);
                    break;
                }
                case 132: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisSbasDepB(io___raw_payload, this, m_root);
                    break;
                }
                case 1510: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrPhaseBiases(io___raw_payload, this, m_root);
                    break;
                }
                case 65290: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgGroupMeta(io___raw_payload, this, m_root);
                    break;
                }
                case 175: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Settings.MsgSettingsWriteResp(io___raw_payload, this, m_root);
                    break;
                }
                case 557: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelEcefGnss(io___raw_payload, this, m_root);
                    break;
                }
                case 526: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgVelNed(io___raw_payload, this, m_root);
                    break;
                }
                case 1520: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrGriddedCorrectionNoStdDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 2305: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Imu.MsgImuAux(io___raw_payload, this, m_root);
                    break;
                }
                case 190: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgCellModemStatus(io___raw_payload, this, m_root);
                    break;
                }
                case 1531: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Ssr.MsgSsrStecCorrectionDep(io___raw_payload, this, m_root);
                    break;
                }
                case 528: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgAgeCorrections(io___raw_payload, this, m_root);
                    break;
                }
                case 3077: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Signing.MsgCertificateChainDep(io___raw_payload, this, m_root);
                    break;
                }
                case 25: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgIarState(io___raw_payload, this, m_root);
                    break;
                }
                case 43: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Piksi.MsgMaskSatellite(io___raw_payload, this, m_root);
                    break;
                }
                case 228: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Flash.MsgStmFlashUnlockSector(io___raw_payload, this, m_root);
                    break;
                }
                case 523: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgBaselineEcef(io___raw_payload, this, m_root);
                    break;
                }
                case 554: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgPosLlhGnss(io___raw_payload, this, m_root);
                    break;
                }
                case 65289: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new System.MsgSensorAidEvent(io___raw_payload, this, m_root);
                    break;
                }
                case 22: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Tracking.MsgTrackingStateDepA(io___raw_payload, this, m_root);
                    break;
                }
                case 3001: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Integrity.MsgSsrFlagHighLevel(io___raw_payload, this, m_root);
                    break;
                }
                case 30: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Acquisition.MsgAcqSvProfileDep(io___raw_payload, this, m_root);
                    break;
                }
                case 261: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Navigation.MsgUtcTimeGnss(io___raw_payload, this, m_root);
                    break;
                }
                case 3021: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Integrity.MsgSsrFlagIonoTileSatLos(io___raw_payload, this, m_root);
                    break;
                }
                case 173: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new FileIo.MsgFileioWriteReq(io___raw_payload, this, m_root);
                    break;
                }
                case 128: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Observation.MsgEphemerisDepD(io___raw_payload, this, m_root);
                    break;
                }
                case 222: {
                    __raw_payload = m_io.ReadBytes(Header.Length);
                    var io___raw_payload = new KaitaiStream(__raw_payload);
                    _payload = new Bootload.MsgNapDeviceDnaReq(io___raw_payload, this, m_root);
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
                _msgType = m_io.ReadU2le();
                _sender = m_io.ReadU2le();
                _length = m_io.ReadU1();
            }
            private byte[] _preamble;
            private ushort _msgType;
            private ushort _sender;
            private byte _length;
            private Sbp m_root;
            private Sbp.Message m_parent;
            public byte[] Preamble { get { return _preamble; } }
            public ushort MsgType { get { return _msgType; } }
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
