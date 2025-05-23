/*
 * Copyright (C) 2011-2021 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated by generate.py. Do not modify by hand!

#include <check.h>
#include <stdlib.h>

#include "check_suites.h"

int main(void) {
  int number_failed;
  Suite *s = edc_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_xml(sr, "test_results.xml");
  srunner_add_suite(sr, sbp_suite());
  srunner_add_suite(sr, bitfield_macros_suite());

  // auto-generated tests:
  srunner_add_suite(sr, auto_check_sbp_acquisition_MsgAcqResult_suite());
  srunner_add_suite(sr, auto_check_sbp_acquisition_MsgAcqResultDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_acquisition_MsgAcqResultDepB_suite());
  srunner_add_suite(sr, auto_check_sbp_acquisition_MsgAcqResultDepC_suite());
  srunner_add_suite(sr, auto_check_sbp_acquisition_MsgAcqSvProfile_suite());
  srunner_add_suite(sr, auto_check_sbp_acquisition_MsgAcqSvProfileDep_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_bootload_MsgBootloaderHandshakeReq_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_bootload_MsgBootloaderHandshakeResp_suite());
  srunner_add_suite(sr, auto_check_sbp_bootload_MsgBootloaderJumptoApp_suite());
  srunner_add_suite(sr, auto_check_sbp_bootload_MsgNapDeviceDnaReq_suite());
  srunner_add_suite(sr, auto_check_sbp_bootload_MsgNapDeviceDnaResp_suite());
  srunner_add_suite(sr, auto_check_sbp_ext_events_MsgExtEvent_suite());
  srunner_add_suite(sr, auto_check_sbp_file_io_MsgFileioConfigReq_suite());
  srunner_add_suite(sr, auto_check_sbp_file_io_MsgFileioConfigResp_suite());
  srunner_add_suite(sr, auto_check_sbp_file_io_MsgFileioReadDirReq_suite());
  srunner_add_suite(sr, auto_check_sbp_file_io_MsgFileioReadDirResp_suite());
  srunner_add_suite(sr, auto_check_sbp_file_io_MsgFileioReadReq_suite());
  srunner_add_suite(sr, auto_check_sbp_file_io_MsgFileioReadResp_suite());
  srunner_add_suite(sr, auto_check_sbp_file_io_MsgFileioRemove_suite());
  srunner_add_suite(sr, auto_check_sbp_file_io_MsgFileioWriteResp_suite());
  srunner_add_suite(sr, auto_check_sbp_flash_MsgFlashDone_suite());
  srunner_add_suite(sr, auto_check_sbp_flash_MsgFlashErase_suite());
  srunner_add_suite(sr, auto_check_sbp_flash_MsgFlashProgram_suite());
  srunner_add_suite(sr, auto_check_sbp_flash_MsgFlashReadReq_suite());
  srunner_add_suite(sr, auto_check_sbp_flash_MsgFlashReadResp_suite());
  srunner_add_suite(sr, auto_check_sbp_flash_MsgM25FlashWriteStatus_suite());
  srunner_add_suite(sr, auto_check_sbp_flash_MsgStmFlashLockSector_suite());
  srunner_add_suite(sr, auto_check_sbp_flash_MsgStmFlashUnlockSector_suite());
  srunner_add_suite(sr, auto_check_sbp_flash_MsgStmUniqueIdReq_suite());
  srunner_add_suite(sr, auto_check_sbp_flash_MsgStmUniqueIdResp_suite());
  srunner_add_suite(sr, auto_check_sbp_imu_MsgImuAux_suite());
  srunner_add_suite(sr, auto_check_sbp_imu_MsgImuComp_suite());
  srunner_add_suite(sr, auto_check_sbp_imu_MsgImuRaw_suite());
  srunner_add_suite(sr, auto_check_sbp_integrity_MsgAcknowledge_suite());
  srunner_add_suite(sr, auto_check_sbp_integrity_MsgSsrFlagHighLevel_suite());
  srunner_add_suite(
      sr, auto_check_sbp_integrity_MsgSsrFlagIonoGridPointSatLos_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_integrity_MsgSsrFlagIonoGridPoints_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_integrity_MsgSsrFlagIonoTileSatLos_suite());
  srunner_add_suite(sr, auto_check_sbp_integrity_MsgSsrFlagSatellites_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_integrity_MsgSsrFlagTropoGridPoints_suite());
  srunner_add_suite(sr, auto_check_sbp_linux_MsgLinuxCpuState_suite());
  srunner_add_suite(sr, auto_check_sbp_linux_MsgLinuxCpuStateDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_linux_MsgLinuxMemState_suite());
  srunner_add_suite(sr, auto_check_sbp_linux_MsgLinuxMemStateDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_linux_MsgLinuxProcessFdCount_suite());
  srunner_add_suite(sr, auto_check_sbp_linux_MsgLinuxProcessFdSummary_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_linux_MsgLinuxProcessSocketCounts_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_linux_MsgLinuxProcessSocketQueues_suite());
  srunner_add_suite(sr, auto_check_sbp_linux_MsgLinuxSocketUsage_suite());
  srunner_add_suite(sr, auto_check_sbp_linux_MsgLinuxSysState_suite());
  srunner_add_suite(sr, auto_check_sbp_linux_MsgLinuxSysStateDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_logging_MsgFwd_suite());
  srunner_add_suite(sr, auto_check_sbp_logging_MsgLog_suite());
  srunner_add_suite(sr, auto_check_sbp_logging_MsgPrintDep_suite());
  srunner_add_suite(sr, auto_check_sbp_mag_MsgMagRaw_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgAgeCorrections_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgBaselineECEF_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgBaselineECEFDepA_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_navigation_MsgBaselineHeadingDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgBaselineNED_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgBaselineNEDDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgDops_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgDopsDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgGPSTime_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgGPSTimeDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgGPSTimeGNSS_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgPosECEF_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgPosECEFCov_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgPosECEFCovGNSS_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgPosECEFDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgPosECEFGNSS_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgPosLLH_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgPosLLHCov_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgPosLLHDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgPosLlhAcc_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgPosLlhCovGnss_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgPosLlhGnss_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgPoseRelative_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgProtectionLevel_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_navigation_MsgProtectionLevelDepA_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_navigation_MsgReferenceFrameParam_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgUTCLeapSecond_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgUTCTime_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgUTCTimeGNSS_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgVelBody_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgVelCog_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgVelECEF_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgVelECEFCov_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgVelECEFDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgVelEcefCovGnss_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgVelEcefGnss_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgVelNED_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgVelNEDCOV_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgVelNEDDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgVelNedCovGnss_suite());
  srunner_add_suite(sr, auto_check_sbp_navigation_MsgVelNedGnss_suite());
  srunner_add_suite(sr, auto_check_sbp_ndb_MsgNdbEvent_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgAlmanacGLO_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgAlmanacGLODep_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgAlmanacGPS_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgAlmanacGPSDep_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgBasePosEcef_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgBasePosLLH_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgEphemerisBds_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgEphemerisDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgEphemerisDepC_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgEphemerisDepD_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgEphemerisGLO_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgEphemerisGLODepA_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgEphemerisGLODepB_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgEphemerisGLODepC_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgEphemerisGLODepD_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgEphemerisGPS_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgEphemerisGPSDepE_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgEphemerisGPSDepF_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgEphemerisGal_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgEphemerisGalDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgEphemerisSbas_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_observation_MsgEphemerisSbasDepA_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_observation_MsgEphemerisSbasDepB_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgGloBiases_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgGnssCapb_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgGroupDelay_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgGroupDelayDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgGroupDelayDepB_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgIono_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgObs_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgObsDepB_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgObsDepC_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgOsr_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_MsgSvAzEl_suite());
  srunner_add_suite(
      sr, auto_check_sbp_observation_MsgSvConfigurationGpsDep_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_msgEphemerisDepB_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_msgEphemerisQzss_suite());
  srunner_add_suite(sr, auto_check_sbp_observation_msgObsDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_orientation_MsgAngularRate_suite());
  srunner_add_suite(sr, auto_check_sbp_orientation_MsgBaselineHeading_suite());
  srunner_add_suite(sr, auto_check_sbp_orientation_MsgOrientEuler_suite());
  srunner_add_suite(sr, auto_check_sbp_orientation_MsgOrientQuat_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgAlmanac_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgCellModemStatus_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgCommandOutput_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgCommandReq_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgCommandResp_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgCwResults_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgCwStart_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgDeviceMonitor_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgFrontEndGain_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgIarState_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgInitBaseDep_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgMaskSatellite_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgMaskSatelliteDep_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgNetworkBandwidthUsage_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgNetworkStateReq_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgNetworkStateResp_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgReset_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgResetDep_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgResetFilters_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgSetTime_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgSpecan_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgSpecanDep_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgThreadState_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgUartState_suite());
  srunner_add_suite(sr, auto_check_sbp_piksi_MsgUartStateDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_profiling_MsgMeasurementPoint_suite());
  srunner_add_suite(
      sr, auto_check_sbp_profiling_MsgProfilingResourceCounter_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_profiling_MsgProfilingSystemInfo_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_profiling_MsgProfilingThreadInfo_suite());
  srunner_add_suite(sr, auto_check_sbp_sbas_MsgSbasRaw_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_settings_MsgSettingsReadByIndexDone_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_settings_MsgSettingsReadByIndexReq_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_settings_MsgSettingsReadByIndexResp_suite());
  srunner_add_suite(sr, auto_check_sbp_settings_MsgSettingsReadReq_suite());
  srunner_add_suite(sr, auto_check_sbp_settings_MsgSettingsReadResp_suite());
  srunner_add_suite(sr, auto_check_sbp_settings_MsgSettingsRegister_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_settings_MsgSettingsRegisterResp_suite());
  srunner_add_suite(sr, auto_check_sbp_settings_MsgSettingsSave_suite());
  srunner_add_suite(sr, auto_check_sbp_settings_MsgSettingsWrite_suite());
  srunner_add_suite(sr, auto_check_sbp_settings_MsgSettingsWriteResp_suite());
  srunner_add_suite(sr, auto_check_sbp_signing_MsgAesCmacSignature_suite());
  srunner_add_suite(sr, auto_check_sbp_signing_MsgCertificateChain_suite());
  srunner_add_suite(sr, auto_check_sbp_signing_MsgCertificateChainDep_suite());
  srunner_add_suite(sr, auto_check_sbp_signing_MsgEcdsaCertificate_suite());
  srunner_add_suite(sr, auto_check_sbp_signing_MsgEcdsaSignature_suite());
  srunner_add_suite(sr, auto_check_sbp_signing_MsgEcdsaSignatureDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_signing_MsgEcdsaSignatureDepB_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_signing_MsgEd25519CertificateDep_suite());
  srunner_add_suite(sr, auto_check_sbp_signing_MsgEd25519SignatureDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_signing_MsgEd25519SignatureDepB_suite());
  srunner_add_suite(sr, auto_check_sbp_solution_meta_MsgSolnMeta_suite());
  srunner_add_suite(sr, auto_check_sbp_solution_meta_MsgSolnMetaDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrCodeBiases_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrCodePhaseBiasesBounds_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrGridDefinitionDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrGriddedCorrection_suite());
  srunner_add_suite(sr,
                    auto_check_sbp_ssr_MsgSsrGriddedCorrectionBounds_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA_suite());
  srunner_add_suite(
      sr, auto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrOrbitClock_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrOrbitClockBounds_suite());
  srunner_add_suite(
      sr, auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradation_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrOrbitClockDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrPhaseBiases_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrSatelliteApc_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrSatelliteApcDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrStecCorrection_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrStecCorrectionDep_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrStecCorrectionDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrTileDefinition_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrTileDefinitionDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_ssr_MsgSsrTileDefinitionDepB_suite());
  srunner_add_suite(sr, auto_check_sbp_system_MsgCsacTelemetry_suite());
  srunner_add_suite(sr, auto_check_sbp_system_MsgCsacTelemetryLabels_suite());
  srunner_add_suite(sr, auto_check_sbp_system_MsgDgnssStatus_suite());
  srunner_add_suite(sr, auto_check_sbp_system_MsgGnssTimeOffset_suite());
  srunner_add_suite(sr, auto_check_sbp_system_MsgGroupMeta_suite());
  srunner_add_suite(sr, auto_check_sbp_system_MsgHeartbeat_suite());
  srunner_add_suite(sr, auto_check_sbp_system_MsgInsStatus_suite());
  srunner_add_suite(sr, auto_check_sbp_system_MsgInsUpdates_suite());
  srunner_add_suite(sr, auto_check_sbp_system_MsgPpsTime_suite());
  srunner_add_suite(sr, auto_check_sbp_system_MsgSensorAidEvent_suite());
  srunner_add_suite(sr, auto_check_sbp_system_MsgStartup_suite());
  srunner_add_suite(sr, auto_check_sbp_system_MsgStatusJournal_suite());
  srunner_add_suite(sr, auto_check_sbp_system_MsgStatusReport_suite());
  srunner_add_suite(sr, auto_check_sbp_telemetry_MsgTelSv_suite());
  srunner_add_suite(sr, auto_check_sbp_tracking_MsgMeasurementState_suite());
  srunner_add_suite(sr, auto_check_sbp_tracking_MsgTrackingIq_suite());
  srunner_add_suite(sr, auto_check_sbp_tracking_MsgTrackingIqDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_tracking_MsgTrackingIqDepB_suite());
  srunner_add_suite(sr, auto_check_sbp_tracking_MsgTrackingState_suite());
  srunner_add_suite(sr, auto_check_sbp_tracking_MsgTrackingStateDepB_suite());
  srunner_add_suite(
      sr, auto_check_sbp_tracking_MsgTrackingStateDetailedDep_suite());
  srunner_add_suite(
      sr, auto_check_sbp_tracking_MsgTrackingStateDetailedDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_tracking_MsgtrackingStateDepA_suite());
  srunner_add_suite(sr, auto_check_sbp_user_MsgUserData_suite());
  srunner_add_suite(sr, auto_check_sbp_vehicle_MsgOdometry_suite());
  srunner_add_suite(sr, auto_check_sbp_vehicle_MsgWheeltick_suite());

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
