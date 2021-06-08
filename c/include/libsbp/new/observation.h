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
 * Automatically generated from yaml/swiftnav/sbp/observation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_OBSERVATION_MESSAGES_H
#define LIBSBP_NEW_OBSERVATION_MESSAGES_H
#include <libsbp/new/observation/AlmanacCommonContent.h>
#include <libsbp/new/observation/AlmanacCommonContentDep.h>
#include <libsbp/new/observation/CarrierPhaseDepA.h>
#include <libsbp/new/observation/Doppler.h>
#include <libsbp/new/observation/EphemerisCommonContent.h>
#include <libsbp/new/observation/EphemerisCommonContentDepA.h>
#include <libsbp/new/observation/EphemerisCommonContentDepB.h>
#include <libsbp/new/observation/GnssCapb.h>
#include <libsbp/new/observation/MSG_ALMANAC_GLO.h>
#include <libsbp/new/observation/MSG_ALMANAC_GLO_DEP.h>
#include <libsbp/new/observation/MSG_ALMANAC_GPS.h>
#include <libsbp/new/observation/MSG_ALMANAC_GPS_DEP.h>
#include <libsbp/new/observation/MSG_BASE_POS_ECEF.h>
#include <libsbp/new/observation/MSG_BASE_POS_LLH.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_BDS.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_DEP_A.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_DEP_B.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_DEP_C.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_DEP_D.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_GAL.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_GAL_DEP_A.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_GLO.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_GLO_DEP_A.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_GLO_DEP_B.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_GLO_DEP_C.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_GLO_DEP_D.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_GPS.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_GPS_DEP_E.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_GPS_DEP_F.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_QZSS.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_SBAS.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_SBAS_DEP_A.h>
#include <libsbp/new/observation/MSG_EPHEMERIS_SBAS_DEP_B.h>
#include <libsbp/new/observation/MSG_GLO_BIASES.h>
#include <libsbp/new/observation/MSG_GNSS_CAPB.h>
#include <libsbp/new/observation/MSG_GROUP_DELAY.h>
#include <libsbp/new/observation/MSG_GROUP_DELAY_DEP_A.h>
#include <libsbp/new/observation/MSG_GROUP_DELAY_DEP_B.h>
#include <libsbp/new/observation/MSG_IONO.h>
#include <libsbp/new/observation/MSG_OBS.h>
#include <libsbp/new/observation/MSG_OBS_DEP_A.h>
#include <libsbp/new/observation/MSG_OBS_DEP_B.h>
#include <libsbp/new/observation/MSG_OBS_DEP_C.h>
#include <libsbp/new/observation/MSG_OSR.h>
#include <libsbp/new/observation/MSG_SV_AZ_EL.h>
#include <libsbp/new/observation/MSG_SV_CONFIGURATION_GPS_DEP.h>
#include <libsbp/new/observation/ObservationHeader.h>
#include <libsbp/new/observation/ObservationHeaderDep.h>
#include <libsbp/new/observation/PackedObsContent.h>
#include <libsbp/new/observation/PackedObsContentDepA.h>
#include <libsbp/new/observation/PackedObsContentDepB.h>
#include <libsbp/new/observation/PackedObsContentDepC.h>
#include <libsbp/new/observation/PackedOsrContent.h>
#include <libsbp/new/observation/SvAzEl.h>

#endif