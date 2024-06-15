# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Automatically generated with generate.py.  Do not hand edit!

from .sbp import Sbp

from .acquisition import *
from .bootload import *
from .ext_events import *
from .file_io import *
from .flash import *
from .gnss import *
from .imu import *
from .integrity import *
from .linux import *
from .logging import *
from .mag import *
from .navigation import *
from .ndb import *
from .observation import *
from .orientation import *
from .piksi import *
from .profiling import *
from .sbas import *
from .settings import *
from .signing import *
from .solution_meta import *
from .ssr import *
from .system import *
from .telemetry import *
from .tracking import *
from .user import *
from .vehicle import *

TABLE = {

  
    47: Acquisition.MsgAcqResult,
    31: Acquisition.MsgAcqResultDepC,
    20: Acquisition.MsgAcqResultDepB,
    21: Acquisition.MsgAcqResultDepA,
    46: Acquisition.MsgAcqSvProfile,
    30: Acquisition.MsgAcqSvProfileDep,
  
    179: Bootload.MsgBootloaderHandshakeReq,
    180: Bootload.MsgBootloaderHandshakeResp,
    177: Bootload.MsgBootloaderJumpToApp,
    222: Bootload.MsgNapDeviceDnaReq,
    221: Bootload.MsgNapDeviceDnaResp,
    176: Bootload.MsgBootloaderHandshakeDepA,
  
    257: ExtEvents.MsgExtEvent,
  
    168: FileIo.MsgFileioReadReq,
    163: FileIo.MsgFileioReadResp,
    169: FileIo.MsgFileioReadDirReq,
    170: FileIo.MsgFileioReadDirResp,
    172: FileIo.MsgFileioRemove,
    173: FileIo.MsgFileioWriteReq,
    171: FileIo.MsgFileioWriteResp,
    4097: FileIo.MsgFileioConfigReq,
    4098: FileIo.MsgFileioConfigResp,
  
    230: Flash.MsgFlashProgram,
    224: Flash.MsgFlashDone,
    231: Flash.MsgFlashReadReq,
    225: Flash.MsgFlashReadResp,
    226: Flash.MsgFlashErase,
    227: Flash.MsgStmFlashLockSector,
    228: Flash.MsgStmFlashUnlockSector,
    232: Flash.MsgStmUniqueIdReq,
    229: Flash.MsgStmUniqueIdResp,
    243: Flash.MsgM25FlashWriteStatus,
  
  
    2304: Imu.MsgImuRaw,
    2305: Imu.MsgImuAux,
  
    3001: Integrity.MsgSsrFlagHighLevel,
    3005: Integrity.MsgSsrFlagSatellites,
    3011: Integrity.MsgSsrFlagTropoGridPoints,
    3015: Integrity.MsgSsrFlagIonoGridPoints,
    3021: Integrity.MsgSsrFlagIonoTileSatLos,
    3025: Integrity.MsgSsrFlagIonoGridPointSatLos,
    3026: Integrity.MsgAcknowledge,
  
    32512: Linux.MsgLinuxCpuStateDepA,
    32513: Linux.MsgLinuxMemStateDepA,
    32514: Linux.MsgLinuxSysStateDepA,
    32515: Linux.MsgLinuxProcessSocketCounts,
    32516: Linux.MsgLinuxProcessSocketQueues,
    32517: Linux.MsgLinuxSocketUsage,
    32518: Linux.MsgLinuxProcessFdCount,
    32519: Linux.MsgLinuxProcessFdSummary,
    32520: Linux.MsgLinuxCpuState,
    32521: Linux.MsgLinuxMemState,
    32522: Linux.MsgLinuxSysState,
  
    1025: Logging.MsgLog,
    1026: Logging.MsgFwd,
    16: Logging.MsgPrintDep,
  
    2306: Mag.MsgMagRaw,
  
    258: Navigation.MsgGpsTime,
    260: Navigation.MsgGpsTimeGnss,
    259: Navigation.MsgUtcTime,
    261: Navigation.MsgUtcTimeGnss,
    520: Navigation.MsgDops,
    521: Navigation.MsgPosEcef,
    532: Navigation.MsgPosEcefCov,
    522: Navigation.MsgPosLlh,
    529: Navigation.MsgPosLlhCov,
    536: Navigation.MsgPosLlhAcc,
    523: Navigation.MsgBaselineEcef,
    524: Navigation.MsgBaselineNed,
    525: Navigation.MsgVelEcef,
    533: Navigation.MsgVelEcefCov,
    526: Navigation.MsgVelNed,
    530: Navigation.MsgVelNedCov,
    553: Navigation.MsgPosEcefGnss,
    564: Navigation.MsgPosEcefCovGnss,
    554: Navigation.MsgPosLlhGnss,
    561: Navigation.MsgPosLlhCovGnss,
    557: Navigation.MsgVelEcefGnss,
    565: Navigation.MsgVelEcefCovGnss,
    558: Navigation.MsgVelNedGnss,
    562: Navigation.MsgVelNedCovGnss,
    531: Navigation.MsgVelBody,
    540: Navigation.MsgVelCog,
    528: Navigation.MsgAgeCorrections,
    256: Navigation.MsgGpsTimeDepA,
    518: Navigation.MsgDopsDepA,
    512: Navigation.MsgPosEcefDepA,
    513: Navigation.MsgPosLlhDepA,
    514: Navigation.MsgBaselineEcefDepA,
    515: Navigation.MsgBaselineNedDepA,
    516: Navigation.MsgVelEcefDepA,
    517: Navigation.MsgVelNedDepA,
    519: Navigation.MsgBaselineHeadingDepA,
    534: Navigation.MsgProtectionLevelDepA,
    535: Navigation.MsgProtectionLevel,
    570: Navigation.MsgUtcLeapSecond,
    580: Navigation.MsgReferenceFrameParam,
    581: Navigation.MsgPoseRelative,
  
    1024: Ndb.MsgNdbEvent,
  
    74: Observation.MsgObs,
    68: Observation.MsgBasePosLlh,
    72: Observation.MsgBasePosEcef,
    129: Observation.MsgEphemerisGpsDepE,
    134: Observation.MsgEphemerisGpsDepF,
    138: Observation.MsgEphemerisGps,
    142: Observation.MsgEphemerisQzss,
    137: Observation.MsgEphemerisBds,
    149: Observation.MsgEphemerisGalDepA,
    141: Observation.MsgEphemerisGal,
    130: Observation.MsgEphemerisSbasDepA,
    131: Observation.MsgEphemerisGloDepA,
    132: Observation.MsgEphemerisSbasDepB,
    140: Observation.MsgEphemerisSbas,
    133: Observation.MsgEphemerisGloDepB,
    135: Observation.MsgEphemerisGloDepC,
    136: Observation.MsgEphemerisGloDepD,
    139: Observation.MsgEphemerisGlo,
    128: Observation.MsgEphemerisDepD,
    26: Observation.MsgEphemerisDepA,
    70: Observation.MsgEphemerisDepB,
    71: Observation.MsgEphemerisDepC,
    69: Observation.MsgObsDepA,
    67: Observation.MsgObsDepB,
    73: Observation.MsgObsDepC,
    144: Observation.MsgIono,
    145: Observation.MsgSvConfigurationGpsDep,
    150: Observation.MsgGnssCapb,
    146: Observation.MsgGroupDelayDepA,
    147: Observation.MsgGroupDelayDepB,
    148: Observation.MsgGroupDelay,
    112: Observation.MsgAlmanacGpsDep,
    114: Observation.MsgAlmanacGps,
    113: Observation.MsgAlmanacGloDep,
    115: Observation.MsgAlmanacGlo,
    117: Observation.MsgGloBiases,
    151: Observation.MsgSvAzEl,
    1600: Observation.MsgOsr,
  
    527: Orientation.MsgBaselineHeading,
    544: Orientation.MsgOrientQuat,
    545: Orientation.MsgOrientEuler,
    546: Orientation.MsgAngularRate,
  
    105: Piksi.MsgAlmanac,
    104: Piksi.MsgSetTime,
    182: Piksi.MsgReset,
    178: Piksi.MsgResetDep,
    192: Piksi.MsgCwResults,
    193: Piksi.MsgCwStart,
    34: Piksi.MsgResetFilters,
    35: Piksi.MsgInitBaseDep,
    23: Piksi.MsgThreadState,
    29: Piksi.MsgUartState,
    24: Piksi.MsgUartStateDepa,
    25: Piksi.MsgIarState,
    43: Piksi.MsgMaskSatellite,
    27: Piksi.MsgMaskSatelliteDep,
    181: Piksi.MsgDeviceMonitor,
    184: Piksi.MsgCommandReq,
    185: Piksi.MsgCommandResp,
    188: Piksi.MsgCommandOutput,
    186: Piksi.MsgNetworkStateReq,
    187: Piksi.MsgNetworkStateResp,
    189: Piksi.MsgNetworkBandwidthUsage,
    190: Piksi.MsgCellModemStatus,
    80: Piksi.MsgSpecanDep,
    81: Piksi.MsgSpecan,
    191: Piksi.MsgFrontEndGain,
  
    52992: Profiling.MsgMeasurementPoint,
    52993: Profiling.MsgProfilingSystemInfo,
    52994: Profiling.MsgProfilingThreadInfo,
    52995: Profiling.MsgProfilingResourceCounter,
  
    30583: Sbas.MsgSbasRaw,
  
    161: Settings.MsgSettingsSave,
    160: Settings.MsgSettingsWrite,
    175: Settings.MsgSettingsWriteResp,
    164: Settings.MsgSettingsReadReq,
    165: Settings.MsgSettingsReadResp,
    162: Settings.MsgSettingsReadByIndexReq,
    167: Settings.MsgSettingsReadByIndexResp,
    166: Settings.MsgSettingsReadByIndexDone,
    174: Settings.MsgSettingsRegister,
    431: Settings.MsgSettingsRegisterResp,
  
    3076: Signing.MsgEcdsaCertificate,
    3081: Signing.MsgCertificateChain,
    3077: Signing.MsgCertificateChainDep,
    3080: Signing.MsgEcdsaSignature,
    3079: Signing.MsgEcdsaSignatureDepB,
    3078: Signing.MsgEcdsaSignatureDepA,
    3074: Signing.MsgEd25519CertificateDep,
    3073: Signing.MsgEd25519SignatureDepA,
    3075: Signing.MsgEd25519SignatureDepB,
  
    65295: SolutionMeta.MsgSolnMetaDepA,
    65294: SolutionMeta.MsgSolnMeta,
  
    1501: Ssr.MsgSsrOrbitClock,
    1505: Ssr.MsgSsrCodeBiases,
    1510: Ssr.MsgSsrPhaseBiases,
    1531: Ssr.MsgSsrStecCorrectionDep,
    1533: Ssr.MsgSsrStecCorrection,
    1532: Ssr.MsgSsrGriddedCorrection,
    1534: Ssr.MsgSsrGriddedCorrectionBounds,
    1526: Ssr.MsgSsrTileDefinitionDepA,
    1527: Ssr.MsgSsrTileDefinitionDepB,
    1528: Ssr.MsgSsrTileDefinition,
    1540: Ssr.MsgSsrSatelliteApcDep,
    1541: Ssr.MsgSsrSatelliteApc,
    1500: Ssr.MsgSsrOrbitClockDepA,
    1515: Ssr.MsgSsrStecCorrectionDepA,
    1520: Ssr.MsgSsrGriddedCorrectionNoStdDepA,
    1530: Ssr.MsgSsrGriddedCorrectionDepA,
    1525: Ssr.MsgSsrGridDefinitionDepA,
    1502: Ssr.MsgSsrOrbitClockBounds,
    1516: Ssr.MsgSsrCodePhaseBiasesBounds,
    1503: Ssr.MsgSsrOrbitClockBoundsDegradation,
  
    65280: System.MsgStartup,
    65282: System.MsgDgnssStatus,
    65535: System.MsgHeartbeat,
    65534: System.MsgStatusReport,
    65533: System.MsgStatusJournal,
    65283: System.MsgInsStatus,
    65284: System.MsgCsacTelemetry,
    65285: System.MsgCsacTelemetryLabels,
    65286: System.MsgInsUpdates,
    65287: System.MsgGnssTimeOffset,
    65288: System.MsgPpsTime,
    65289: System.MsgSensorAidEvent,
    65290: System.MsgGroupMeta,
  
    288: Telemetry.MsgTelSv,
  
    33: Tracking.MsgTrackingStateDetailedDepA,
    17: Tracking.MsgTrackingStateDetailedDep,
    65: Tracking.MsgTrackingState,
    97: Tracking.MsgMeasurementState,
    45: Tracking.MsgTrackingIq,
    44: Tracking.MsgTrackingIqDepB,
    28: Tracking.MsgTrackingIqDepA,
    22: Tracking.MsgTrackingStateDepA,
    19: Tracking.MsgTrackingStateDepB,
  
    2048: User.MsgUserData,
  
    2307: Vehicle.MsgOdometry,
    2308: Vehicle.MsgWheeltick,
}

# Extend Sbp.SbpMessage to use table-based lookup
class SbpMessage(Sbp.SbpMessage):
    def __init__(self, _io, _parent=None, _root=None):
        super().__init__(_io, _parent, _root)


    def _read(self):
        self.preamble = self._io.read_bytes(1)
        if not self.preamble == b"\x55":
            raise kaitaistruct.ValidationNotEqualError(b"\x55", self.preamble, self._io, "Preamble")

        msg_type = self._io.read_u2le()
        if msg_type not in TABLE:
            raise kaitaistruct.ValidationNotAnyOfError(msg_type, self._io, "Message Type")
        self.msg_type = msg_type

        self.sender = self._io.read_u2le()
        self.length = self._io.read_u1()

        self._raw_payload = self._io.read_bytes(self.length)
        _io__raw_payload = KaitaiStream(BytesIO(self._raw_payload))
        self.payload = TABLE[msg_type](_io__raw_payload, self, self._root)

        self.crc = self._io.read_u2le()