//
// Copyright (C) 2019-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated. Do not modify by hand!
#![allow(non_snake_case)]
mod auto_check_sbp_acquisition_MsgAcqResultDepA;
mod auto_check_sbp_acquisition_MsgAcqResultDepB;
mod auto_check_sbp_acquisition_MsgAcqResultDepC;
mod auto_check_sbp_bootload_MsgBootloaderHandshakeResp;
mod auto_check_sbp_ext_events_MsgExtEvent;
mod auto_check_sbp_file_io_MsgFileioWriteResp;
mod auto_check_sbp_imu_MsgImuAux;
mod auto_check_sbp_imu_MsgImuRaw;
mod auto_check_sbp_logging_MsgFwd;
mod auto_check_sbp_logging_MsgLog;
mod auto_check_sbp_logging_MsgPrintDep;
mod auto_check_sbp_navigation_MsgAgeCorrections;
mod auto_check_sbp_navigation_MsgBaselineECEF;
mod auto_check_sbp_navigation_MsgBaselineECEFDepA;
mod auto_check_sbp_navigation_MsgBaselineNED;
mod auto_check_sbp_navigation_MsgBaselineNEDDepA;
mod auto_check_sbp_navigation_MsgDops;
mod auto_check_sbp_navigation_MsgDopsDepA;
mod auto_check_sbp_navigation_MsgGPSTime;
mod auto_check_sbp_navigation_MsgGPSTimeDepA;
mod auto_check_sbp_navigation_MsgGPSTimeGNSS;
mod auto_check_sbp_navigation_MsgPosECEF;
mod auto_check_sbp_navigation_MsgPosECEFCov;
mod auto_check_sbp_navigation_MsgPosECEFCovGNSS;
mod auto_check_sbp_navigation_MsgPosECEFDepA;
mod auto_check_sbp_navigation_MsgPosECEFGNSS;
mod auto_check_sbp_navigation_MsgPosLLH;
mod auto_check_sbp_navigation_MsgPosLLHCov;
mod auto_check_sbp_navigation_MsgPosLLHDepA;
mod auto_check_sbp_navigation_MsgPosLlhCovGnss;
mod auto_check_sbp_navigation_MsgPosLlhGnss;
mod auto_check_sbp_navigation_MsgProtectionLevel;
mod auto_check_sbp_navigation_MsgUTCTime;
mod auto_check_sbp_navigation_MsgUTCTimeGNSS;
mod auto_check_sbp_navigation_MsgVelBody;
mod auto_check_sbp_navigation_MsgVelECEF;
mod auto_check_sbp_navigation_MsgVelECEFCov;
mod auto_check_sbp_navigation_MsgVelECEFDepA;
mod auto_check_sbp_navigation_MsgVelEcefCovGnss;
mod auto_check_sbp_navigation_MsgVelEcefGnss;
mod auto_check_sbp_navigation_MsgVelNED;
mod auto_check_sbp_navigation_MsgVelNEDCOV;
mod auto_check_sbp_navigation_MsgVelNEDDepA;
mod auto_check_sbp_navigation_MsgVelNedCovGnss;
mod auto_check_sbp_navigation_MsgVelNedGnss;
mod auto_check_sbp_observation_MsgBasePosEcef;
mod auto_check_sbp_observation_MsgEphemerisBds;
mod auto_check_sbp_observation_MsgEphemerisGLO;
mod auto_check_sbp_observation_MsgEphemerisGPS;
mod auto_check_sbp_observation_MsgEphemerisGal;
mod auto_check_sbp_observation_MsgGloBiases;
mod auto_check_sbp_observation_MsgObs;
mod auto_check_sbp_observation_MsgObsDepB;
mod auto_check_sbp_observation_MsgObsDepC;
mod auto_check_sbp_observation_MsgOsr;
mod auto_check_sbp_observation_MsgSvAzEl;
mod auto_check_sbp_observation_msgEphemerisDepB;
mod auto_check_sbp_observation_msgEphemerisQzss;
mod auto_check_sbp_observation_msgObsDepA;
mod auto_check_sbp_orientation_MsgAngularRate;
mod auto_check_sbp_orientation_MsgOrientEuler;
mod auto_check_sbp_orientation_MsgOrientQuat;
mod auto_check_sbp_piksi_MsgDeviceMonitor;
mod auto_check_sbp_piksi_MsgIarState;
mod auto_check_sbp_piksi_MsgNetworkBandwidthUsage;
mod auto_check_sbp_piksi_MsgThreadState;
mod auto_check_sbp_piksi_MsgUartState;
mod auto_check_sbp_piksi_MsgUartStateDepA;
mod auto_check_sbp_sbas_MsgSbasRaw;
mod auto_check_sbp_settings_MsgSettingsReadByIndexDone;
mod auto_check_sbp_settings_MsgSettingsReadByIndexResp;
mod auto_check_sbp_system_MsgDgnssStatus;
mod auto_check_sbp_system_MsgGroupMeta;
mod auto_check_sbp_system_MsgHeartbeat;
mod auto_check_sbp_system_MsgInsStatus;
mod auto_check_sbp_system_MsgInsUpdates;
mod auto_check_sbp_system_MsgStartup;
mod auto_check_sbp_tracking_MsgMeasurementState;
mod auto_check_sbp_tracking_MsgTrackingState;
mod auto_check_sbp_tracking_MsgTrackingStateDetailedDep;
mod auto_check_sbp_tracking_MsgtrackingStateDepA;
mod auto_check_sbp_vehicle_MsgOdometry;

pub trait AlmostEq {
    fn almost_eq(self, rhs: Self) -> bool;
}

impl AlmostEq for f32 {
    fn almost_eq(self, rhs: Self) -> bool {
        const ULP: f32 = 5.0;
        ((self - rhs).abs() <= (std::f32::EPSILON * (self + rhs).abs() * ULP))
            || ((self - rhs).abs() < std::f32::MIN)
    }
}

impl AlmostEq for f64 {
    fn almost_eq(self, rhs: Self) -> bool {
        const ULP: f64 = 5.0;
        ((self - rhs).abs() <= (std::f64::EPSILON * (self + rhs).abs() * ULP))
            || ((self - rhs).abs() < std::f64::MIN)
    }
}
