/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
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

/** SBP_MSG_ID to use to register frame callback for ALL messages. */
#define SBP_MSG_ALL 0

typedef enum {
  SbpMsgAcknowledge = SBP_MSG_ACKNOWLEDGE,
  SbpMsgAcqResultDepA = SBP_MSG_ACQ_RESULT_DEP_A,
  SbpMsgAcqResultDepB = SBP_MSG_ACQ_RESULT_DEP_B,
  SbpMsgAcqResultDepC = SBP_MSG_ACQ_RESULT_DEP_C,
  SbpMsgAcqResult = SBP_MSG_ACQ_RESULT,
  SbpMsgAcqSvProfileDep = SBP_MSG_ACQ_SV_PROFILE_DEP,
  SbpMsgAcqSvProfile = SBP_MSG_ACQ_SV_PROFILE,
  SbpMsgAgeCorrections = SBP_MSG_AGE_CORRECTIONS,
  SbpMsgAlmanacGloDep = SBP_MSG_ALMANAC_GLO_DEP,
  SbpMsgAlmanacGlo = SBP_MSG_ALMANAC_GLO,
  SbpMsgAlmanacGpsDep = SBP_MSG_ALMANAC_GPS_DEP,
  SbpMsgAlmanacGps = SBP_MSG_ALMANAC_GPS,
  SbpMsgAlmanac = SBP_MSG_ALMANAC,
  SbpMsgAngularRate = SBP_MSG_ANGULAR_RATE,
  SbpMsgBasePosEcef = SBP_MSG_BASE_POS_ECEF,
  SbpMsgBasePosLlh = SBP_MSG_BASE_POS_LLH,
  SbpMsgBaselineEcefDepA = SBP_MSG_BASELINE_ECEF_DEP_A,
  SbpMsgBaselineEcef = SBP_MSG_BASELINE_ECEF,
  SbpMsgBaselineHeadingDepA = SBP_MSG_BASELINE_HEADING_DEP_A,
  SbpMsgBaselineHeading = SBP_MSG_BASELINE_HEADING,
  SbpMsgBaselineNedDepA = SBP_MSG_BASELINE_NED_DEP_A,
  SbpMsgBaselineNed = SBP_MSG_BASELINE_NED,
  SbpMsgBootloaderHandshakeDepA = SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A,
  SbpMsgBootloaderHandshakeReq = SBP_MSG_BOOTLOADER_HANDSHAKE_REQ,
  SbpMsgBootloaderHandshakeResp = SBP_MSG_BOOTLOADER_HANDSHAKE_RESP,
  SbpMsgBootloaderJumpToApp = SBP_MSG_BOOTLOADER_JUMP_TO_APP,
  SbpMsgCellModemStatus = SBP_MSG_CELL_MODEM_STATUS,
  SbpMsgCertificateChainDep = SBP_MSG_CERTIFICATE_CHAIN_DEP,
  SbpMsgCertificateChain = SBP_MSG_CERTIFICATE_CHAIN,
  SbpMsgCommandOutput = SBP_MSG_COMMAND_OUTPUT,
  SbpMsgCommandReq = SBP_MSG_COMMAND_REQ,
  SbpMsgCommandResp = SBP_MSG_COMMAND_RESP,
  SbpMsgCsacTelemetryLabels = SBP_MSG_CSAC_TELEMETRY_LABELS,
  SbpMsgCsacTelemetry = SBP_MSG_CSAC_TELEMETRY,
  SbpMsgCwResults = SBP_MSG_CW_RESULTS,
  SbpMsgCwStart = SBP_MSG_CW_START,
  SbpMsgDeviceMonitor = SBP_MSG_DEVICE_MONITOR,
  SbpMsgDgnssStatus = SBP_MSG_DGNSS_STATUS,
  SbpMsgDopsDepA = SBP_MSG_DOPS_DEP_A,
  SbpMsgDops = SBP_MSG_DOPS,
  SbpMsgEcdsaCertificate = SBP_MSG_ECDSA_CERTIFICATE,
  SbpMsgEcdsaSignatureDepA = SBP_MSG_ECDSA_SIGNATURE_DEP_A,
  SbpMsgEcdsaSignatureDepB = SBP_MSG_ECDSA_SIGNATURE_DEP_B,
  SbpMsgEcdsaSignature = SBP_MSG_ECDSA_SIGNATURE,
  SbpMsgEd25519CertificateDep = SBP_MSG_ED25519_CERTIFICATE_DEP,
  SbpMsgEd25519SignatureDepA = SBP_MSG_ED25519_SIGNATURE_DEP_A,
  SbpMsgEd25519SignatureDepB = SBP_MSG_ED25519_SIGNATURE_DEP_B,
  SbpMsgEphemerisBds = SBP_MSG_EPHEMERIS_BDS,
  SbpMsgEphemerisDepA = SBP_MSG_EPHEMERIS_DEP_A,
  SbpMsgEphemerisDepB = SBP_MSG_EPHEMERIS_DEP_B,
  SbpMsgEphemerisDepC = SBP_MSG_EPHEMERIS_DEP_C,
  SbpMsgEphemerisDepD = SBP_MSG_EPHEMERIS_DEP_D,
  SbpMsgEphemerisGalDepA = SBP_MSG_EPHEMERIS_GAL_DEP_A,
  SbpMsgEphemerisGal = SBP_MSG_EPHEMERIS_GAL,
  SbpMsgEphemerisGloDepA = SBP_MSG_EPHEMERIS_GLO_DEP_A,
  SbpMsgEphemerisGloDepB = SBP_MSG_EPHEMERIS_GLO_DEP_B,
  SbpMsgEphemerisGloDepC = SBP_MSG_EPHEMERIS_GLO_DEP_C,
  SbpMsgEphemerisGloDepD = SBP_MSG_EPHEMERIS_GLO_DEP_D,
  SbpMsgEphemerisGlo = SBP_MSG_EPHEMERIS_GLO,
  SbpMsgEphemerisGpsDepE = SBP_MSG_EPHEMERIS_GPS_DEP_E,
  SbpMsgEphemerisGpsDepF = SBP_MSG_EPHEMERIS_GPS_DEP_F,
  SbpMsgEphemerisGps = SBP_MSG_EPHEMERIS_GPS,
  SbpMsgEphemerisQzss = SBP_MSG_EPHEMERIS_QZSS,
  SbpMsgEphemerisSbasDepA = SBP_MSG_EPHEMERIS_SBAS_DEP_A,
  SbpMsgEphemerisSbasDepB = SBP_MSG_EPHEMERIS_SBAS_DEP_B,
  SbpMsgEphemerisSbas = SBP_MSG_EPHEMERIS_SBAS,
  SbpMsgExtEvent = SBP_MSG_EXT_EVENT,
  SbpMsgFileioConfigReq = SBP_MSG_FILEIO_CONFIG_REQ,
  SbpMsgFileioConfigResp = SBP_MSG_FILEIO_CONFIG_RESP,
  SbpMsgFileioReadDirReq = SBP_MSG_FILEIO_READ_DIR_REQ,
  SbpMsgFileioReadDirResp = SBP_MSG_FILEIO_READ_DIR_RESP,
  SbpMsgFileioReadReq = SBP_MSG_FILEIO_READ_REQ,
  SbpMsgFileioReadResp = SBP_MSG_FILEIO_READ_RESP,
  SbpMsgFileioRemove = SBP_MSG_FILEIO_REMOVE,
  SbpMsgFileioWriteReq = SBP_MSG_FILEIO_WRITE_REQ,
  SbpMsgFileioWriteResp = SBP_MSG_FILEIO_WRITE_RESP,
  SbpMsgFlashDone = SBP_MSG_FLASH_DONE,
  SbpMsgFlashErase = SBP_MSG_FLASH_ERASE,
  SbpMsgFlashProgram = SBP_MSG_FLASH_PROGRAM,
  SbpMsgFlashReadReq = SBP_MSG_FLASH_READ_REQ,
  SbpMsgFlashReadResp = SBP_MSG_FLASH_READ_RESP,
  SbpMsgFrontEndGain = SBP_MSG_FRONT_END_GAIN,
  SbpMsgFwd = SBP_MSG_FWD,
  SbpMsgGloBiases = SBP_MSG_GLO_BIASES,
  SbpMsgGnssCapb = SBP_MSG_GNSS_CAPB,
  SbpMsgGnssTimeOffset = SBP_MSG_GNSS_TIME_OFFSET,
  SbpMsgGpsTimeDepA = SBP_MSG_GPS_TIME_DEP_A,
  SbpMsgGpsTimeGnss = SBP_MSG_GPS_TIME_GNSS,
  SbpMsgGpsTime = SBP_MSG_GPS_TIME,
  SbpMsgGroupDelayDepA = SBP_MSG_GROUP_DELAY_DEP_A,
  SbpMsgGroupDelayDepB = SBP_MSG_GROUP_DELAY_DEP_B,
  SbpMsgGroupDelay = SBP_MSG_GROUP_DELAY,
  SbpMsgGroupMeta = SBP_MSG_GROUP_META,
  SbpMsgHeartbeat = SBP_MSG_HEARTBEAT,
  SbpMsgIarState = SBP_MSG_IAR_STATE,
  SbpMsgImuAux = SBP_MSG_IMU_AUX,
  SbpMsgImuRaw = SBP_MSG_IMU_RAW,
  SbpMsgInitBaseDep = SBP_MSG_INIT_BASE_DEP,
  SbpMsgInsStatus = SBP_MSG_INS_STATUS,
  SbpMsgInsUpdates = SBP_MSG_INS_UPDATES,
  SbpMsgIono = SBP_MSG_IONO,
  SbpMsgLinuxCpuStateDepA = SBP_MSG_LINUX_CPU_STATE_DEP_A,
  SbpMsgLinuxCpuState = SBP_MSG_LINUX_CPU_STATE,
  SbpMsgLinuxMemStateDepA = SBP_MSG_LINUX_MEM_STATE_DEP_A,
  SbpMsgLinuxMemState = SBP_MSG_LINUX_MEM_STATE,
  SbpMsgLinuxProcessFdCount = SBP_MSG_LINUX_PROCESS_FD_COUNT,
  SbpMsgLinuxProcessFdSummary = SBP_MSG_LINUX_PROCESS_FD_SUMMARY,
  SbpMsgLinuxProcessSocketCounts = SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS,
  SbpMsgLinuxProcessSocketQueues = SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES,
  SbpMsgLinuxSocketUsage = SBP_MSG_LINUX_SOCKET_USAGE,
  SbpMsgLinuxSysStateDepA = SBP_MSG_LINUX_SYS_STATE_DEP_A,
  SbpMsgLinuxSysState = SBP_MSG_LINUX_SYS_STATE,
  SbpMsgLog = SBP_MSG_LOG,
  SbpMsgM25FlashWriteStatus = SBP_MSG_M25_FLASH_WRITE_STATUS,
  SbpMsgMagRaw = SBP_MSG_MAG_RAW,
  SbpMsgMaskSatelliteDep = SBP_MSG_MASK_SATELLITE_DEP,
  SbpMsgMaskSatellite = SBP_MSG_MASK_SATELLITE,
  SbpMsgMeasurementPoint = SBP_MSG_MEASUREMENT_POINT,
  SbpMsgMeasurementState = SBP_MSG_MEASUREMENT_STATE,
  SbpMsgNapDeviceDnaReq = SBP_MSG_NAP_DEVICE_DNA_REQ,
  SbpMsgNapDeviceDnaResp = SBP_MSG_NAP_DEVICE_DNA_RESP,
  SbpMsgNdbEvent = SBP_MSG_NDB_EVENT,
  SbpMsgNetworkBandwidthUsage = SBP_MSG_NETWORK_BANDWIDTH_USAGE,
  SbpMsgNetworkStateReq = SBP_MSG_NETWORK_STATE_REQ,
  SbpMsgNetworkStateResp = SBP_MSG_NETWORK_STATE_RESP,
  SbpMsgObsDepA = SBP_MSG_OBS_DEP_A,
  SbpMsgObsDepB = SBP_MSG_OBS_DEP_B,
  SbpMsgObsDepC = SBP_MSG_OBS_DEP_C,
  SbpMsgObs = SBP_MSG_OBS,
  SbpMsgOdometry = SBP_MSG_ODOMETRY,
  SbpMsgOrientEuler = SBP_MSG_ORIENT_EULER,
  SbpMsgOrientQuat = SBP_MSG_ORIENT_QUAT,
  SbpMsgOsr = SBP_MSG_OSR,
  SbpMsgPosEcefCovGnss = SBP_MSG_POS_ECEF_COV_GNSS,
  SbpMsgPosEcefCov = SBP_MSG_POS_ECEF_COV,
  SbpMsgPosEcefDepA = SBP_MSG_POS_ECEF_DEP_A,
  SbpMsgPosEcefGnss = SBP_MSG_POS_ECEF_GNSS,
  SbpMsgPosEcef = SBP_MSG_POS_ECEF,
  SbpMsgPosLlhAcc = SBP_MSG_POS_LLH_ACC,
  SbpMsgPosLlhCovGnss = SBP_MSG_POS_LLH_COV_GNSS,
  SbpMsgPosLlhCov = SBP_MSG_POS_LLH_COV,
  SbpMsgPosLlhDepA = SBP_MSG_POS_LLH_DEP_A,
  SbpMsgPosLlhGnss = SBP_MSG_POS_LLH_GNSS,
  SbpMsgPosLlh = SBP_MSG_POS_LLH,
  SbpMsgPoseRelative = SBP_MSG_POSE_RELATIVE,
  SbpMsgPpsTime = SBP_MSG_PPS_TIME,
  SbpMsgPrintDep = SBP_MSG_PRINT_DEP,
  SbpMsgProfilingResourceCounter = SBP_MSG_PROFILING_RESOURCE_COUNTER,
  SbpMsgProfilingSystemInfo = SBP_MSG_PROFILING_SYSTEM_INFO,
  SbpMsgProfilingThreadInfo = SBP_MSG_PROFILING_THREAD_INFO,
  SbpMsgProtectionLevelDepA = SBP_MSG_PROTECTION_LEVEL_DEP_A,
  SbpMsgProtectionLevel = SBP_MSG_PROTECTION_LEVEL,
  SbpMsgReferenceFrameParam = SBP_MSG_REFERENCE_FRAME_PARAM,
  SbpMsgResetDep = SBP_MSG_RESET_DEP,
  SbpMsgResetFilters = SBP_MSG_RESET_FILTERS,
  SbpMsgReset = SBP_MSG_RESET,
  SbpMsgSbasRaw = SBP_MSG_SBAS_RAW,
  SbpMsgSensorAidEvent = SBP_MSG_SENSOR_AID_EVENT,
  SbpMsgSetTime = SBP_MSG_SET_TIME,
  SbpMsgSettingsReadByIndexDone = SBP_MSG_SETTINGS_READ_BY_INDEX_DONE,
  SbpMsgSettingsReadByIndexReq = SBP_MSG_SETTINGS_READ_BY_INDEX_REQ,
  SbpMsgSettingsReadByIndexResp = SBP_MSG_SETTINGS_READ_BY_INDEX_RESP,
  SbpMsgSettingsReadReq = SBP_MSG_SETTINGS_READ_REQ,
  SbpMsgSettingsReadResp = SBP_MSG_SETTINGS_READ_RESP,
  SbpMsgSettingsRegisterResp = SBP_MSG_SETTINGS_REGISTER_RESP,
  SbpMsgSettingsRegister = SBP_MSG_SETTINGS_REGISTER,
  SbpMsgSettingsSave = SBP_MSG_SETTINGS_SAVE,
  SbpMsgSettingsWriteResp = SBP_MSG_SETTINGS_WRITE_RESP,
  SbpMsgSettingsWrite = SBP_MSG_SETTINGS_WRITE,
  SbpMsgSolnMetaDepA = SBP_MSG_SOLN_META_DEP_A,
  SbpMsgSolnMeta = SBP_MSG_SOLN_META,
  SbpMsgSpecanDep = SBP_MSG_SPECAN_DEP,
  SbpMsgSpecan = SBP_MSG_SPECAN,
  SbpMsgSsrCodeBiases = SBP_MSG_SSR_CODE_BIASES,
  SbpMsgSsrCodePhaseBiasesBounds = SBP_MSG_SSR_CODE_PHASE_BIASES_BOUNDS,
  SbpMsgSsrFlagHighLevel = SBP_MSG_SSR_FLAG_HIGH_LEVEL,
  SbpMsgSsrFlagIonoGridPointSatLos = SBP_MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS,
  SbpMsgSsrFlagIonoGridPoints = SBP_MSG_SSR_FLAG_IONO_GRID_POINTS,
  SbpMsgSsrFlagIonoTileSatLos = SBP_MSG_SSR_FLAG_IONO_TILE_SAT_LOS,
  SbpMsgSsrFlagSatellites = SBP_MSG_SSR_FLAG_SATELLITES,
  SbpMsgSsrFlagTropoGridPoints = SBP_MSG_SSR_FLAG_TROPO_GRID_POINTS,
  SbpMsgSsrGridDefinitionDepA = SBP_MSG_SSR_GRID_DEFINITION_DEP_A,
  SbpMsgSsrGriddedCorrectionBounds = SBP_MSG_SSR_GRIDDED_CORRECTION_BOUNDS,
  SbpMsgSsrGriddedCorrectionDepA = SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A,
  SbpMsgSsrGriddedCorrectionNoStdDepA =
      SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A,
  SbpMsgSsrGriddedCorrection = SBP_MSG_SSR_GRIDDED_CORRECTION,
  SbpMsgSsrOrbitClockBoundsDegradation =
      SBP_MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION,
  SbpMsgSsrOrbitClockBounds = SBP_MSG_SSR_ORBIT_CLOCK_BOUNDS,
  SbpMsgSsrOrbitClockDepA = SBP_MSG_SSR_ORBIT_CLOCK_DEP_A,
  SbpMsgSsrOrbitClock = SBP_MSG_SSR_ORBIT_CLOCK,
  SbpMsgSsrPhaseBiases = SBP_MSG_SSR_PHASE_BIASES,
  SbpMsgSsrSatelliteApcDep = SBP_MSG_SSR_SATELLITE_APC_DEP,
  SbpMsgSsrSatelliteApc = SBP_MSG_SSR_SATELLITE_APC,
  SbpMsgSsrStecCorrectionDepA = SBP_MSG_SSR_STEC_CORRECTION_DEP_A,
  SbpMsgSsrStecCorrectionDep = SBP_MSG_SSR_STEC_CORRECTION_DEP,
  SbpMsgSsrStecCorrection = SBP_MSG_SSR_STEC_CORRECTION,
  SbpMsgSsrTileDefinitionDepA = SBP_MSG_SSR_TILE_DEFINITION_DEP_A,
  SbpMsgSsrTileDefinitionDepB = SBP_MSG_SSR_TILE_DEFINITION_DEP_B,
  SbpMsgSsrTileDefinition = SBP_MSG_SSR_TILE_DEFINITION,
  SbpMsgStartup = SBP_MSG_STARTUP,
  SbpMsgStatusJournal = SBP_MSG_STATUS_JOURNAL,
  SbpMsgStatusReport = SBP_MSG_STATUS_REPORT,
  SbpMsgStmFlashLockSector = SBP_MSG_STM_FLASH_LOCK_SECTOR,
  SbpMsgStmFlashUnlockSector = SBP_MSG_STM_FLASH_UNLOCK_SECTOR,
  SbpMsgStmUniqueIdReq = SBP_MSG_STM_UNIQUE_ID_REQ,
  SbpMsgStmUniqueIdResp = SBP_MSG_STM_UNIQUE_ID_RESP,
  SbpMsgSvAzEl = SBP_MSG_SV_AZ_EL,
  SbpMsgSvConfigurationGpsDep = SBP_MSG_SV_CONFIGURATION_GPS_DEP,
  SbpMsgTelSv = SBP_MSG_TEL_SV,
  SbpMsgThreadState = SBP_MSG_THREAD_STATE,
  SbpMsgTrackingIqDepA = SBP_MSG_TRACKING_IQ_DEP_A,
  SbpMsgTrackingIqDepB = SBP_MSG_TRACKING_IQ_DEP_B,
  SbpMsgTrackingIq = SBP_MSG_TRACKING_IQ,
  SbpMsgTrackingStateDepA = SBP_MSG_TRACKING_STATE_DEP_A,
  SbpMsgTrackingStateDepB = SBP_MSG_TRACKING_STATE_DEP_B,
  SbpMsgTrackingStateDetailedDepA = SBP_MSG_TRACKING_STATE_DETAILED_DEP_A,
  SbpMsgTrackingStateDetailedDep = SBP_MSG_TRACKING_STATE_DETAILED_DEP,
  SbpMsgTrackingState = SBP_MSG_TRACKING_STATE,
  SbpMsgUartStateDepa = SBP_MSG_UART_STATE_DEPA,
  SbpMsgUartState = SBP_MSG_UART_STATE,
  SbpMsgUserData = SBP_MSG_USER_DATA,
  SbpMsgUtcLeapSecond = SBP_MSG_UTC_LEAP_SECOND,
  SbpMsgUtcTimeGnss = SBP_MSG_UTC_TIME_GNSS,
  SbpMsgUtcTime = SBP_MSG_UTC_TIME,
  SbpMsgVelBody = SBP_MSG_VEL_BODY,
  SbpMsgVelCog = SBP_MSG_VEL_COG,
  SbpMsgVelEcefCovGnss = SBP_MSG_VEL_ECEF_COV_GNSS,
  SbpMsgVelEcefCov = SBP_MSG_VEL_ECEF_COV,
  SbpMsgVelEcefDepA = SBP_MSG_VEL_ECEF_DEP_A,
  SbpMsgVelEcefGnss = SBP_MSG_VEL_ECEF_GNSS,
  SbpMsgVelEcef = SBP_MSG_VEL_ECEF,
  SbpMsgVelNedCovGnss = SBP_MSG_VEL_NED_COV_GNSS,
  SbpMsgVelNedCov = SBP_MSG_VEL_NED_COV,
  SbpMsgVelNedDepA = SBP_MSG_VEL_NED_DEP_A,
  SbpMsgVelNedGnss = SBP_MSG_VEL_NED_GNSS,
  SbpMsgVelNed = SBP_MSG_VEL_NED,
  SbpMsgWheeltick = SBP_MSG_WHEELTICK,
  SbpMsgAll = SBP_MSG_ALL,
  SbpMsgUnknown = SBP_MSG_ALL,
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
