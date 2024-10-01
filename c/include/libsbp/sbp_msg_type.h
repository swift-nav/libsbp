/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_SBP_MSG_TYPE_H
#define LIBSBP_SBP_MSG_TYPE_H

#include <libsbp/acquisition_macros.h>
#include <libsbp/bootload_macros.h>
#include <libsbp/ext_events_macros.h>
#include <libsbp/file_io_macros.h>
#include <libsbp/flash_macros.h>
#include <libsbp/gnss_macros.h>
#include <libsbp/imu_macros.h>
#include <libsbp/integrity_macros.h>
#include <libsbp/linux_macros.h>
#include <libsbp/logging_macros.h>
#include <libsbp/mag_macros.h>
#include <libsbp/navigation_macros.h>
#include <libsbp/ndb_macros.h>
#include <libsbp/observation_macros.h>
#include <libsbp/orientation_macros.h>
#include <libsbp/piksi_macros.h>
#include <libsbp/profiling_macros.h>
#include <libsbp/sbas_macros.h>
#include <libsbp/settings_macros.h>
#include <libsbp/signing_macros.h>
#include <libsbp/solution_meta_macros.h>
#include <libsbp/ssr_macros.h>
#include <libsbp/system_macros.h>
#include <libsbp/telemetry_macros.h>
#include <libsbp/tracking_macros.h>
#include <libsbp/user_macros.h>
#include <libsbp/vehicle_macros.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  SbpMsgAcknowledge = 0x0BD2,
  SbpMsgAcqResultDepA = 0x0015,
  SbpMsgAcqResultDepB = 0x0014,
  SbpMsgAcqResultDepC = 0x001F,
  SbpMsgAcqResult = 0x002F,
  SbpMsgAcqSvProfileDep = 0x001E,
  SbpMsgAcqSvProfile = 0x002E,
  SbpMsgAesCmacSignature = 0x0C10,
  SbpMsgAgeCorrections = 0x0210,
  SbpMsgAlmanacGloDep = 0x0071,
  SbpMsgAlmanacGlo = 0x0073,
  SbpMsgAlmanacGpsDep = 0x0070,
  SbpMsgAlmanacGps = 0x0072,
  SbpMsgAlmanac = 0x0069,
  SbpMsgAngularRate = 0x0222,
  SbpMsgBasePosEcef = 0x0048,
  SbpMsgBasePosLlh = 0x0044,
  SbpMsgBaselineEcefDepA = 0x0202,
  SbpMsgBaselineEcef = 0x020B,
  SbpMsgBaselineHeadingDepA = 0x0207,
  SbpMsgBaselineHeading = 0x020F,
  SbpMsgBaselineNedDepA = 0x0203,
  SbpMsgBaselineNed = 0x020C,
  SbpMsgBootloaderHandshakeDepA = 0x00B0,
  SbpMsgBootloaderHandshakeReq = 0x00B3,
  SbpMsgBootloaderHandshakeResp = 0x00B4,
  SbpMsgBootloaderJumpToApp = 0x00B1,
  SbpMsgCellModemStatus = 0x00BE,
  SbpMsgCertificateChainDep = 0x0C05,
  SbpMsgCertificateChain = 0x0C09,
  SbpMsgCommandOutput = 0x00BC,
  SbpMsgCommandReq = 0x00B8,
  SbpMsgCommandResp = 0x00B9,
  SbpMsgCsacTelemetryLabels = 0xFF05,
  SbpMsgCsacTelemetry = 0xFF04,
  SbpMsgCwResults = 0x00C0,
  SbpMsgCwStart = 0x00C1,
  SbpMsgDeviceMonitor = 0x00B5,
  SbpMsgDgnssStatus = 0xFF02,
  SbpMsgDopsDepA = 0x0206,
  SbpMsgDops = 0x0208,
  SbpMsgEcdsaCertificate = 0x0C04,
  SbpMsgEcdsaSignatureDepA = 0x0C06,
  SbpMsgEcdsaSignatureDepB = 0x0C07,
  SbpMsgEcdsaSignature = 0x0C08,
  SbpMsgEd25519CertificateDep = 0x0C02,
  SbpMsgEd25519SignatureDepA = 0x0C01,
  SbpMsgEd25519SignatureDepB = 0x0C03,
  SbpMsgEphemerisBds = 0x0089,
  SbpMsgEphemerisDepA = 0x001A,
  SbpMsgEphemerisDepB = 0x0046,
  SbpMsgEphemerisDepC = 0x0047,
  SbpMsgEphemerisDepD = 0x0080,
  SbpMsgEphemerisGalDepA = 0x0095,
  SbpMsgEphemerisGal = 0x008D,
  SbpMsgEphemerisGloDepA = 0x0083,
  SbpMsgEphemerisGloDepB = 0x0085,
  SbpMsgEphemerisGloDepC = 0x0087,
  SbpMsgEphemerisGloDepD = 0x0088,
  SbpMsgEphemerisGlo = 0x008B,
  SbpMsgEphemerisGpsDepE = 0x0081,
  SbpMsgEphemerisGpsDepF = 0x0086,
  SbpMsgEphemerisGps = 0x008A,
  SbpMsgEphemerisQzss = 0x008E,
  SbpMsgEphemerisSbasDepA = 0x0082,
  SbpMsgEphemerisSbasDepB = 0x0084,
  SbpMsgEphemerisSbas = 0x008C,
  SbpMsgExtEvent = 0x0101,
  SbpMsgFileioConfigReq = 0x1001,
  SbpMsgFileioConfigResp = 0x1002,
  SbpMsgFileioReadDirReq = 0x00A9,
  SbpMsgFileioReadDirResp = 0x00AA,
  SbpMsgFileioReadReq = 0x00A8,
  SbpMsgFileioReadResp = 0x00A3,
  SbpMsgFileioRemove = 0x00AC,
  SbpMsgFileioWriteReq = 0x00AD,
  SbpMsgFileioWriteResp = 0x00AB,
  SbpMsgFlashDone = 0x00E0,
  SbpMsgFlashErase = 0x00E2,
  SbpMsgFlashProgram = 0x00E6,
  SbpMsgFlashReadReq = 0x00E7,
  SbpMsgFlashReadResp = 0x00E1,
  SbpMsgFrontEndGain = 0x00BF,
  SbpMsgFwd = 0x0402,
  SbpMsgGloBiases = 0x0075,
  SbpMsgGnssCapb = 0x0096,
  SbpMsgGnssTimeOffset = 0xFF07,
  SbpMsgGpsTimeDepA = 0x0100,
  SbpMsgGpsTimeGnss = 0x0104,
  SbpMsgGpsTime = 0x0102,
  SbpMsgGroupDelayDepA = 0x0092,
  SbpMsgGroupDelayDepB = 0x0093,
  SbpMsgGroupDelay = 0x0094,
  SbpMsgGroupMeta = 0xFF0A,
  SbpMsgHeartbeat = 0xFFFF,
  SbpMsgIarState = 0x0019,
  SbpMsgImuAux = 0x0901,
  SbpMsgImuComp = 0x0905,
  SbpMsgImuRaw = 0x0900,
  SbpMsgInitBaseDep = 0x0023,
  SbpMsgInsStatus = 0xFF03,
  SbpMsgInsUpdates = 0xFF06,
  SbpMsgIono = 0x0090,
  SbpMsgLinuxCpuStateDepA = 0x7F00,
  SbpMsgLinuxCpuState = 0x7F08,
  SbpMsgLinuxMemStateDepA = 0x7F01,
  SbpMsgLinuxMemState = 0x7F09,
  SbpMsgLinuxProcessFdCount = 0x7F06,
  SbpMsgLinuxProcessFdSummary = 0x7F07,
  SbpMsgLinuxProcessSocketCounts = 0x7F03,
  SbpMsgLinuxProcessSocketQueues = 0x7F04,
  SbpMsgLinuxSocketUsage = 0x7F05,
  SbpMsgLinuxSysStateDepA = 0x7F02,
  SbpMsgLinuxSysState = 0x7F0A,
  SbpMsgLog = 0x0401,
  SbpMsgM25FlashWriteStatus = 0x00F3,
  SbpMsgMagRaw = 0x0902,
  SbpMsgMaskSatelliteDep = 0x001B,
  SbpMsgMaskSatellite = 0x002B,
  SbpMsgMeasurementPoint = 0xCF00,
  SbpMsgMeasurementState = 0x0061,
  SbpMsgNapDeviceDnaReq = 0x00DE,
  SbpMsgNapDeviceDnaResp = 0x00DD,
  SbpMsgNdbEvent = 0x0400,
  SbpMsgNetworkBandwidthUsage = 0x00BD,
  SbpMsgNetworkStateReq = 0x00BA,
  SbpMsgNetworkStateResp = 0x00BB,
  SbpMsgObsDepA = 0x0045,
  SbpMsgObsDepB = 0x0043,
  SbpMsgObsDepC = 0x0049,
  SbpMsgObs = 0x004A,
  SbpMsgOdometry = 0x0903,
  SbpMsgOrientEuler = 0x0221,
  SbpMsgOrientQuat = 0x0220,
  SbpMsgOsr = 0x0640,
  SbpMsgPosEcefCovGnss = 0x0234,
  SbpMsgPosEcefCov = 0x0214,
  SbpMsgPosEcefDepA = 0x0200,
  SbpMsgPosEcefGnss = 0x0229,
  SbpMsgPosEcef = 0x0209,
  SbpMsgPosLlhAcc = 0x0218,
  SbpMsgPosLlhCovGnss = 0x0231,
  SbpMsgPosLlhCov = 0x0211,
  SbpMsgPosLlhDepA = 0x0201,
  SbpMsgPosLlhGnss = 0x022A,
  SbpMsgPosLlh = 0x020A,
  SbpMsgPoseRelative = 0x0245,
  SbpMsgPpsTime = 0xFF08,
  SbpMsgPrintDep = 0x0010,
  SbpMsgProfilingResourceCounter = 0xCF03,
  SbpMsgProfilingSystemInfo = 0xCF01,
  SbpMsgProfilingThreadInfo = 0xCF02,
  SbpMsgProtectionLevelDepA = 0x0216,
  SbpMsgProtectionLevel = 0x0217,
  SbpMsgReferenceFrameParam = 0x0244,
  SbpMsgResetDep = 0x00B2,
  SbpMsgResetFilters = 0x0022,
  SbpMsgReset = 0x00B6,
  SbpMsgSbasRaw = 0x7777,
  SbpMsgSensorAidEvent = 0xFF09,
  SbpMsgSetTime = 0x0068,
  SbpMsgSettingsReadByIndexDone = 0x00A6,
  SbpMsgSettingsReadByIndexReq = 0x00A2,
  SbpMsgSettingsReadByIndexResp = 0x00A7,
  SbpMsgSettingsReadReq = 0x00A4,
  SbpMsgSettingsReadResp = 0x00A5,
  SbpMsgSettingsRegisterResp = 0x01AF,
  SbpMsgSettingsRegister = 0x00AE,
  SbpMsgSettingsSave = 0x00A1,
  SbpMsgSettingsWriteResp = 0x00AF,
  SbpMsgSettingsWrite = 0x00A0,
  SbpMsgSolnMetaDepA = 0xFF0F,
  SbpMsgSolnMeta = 0xFF0E,
  SbpMsgSpecanDep = 0x0050,
  SbpMsgSpecan = 0x0051,
  SbpMsgSsrCodeBiases = 0x05E1,
  SbpMsgSsrCodePhaseBiasesBounds = 0x05EC,
  SbpMsgSsrFlagHighLevel = 0x0BB9,
  SbpMsgSsrFlagIonoGridPointSatLos = 0x0BD1,
  SbpMsgSsrFlagIonoGridPoints = 0x0BC7,
  SbpMsgSsrFlagIonoTileSatLos = 0x0BCD,
  SbpMsgSsrFlagSatellites = 0x0BBD,
  SbpMsgSsrFlagTropoGridPoints = 0x0BC3,
  SbpMsgSsrGridDefinitionDepA = 0x05F5,
  SbpMsgSsrGriddedCorrectionBounds = 0x05FE,
  SbpMsgSsrGriddedCorrectionDepA = 0x05FA,
  SbpMsgSsrGriddedCorrectionNoStdDepA = 0x05F0,
  SbpMsgSsrGriddedCorrection = 0x05FC,
  SbpMsgSsrOrbitClockBoundsDegradation = 0x05DF,
  SbpMsgSsrOrbitClockBounds = 0x05DE,
  SbpMsgSsrOrbitClockDepA = 0x05DC,
  SbpMsgSsrOrbitClock = 0x05DD,
  SbpMsgSsrPhaseBiases = 0x05E6,
  SbpMsgSsrSatelliteApcDep = 0x0604,
  SbpMsgSsrSatelliteApc = 0x0605,
  SbpMsgSsrStecCorrectionDepA = 0x05EB,
  SbpMsgSsrStecCorrectionDep = 0x05FB,
  SbpMsgSsrStecCorrection = 0x05FD,
  SbpMsgSsrTileDefinitionDepA = 0x05F6,
  SbpMsgSsrTileDefinitionDepB = 0x05F7,
  SbpMsgSsrTileDefinition = 0x05F8,
  SbpMsgStartup = 0xFF00,
  SbpMsgStatusJournal = 0xFFFD,
  SbpMsgStatusReport = 0xFFFE,
  SbpMsgStmFlashLockSector = 0x00E3,
  SbpMsgStmFlashUnlockSector = 0x00E4,
  SbpMsgStmUniqueIdReq = 0x00E8,
  SbpMsgStmUniqueIdResp = 0x00E5,
  SbpMsgSvAzEl = 0x0097,
  SbpMsgSvConfigurationGpsDep = 0x0091,
  SbpMsgTelSv = 0x0120,
  SbpMsgThreadState = 0x0017,
  SbpMsgTrackingIqDepA = 0x001C,
  SbpMsgTrackingIqDepB = 0x002C,
  SbpMsgTrackingIq = 0x002D,
  SbpMsgTrackingStateDepA = 0x0016,
  SbpMsgTrackingStateDepB = 0x0013,
  SbpMsgTrackingStateDetailedDepA = 0x0021,
  SbpMsgTrackingStateDetailedDep = 0x0011,
  SbpMsgTrackingState = 0x0041,
  SbpMsgUartStateDepa = 0x0018,
  SbpMsgUartState = 0x001D,
  SbpMsgUserData = 0x0800,
  SbpMsgUtcLeapSecond = 0x023A,
  SbpMsgUtcTimeGnss = 0x0105,
  SbpMsgUtcTime = 0x0103,
  SbpMsgVelBody = 0x0213,
  SbpMsgVelCog = 0x021C,
  SbpMsgVelEcefCovGnss = 0x0235,
  SbpMsgVelEcefCov = 0x0215,
  SbpMsgVelEcefDepA = 0x0204,
  SbpMsgVelEcefGnss = 0x022D,
  SbpMsgVelEcef = 0x020D,
  SbpMsgVelNedCovGnss = 0x0232,
  SbpMsgVelNedCov = 0x0212,
  SbpMsgVelNedDepA = 0x0205,
  SbpMsgVelNedGnss = 0x022E,
  SbpMsgVelNed = 0x020E,
  SbpMsgWheeltick = 0x0904,
  SbpMsgAll = 0,
  SbpMsgUnknown = 0,
} sbp_msg_type_t;

