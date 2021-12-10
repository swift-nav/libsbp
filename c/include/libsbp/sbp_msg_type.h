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
#include <libsbp/linux_macros.h>
#include <libsbp/logging_macros.h>
#include <libsbp/mag_macros.h>
#include <libsbp/navigation_macros.h>
#include <libsbp/ndb_macros.h>
#include <libsbp/observation_macros.h>
#include <libsbp/orientation_macros.h>
#include <libsbp/piksi_macros.h>
#include <libsbp/sbas_macros.h>
#include <libsbp/settings_macros.h>
#include <libsbp/solution_meta_macros.h>
#include <libsbp/ssr_macros.h>
#include <libsbp/system_macros.h>
#include <libsbp/tracking_macros.h>
#include <libsbp/user_macros.h>
#include <libsbp/vehicle_macros.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
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
  SbpMsgPpsTime = SBP_MSG_PPS_TIME,
  SbpMsgPrintDep = SBP_MSG_PRINT_DEP,
  SbpMsgProtectionLevelDepA = SBP_MSG_PROTECTION_LEVEL_DEP_A,
  SbpMsgProtectionLevel = SBP_MSG_PROTECTION_LEVEL,
  SbpMsgResetDep = SBP_MSG_RESET_DEP,
  SbpMsgResetFilters = SBP_MSG_RESET_FILTERS,
  SbpMsgReset = SBP_MSG_RESET,
  SbpMsgSbasRaw = SBP_MSG_SBAS_RAW,
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
  SbpMsgSsrGridDefinitionDepA = SBP_MSG_SSR_GRID_DEFINITION_DEP_A,
  SbpMsgSsrGriddedCorrectionDepA = SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A,
  SbpMsgSsrGriddedCorrectionNoStdDepA =
      SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A,
  SbpMsgSsrGriddedCorrection = SBP_MSG_SSR_GRIDDED_CORRECTION,
  SbpMsgSsrOrbitClockDepA = SBP_MSG_SSR_ORBIT_CLOCK_DEP_A,
  SbpMsgSsrOrbitClock = SBP_MSG_SSR_ORBIT_CLOCK,
  SbpMsgSsrPhaseBiases = SBP_MSG_SSR_PHASE_BIASES,
  SbpMsgSsrSatelliteApc = SBP_MSG_SSR_SATELLITE_APC,
  SbpMsgSsrStecCorrectionDepA = SBP_MSG_SSR_STEC_CORRECTION_DEP_A,
  SbpMsgSsrStecCorrection = SBP_MSG_SSR_STEC_CORRECTION,
  SbpMsgSsrTileDefinition = SBP_MSG_SSR_TILE_DEFINITION,
  SbpMsgStartup = SBP_MSG_STARTUP,
  SbpMsgStatusReport = SBP_MSG_STATUS_REPORT,
  SbpMsgStmFlashLockSector = SBP_MSG_STM_FLASH_LOCK_SECTOR,
  SbpMsgStmFlashUnlockSector = SBP_MSG_STM_FLASH_UNLOCK_SECTOR,
  SbpMsgStmUniqueIdReq = SBP_MSG_STM_UNIQUE_ID_REQ,
  SbpMsgStmUniqueIdResp = SBP_MSG_STM_UNIQUE_ID_RESP,
  SbpMsgSvAzEl = SBP_MSG_SV_AZ_EL,
  SbpMsgSvConfigurationGpsDep = SBP_MSG_SV_CONFIGURATION_GPS_DEP,
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
} sbp_msg_type_t;

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_SBP_MSG_TYPE_H */