static inline const char *sbp_msg_type_to_string(sbp_msg_type_t msg_type) {
  switch (msg_type) {
    case SbpMsgAcknowledge:
      return "MSG_ACKNOWLEDGE";
    case SbpMsgAcqResultDepA:
      return "MSG_ACQ_RESULT_DEP_A";
    case SbpMsgAcqResultDepB:
      return "MSG_ACQ_RESULT_DEP_B";
    case SbpMsgAcqResultDepC:
      return "MSG_ACQ_RESULT_DEP_C";
    case SbpMsgAcqResult:
      return "MSG_ACQ_RESULT";
    case SbpMsgAcqSvProfileDep:
      return "MSG_ACQ_SV_PROFILE_DEP";
    case SbpMsgAcqSvProfile:
      return "MSG_ACQ_SV_PROFILE";
    case SbpMsgAesCmacSignature:
      return "MSG_AES_CMAC_SIGNATURE";
    case SbpMsgAgeCorrections:
      return "MSG_AGE_CORRECTIONS";
    case SbpMsgAlmanacGloDep:
      return "MSG_ALMANAC_GLO_DEP";
    case SbpMsgAlmanacGlo:
      return "MSG_ALMANAC_GLO";
    case SbpMsgAlmanacGpsDep:
      return "MSG_ALMANAC_GPS_DEP";
    case SbpMsgAlmanacGps:
      return "MSG_ALMANAC_GPS";
    case SbpMsgAlmanac:
      return "MSG_ALMANAC";
    case SbpMsgAngularRate:
      return "MSG_ANGULAR_RATE";
    case SbpMsgBasePosEcef:
      return "MSG_BASE_POS_ECEF";
    case SbpMsgBasePosLlh:
      return "MSG_BASE_POS_LLH";
    case SbpMsgBaselineEcefDepA:
      return "MSG_BASELINE_ECEF_DEP_A";
    case SbpMsgBaselineEcef:
      return "MSG_BASELINE_ECEF";
    case SbpMsgBaselineHeadingDepA:
      return "MSG_BASELINE_HEADING_DEP_A";
    case SbpMsgBaselineHeading:
      return "MSG_BASELINE_HEADING";
    case SbpMsgBaselineNedDepA:
      return "MSG_BASELINE_NED_DEP_A";
    case SbpMsgBaselineNed:
      return "MSG_BASELINE_NED";
    case SbpMsgBootloaderHandshakeDepA:
      return "MSG_BOOTLOADER_HANDSHAKE_DEP_A";
    case SbpMsgBootloaderHandshakeReq:
      return "MSG_BOOTLOADER_HANDSHAKE_REQ";
    case SbpMsgBootloaderHandshakeResp:
      return "MSG_BOOTLOADER_HANDSHAKE_RESP";
    case SbpMsgBootloaderJumpToApp:
      return "MSG_BOOTLOADER_JUMP_TO_APP";
    case SbpMsgCellModemStatus:
      return "MSG_CELL_MODEM_STATUS";
    case SbpMsgCertificateChainDep:
      return "MSG_CERTIFICATE_CHAIN_DEP";
    case SbpMsgCertificateChain:
      return "MSG_CERTIFICATE_CHAIN";
    case SbpMsgCommandOutput:
      return "MSG_COMMAND_OUTPUT";
    case SbpMsgCommandReq:
      return "MSG_COMMAND_REQ";
    case SbpMsgCommandResp:
      return "MSG_COMMAND_RESP";
    case SbpMsgCsacTelemetryLabels:
      return "MSG_CSAC_TELEMETRY_LABELS";
    case SbpMsgCsacTelemetry:
      return "MSG_CSAC_TELEMETRY";
    case SbpMsgCwResults:
      return "MSG_CW_RESULTS";
    case SbpMsgCwStart:
      return "MSG_CW_START";
    case SbpMsgDeviceMonitor:
      return "MSG_DEVICE_MONITOR";
    case SbpMsgDgnssStatus:
      return "MSG_DGNSS_STATUS";
    case SbpMsgDopsDepA:
      return "MSG_DOPS_DEP_A";
    case SbpMsgDops:
      return "MSG_DOPS";
    case SbpMsgEcdsaCertificate:
      return "MSG_ECDSA_CERTIFICATE";
    case SbpMsgEcdsaSignatureDepA:
      return "MSG_ECDSA_SIGNATURE_DEP_A";
    case SbpMsgEcdsaSignatureDepB:
      return "MSG_ECDSA_SIGNATURE_DEP_B";
    case SbpMsgEcdsaSignature:
      return "MSG_ECDSA_SIGNATURE";
    case SbpMsgEd25519CertificateDep:
      return "MSG_ED25519_CERTIFICATE_DEP";
    case SbpMsgEd25519SignatureDepA:
      return "MSG_ED25519_SIGNATURE_DEP_A";
    case SbpMsgEd25519SignatureDepB:
      return "MSG_ED25519_SIGNATURE_DEP_B";
    case SbpMsgEphemerisBds:
      return "MSG_EPHEMERIS_BDS";
    case SbpMsgEphemerisDepA:
      return "MSG_EPHEMERIS_DEP_A";
    case SbpMsgEphemerisDepB:
      return "MSG_EPHEMERIS_DEP_B";
    case SbpMsgEphemerisDepC:
      return "MSG_EPHEMERIS_DEP_C";
    case SbpMsgEphemerisDepD:
      return "MSG_EPHEMERIS_DEP_D";
    case SbpMsgEphemerisGalDepA:
      return "MSG_EPHEMERIS_GAL_DEP_A";
    case SbpMsgEphemerisGal:
      return "MSG_EPHEMERIS_GAL";
    case SbpMsgEphemerisGloDepA:
      return "MSG_EPHEMERIS_GLO_DEP_A";
    case SbpMsgEphemerisGloDepB:
      return "MSG_EPHEMERIS_GLO_DEP_B";
    case SbpMsgEphemerisGloDepC:
      return "MSG_EPHEMERIS_GLO_DEP_C";
    case SbpMsgEphemerisGloDepD:
      return "MSG_EPHEMERIS_GLO_DEP_D";
    case SbpMsgEphemerisGlo:
      return "MSG_EPHEMERIS_GLO";
    case SbpMsgEphemerisGpsDepE:
      return "MSG_EPHEMERIS_GPS_DEP_E";
    case SbpMsgEphemerisGpsDepF:
      return "MSG_EPHEMERIS_GPS_DEP_F";
    case SbpMsgEphemerisGps:
      return "MSG_EPHEMERIS_GPS";
    case SbpMsgEphemerisQzss:
      return "MSG_EPHEMERIS_QZSS";
    case SbpMsgEphemerisSbasDepA:
      return "MSG_EPHEMERIS_SBAS_DEP_A";
    case SbpMsgEphemerisSbasDepB:
      return "MSG_EPHEMERIS_SBAS_DEP_B";
    case SbpMsgEphemerisSbas:
      return "MSG_EPHEMERIS_SBAS";
    case SbpMsgExtEvent:
      return "MSG_EXT_EVENT";
    case SbpMsgFileioConfigReq:
      return "MSG_FILEIO_CONFIG_REQ";
    case SbpMsgFileioConfigResp:
      return "MSG_FILEIO_CONFIG_RESP";
    case SbpMsgFileioReadDirReq:
      return "MSG_FILEIO_READ_DIR_REQ";
    case SbpMsgFileioReadDirResp:
      return "MSG_FILEIO_READ_DIR_RESP";
    case SbpMsgFileioReadReq:
      return "MSG_FILEIO_READ_REQ";
    case SbpMsgFileioReadResp:
      return "MSG_FILEIO_READ_RESP";
    case SbpMsgFileioRemove:
      return "MSG_FILEIO_REMOVE";
    case SbpMsgFileioWriteReq:
      return "MSG_FILEIO_WRITE_REQ";
    case SbpMsgFileioWriteResp:
      return "MSG_FILEIO_WRITE_RESP";
    case SbpMsgFlashDone:
      return "MSG_FLASH_DONE";
    case SbpMsgFlashErase:
      return "MSG_FLASH_ERASE";
    case SbpMsgFlashProgram:
      return "MSG_FLASH_PROGRAM";
    case SbpMsgFlashReadReq:
      return "MSG_FLASH_READ_REQ";
    case SbpMsgFlashReadResp:
      return "MSG_FLASH_READ_RESP";
    case SbpMsgFrontEndGain:
      return "MSG_FRONT_END_GAIN";
    case SbpMsgFwd:
      return "MSG_FWD";
    case SbpMsgGloBiases:
      return "MSG_GLO_BIASES";
    case SbpMsgGnssCapb:
      return "MSG_GNSS_CAPB";
    case SbpMsgGnssTimeOffset:
      return "MSG_GNSS_TIME_OFFSET";
    case SbpMsgGpsTimeDepA:
      return "MSG_GPS_TIME_DEP_A";
    case SbpMsgGpsTimeGnss:
      return "MSG_GPS_TIME_GNSS";
    case SbpMsgGpsTime:
      return "MSG_GPS_TIME";
    case SbpMsgGroupDelayDepA:
      return "MSG_GROUP_DELAY_DEP_A";
    case SbpMsgGroupDelayDepB:
      return "MSG_GROUP_DELAY_DEP_B";
    case SbpMsgGroupDelay:
      return "MSG_GROUP_DELAY";
    case SbpMsgGroupMeta:
      return "MSG_GROUP_META";
    case SbpMsgHeartbeat:
      return "MSG_HEARTBEAT";
    case SbpMsgIarState:
      return "MSG_IAR_STATE";
    case SbpMsgImuAux:
      return "MSG_IMU_AUX";
    case SbpMsgImuComp:
      return "MSG_IMU_COMP";
    case SbpMsgImuRaw:
      return "MSG_IMU_RAW";
    case SbpMsgInitBaseDep:
      return "MSG_INIT_BASE_DEP";
    case SbpMsgInsStatus:
      return "MSG_INS_STATUS";
    case SbpMsgInsUpdates:
      return "MSG_INS_UPDATES";
    case SbpMsgIono:
      return "MSG_IONO";
    case SbpMsgLinuxCpuStateDepA:
      return "MSG_LINUX_CPU_STATE_DEP_A";
    case SbpMsgLinuxCpuState:
      return "MSG_LINUX_CPU_STATE";
    case SbpMsgLinuxMemStateDepA:
      return "MSG_LINUX_MEM_STATE_DEP_A";
    case SbpMsgLinuxMemState:
      return "MSG_LINUX_MEM_STATE";
    case SbpMsgLinuxProcessFdCount:
      return "MSG_LINUX_PROCESS_FD_COUNT";
    case SbpMsgLinuxProcessFdSummary:
      return "MSG_LINUX_PROCESS_FD_SUMMARY";
    case SbpMsgLinuxProcessSocketCounts:
      return "MSG_LINUX_PROCESS_SOCKET_COUNTS";
    case SbpMsgLinuxProcessSocketQueues:
      return "MSG_LINUX_PROCESS_SOCKET_QUEUES";
    case SbpMsgLinuxSocketUsage:
      return "MSG_LINUX_SOCKET_USAGE";
    case SbpMsgLinuxSysStateDepA:
      return "MSG_LINUX_SYS_STATE_DEP_A";
    case SbpMsgLinuxSysState:
      return "MSG_LINUX_SYS_STATE";
    case SbpMsgLog:
      return "MSG_LOG";
    case SbpMsgM25FlashWriteStatus:
      return "MSG_M25_FLASH_WRITE_STATUS";
    case SbpMsgMagRaw:
      return "MSG_MAG_RAW";
    case SbpMsgMaskSatelliteDep:
      return "MSG_MASK_SATELLITE_DEP";
    case SbpMsgMaskSatellite:
      return "MSG_MASK_SATELLITE";
    case SbpMsgMeasurementPoint:
      return "MSG_MEASUREMENT_POINT";
    case SbpMsgMeasurementState:
      return "MSG_MEASUREMENT_STATE";
    case SbpMsgNapDeviceDnaReq:
      return "MSG_NAP_DEVICE_DNA_REQ";
    case SbpMsgNapDeviceDnaResp:
      return "MSG_NAP_DEVICE_DNA_RESP";
    case SbpMsgNdbEvent:
      return "MSG_NDB_EVENT";
    case SbpMsgNetworkBandwidthUsage:
      return "MSG_NETWORK_BANDWIDTH_USAGE";
    case SbpMsgNetworkStateReq:
      return "MSG_NETWORK_STATE_REQ";
    case SbpMsgNetworkStateResp:
      return "MSG_NETWORK_STATE_RESP";
    case SbpMsgObsDepA:
      return "MSG_OBS_DEP_A";
    case SbpMsgObsDepB:
      return "MSG_OBS_DEP_B";
    case SbpMsgObsDepC:
      return "MSG_OBS_DEP_C";
    case SbpMsgObs:
      return "MSG_OBS";
    case SbpMsgOdometry:
      return "MSG_ODOMETRY";
    case SbpMsgOrientEuler:
      return "MSG_ORIENT_EULER";
    case SbpMsgOrientQuat:
      return "MSG_ORIENT_QUAT";
    case SbpMsgOsr:
      return "MSG_OSR";
    case SbpMsgPosEcefCovGnss:
      return "MSG_POS_ECEF_COV_GNSS";
    case SbpMsgPosEcefCov:
      return "MSG_POS_ECEF_COV";
    case SbpMsgPosEcefDepA:
      return "MSG_POS_ECEF_DEP_A";
    case SbpMsgPosEcefGnss:
      return "MSG_POS_ECEF_GNSS";
    case SbpMsgPosEcef:
      return "MSG_POS_ECEF";
    case SbpMsgPosLlhAcc:
      return "MSG_POS_LLH_ACC";
    case SbpMsgPosLlhCovGnss:
      return "MSG_POS_LLH_COV_GNSS";
    case SbpMsgPosLlhCov:
      return "MSG_POS_LLH_COV";
    case SbpMsgPosLlhDepA:
      return "MSG_POS_LLH_DEP_A";
    case SbpMsgPosLlhGnss:
      return "MSG_POS_LLH_GNSS";
    case SbpMsgPosLlh:
      return "MSG_POS_LLH";
    case SbpMsgPoseRelative:
      return "MSG_POSE_RELATIVE";
    case SbpMsgPpsTime:
      return "MSG_PPS_TIME";
    case SbpMsgPrintDep:
      return "MSG_PRINT_DEP";
    case SbpMsgProfilingResourceCounter:
      return "MSG_PROFILING_RESOURCE_COUNTER";
    case SbpMsgProfilingSystemInfo:
      return "MSG_PROFILING_SYSTEM_INFO";
    case SbpMsgProfilingThreadInfo:
      return "MSG_PROFILING_THREAD_INFO";
    case SbpMsgProtectionLevelDepA:
      return "MSG_PROTECTION_LEVEL_DEP_A";
    case SbpMsgProtectionLevel:
      return "MSG_PROTECTION_LEVEL";
    case SbpMsgReferenceFrameParam:
      return "MSG_REFERENCE_FRAME_PARAM";
    case SbpMsgResetDep:
      return "MSG_RESET_DEP";
    case SbpMsgResetFilters:
      return "MSG_RESET_FILTERS";
    case SbpMsgReset:
      return "MSG_RESET";
    case SbpMsgSbasRaw:
      return "MSG_SBAS_RAW";
    case SbpMsgSensorAidEvent:
      return "MSG_SENSOR_AID_EVENT";
    case SbpMsgSetTime:
      return "MSG_SET_TIME";
    case SbpMsgSettingsReadByIndexDone:
      return "MSG_SETTINGS_READ_BY_INDEX_DONE";
    case SbpMsgSettingsReadByIndexReq:
      return "MSG_SETTINGS_READ_BY_INDEX_REQ";
    case SbpMsgSettingsReadByIndexResp:
      return "MSG_SETTINGS_READ_BY_INDEX_RESP";
    case SbpMsgSettingsReadReq:
      return "MSG_SETTINGS_READ_REQ";
    case SbpMsgSettingsReadResp:
      return "MSG_SETTINGS_READ_RESP";
    case SbpMsgSettingsRegisterResp:
      return "MSG_SETTINGS_REGISTER_RESP";
    case SbpMsgSettingsRegister:
      return "MSG_SETTINGS_REGISTER";
    case SbpMsgSettingsSave:
      return "MSG_SETTINGS_SAVE";
    case SbpMsgSettingsWriteResp:
      return "MSG_SETTINGS_WRITE_RESP";
    case SbpMsgSettingsWrite:
      return "MSG_SETTINGS_WRITE";
    case SbpMsgSolnMetaDepA:
      return "MSG_SOLN_META_DEP_A";
    case SbpMsgSolnMeta:
      return "MSG_SOLN_META";
    case SbpMsgSpecanDep:
      return "MSG_SPECAN_DEP";
    case SbpMsgSpecan:
      return "MSG_SPECAN";
    case SbpMsgSsrCodeBiases:
      return "MSG_SSR_CODE_BIASES";
    case SbpMsgSsrCodePhaseBiasesBounds:
      return "MSG_SSR_CODE_PHASE_BIASES_BOUNDS";
    case SbpMsgSsrFlagHighLevel:
      return "MSG_SSR_FLAG_HIGH_LEVEL";
    case SbpMsgSsrFlagIonoGridPointSatLos:
      return "MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS";
    case SbpMsgSsrFlagIonoGridPoints:
      return "MSG_SSR_FLAG_IONO_GRID_POINTS";
    case SbpMsgSsrFlagIonoTileSatLos:
      return "MSG_SSR_FLAG_IONO_TILE_SAT_LOS";
    case SbpMsgSsrFlagSatellites:
      return "MSG_SSR_FLAG_SATELLITES";
    case SbpMsgSsrFlagTropoGridPoints:
      return "MSG_SSR_FLAG_TROPO_GRID_POINTS";
    case SbpMsgSsrGridDefinitionDepA:
      return "MSG_SSR_GRID_DEFINITION_DEP_A";
    case SbpMsgSsrGriddedCorrectionBounds:
      return "MSG_SSR_GRIDDED_CORRECTION_BOUNDS";
    case SbpMsgSsrGriddedCorrectionDepA:
      return "MSG_SSR_GRIDDED_CORRECTION_DEP_A";
    case SbpMsgSsrGriddedCorrectionNoStdDepA:
      return "MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A";
    case SbpMsgSsrGriddedCorrection:
      return "MSG_SSR_GRIDDED_CORRECTION";
    case SbpMsgSsrOrbitClockBoundsDegradation:
      return "MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION";
    case SbpMsgSsrOrbitClockBounds:
      return "MSG_SSR_ORBIT_CLOCK_BOUNDS";
    case SbpMsgSsrOrbitClockDepA:
      return "MSG_SSR_ORBIT_CLOCK_DEP_A";
    case SbpMsgSsrOrbitClock:
      return "MSG_SSR_ORBIT_CLOCK";
    case SbpMsgSsrPhaseBiases:
      return "MSG_SSR_PHASE_BIASES";
    case SbpMsgSsrSatelliteApcDep:
      return "MSG_SSR_SATELLITE_APC_DEP";
    case SbpMsgSsrSatelliteApc:
      return "MSG_SSR_SATELLITE_APC";
    case SbpMsgSsrStecCorrectionDepA:
      return "MSG_SSR_STEC_CORRECTION_DEP_A";
    case SbpMsgSsrStecCorrectionDep:
      return "MSG_SSR_STEC_CORRECTION_DEP";
    case SbpMsgSsrStecCorrection:
      return "MSG_SSR_STEC_CORRECTION";
    case SbpMsgSsrTileDefinitionDepA:
      return "MSG_SSR_TILE_DEFINITION_DEP_A";
    case SbpMsgSsrTileDefinitionDepB:
      return "MSG_SSR_TILE_DEFINITION_DEP_B";
    case SbpMsgSsrTileDefinition:
      return "MSG_SSR_TILE_DEFINITION";
    case SbpMsgStartup:
      return "MSG_STARTUP";
    case SbpMsgStatusJournal:
      return "MSG_STATUS_JOURNAL";
    case SbpMsgStatusReport:
      return "MSG_STATUS_REPORT";
    case SbpMsgStmFlashLockSector:
      return "MSG_STM_FLASH_LOCK_SECTOR";
    case SbpMsgStmFlashUnlockSector:
      return "MSG_STM_FLASH_UNLOCK_SECTOR";
    case SbpMsgStmUniqueIdReq:
      return "MSG_STM_UNIQUE_ID_REQ";
    case SbpMsgStmUniqueIdResp:
      return "MSG_STM_UNIQUE_ID_RESP";
    case SbpMsgSvAzEl:
      return "MSG_SV_AZ_EL";
    case SbpMsgSvConfigurationGpsDep:
      return "MSG_SV_CONFIGURATION_GPS_DEP";
    case SbpMsgTelSv:
      return "MSG_TEL_SV";
    case SbpMsgThreadState:
      return "MSG_THREAD_STATE";
    case SbpMsgTrackingIqDepA:
      return "MSG_TRACKING_IQ_DEP_A";
    case SbpMsgTrackingIqDepB:
      return "MSG_TRACKING_IQ_DEP_B";
    case SbpMsgTrackingIq:
      return "MSG_TRACKING_IQ";
    case SbpMsgTrackingStateDepA:
      return "MSG_TRACKING_STATE_DEP_A";
    case SbpMsgTrackingStateDepB:
      return "MSG_TRACKING_STATE_DEP_B";
    case SbpMsgTrackingStateDetailedDepA:
      return "MSG_TRACKING_STATE_DETAILED_DEP_A";
    case SbpMsgTrackingStateDetailedDep:
      return "MSG_TRACKING_STATE_DETAILED_DEP";
    case SbpMsgTrackingState:
      return "MSG_TRACKING_STATE";
    case SbpMsgUartStateDepa:
      return "MSG_UART_STATE_DEPA";
    case SbpMsgUartState:
      return "MSG_UART_STATE";
    case SbpMsgUserData:
      return "MSG_USER_DATA";
    case SbpMsgUtcLeapSecond:
      return "MSG_UTC_LEAP_SECOND";
    case SbpMsgUtcTimeGnss:
      return "MSG_UTC_TIME_GNSS";
    case SbpMsgUtcTime:
      return "MSG_UTC_TIME";
    case SbpMsgVelBody:
      return "MSG_VEL_BODY";
    case SbpMsgVelCog:
      return "MSG_VEL_COG";
    case SbpMsgVelEcefCovGnss:
      return "MSG_VEL_ECEF_COV_GNSS";
    case SbpMsgVelEcefCov:
      return "MSG_VEL_ECEF_COV";
    case SbpMsgVelEcefDepA:
      return "MSG_VEL_ECEF_DEP_A";
    case SbpMsgVelEcefGnss:
      return "MSG_VEL_ECEF_GNSS";
    case SbpMsgVelEcef:
      return "MSG_VEL_ECEF";
    case SbpMsgVelNedCovGnss:
      return "MSG_VEL_NED_COV_GNSS";
    case SbpMsgVelNedCov:
      return "MSG_VEL_NED_COV";
    case SbpMsgVelNedDepA:
      return "MSG_VEL_NED_DEP_A";
    case SbpMsgVelNedGnss:
      return "MSG_VEL_NED_GNSS";
    case SbpMsgVelNed:
      return "MSG_VEL_NED";
    case SbpMsgWheeltick:
      return "MSG_WHEELTICK";
    case SbpMsgAll:
    default:
      return "(unknown)";
  }
}

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_SBP_MSG_TYPE_H */
