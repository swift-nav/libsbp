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
 * Automatically generated from yaml/swiftnav/sbp/ssr.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_SSR_MESSAGES_H
#define LIBSBP_SSR_MESSAGES_H
#include <libsbp/ssr/BoundsHeader.h>
#include <libsbp/ssr/CodeBiasesContent.h>
#include <libsbp/ssr/CodePhaseBiasesSatSig.h>
#include <libsbp/ssr/GridDefinitionHeaderDepA.h>
#include <libsbp/ssr/GriddedCorrectionHeader.h>
#include <libsbp/ssr/GriddedCorrectionHeaderDepA.h>
#include <libsbp/ssr/MSG_SSR_CODE_BIASES.h>
#include <libsbp/ssr/MSG_SSR_CODE_PHASE_BIASES_BOUNDS.h>
#include <libsbp/ssr/MSG_SSR_GRIDDED_CORRECTION.h>
#include <libsbp/ssr/MSG_SSR_GRIDDED_CORRECTION_BOUNDS.h>
#include <libsbp/ssr/MSG_SSR_GRIDDED_CORRECTION_DEP_A.h>
#include <libsbp/ssr/MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A.h>
#include <libsbp/ssr/MSG_SSR_GRID_DEFINITION_DEP_A.h>
#include <libsbp/ssr/MSG_SSR_ORBIT_CLOCK.h>
#include <libsbp/ssr/MSG_SSR_ORBIT_CLOCK_BOUNDS.h>
#include <libsbp/ssr/MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION.h>
#include <libsbp/ssr/MSG_SSR_ORBIT_CLOCK_DEP_A.h>
#include <libsbp/ssr/MSG_SSR_PHASE_BIASES.h>
#include <libsbp/ssr/MSG_SSR_SATELLITE_APC.h>
#include <libsbp/ssr/MSG_SSR_SATELLITE_APC_DEP.h>
#include <libsbp/ssr/MSG_SSR_STEC_CORRECTION.h>
#include <libsbp/ssr/MSG_SSR_STEC_CORRECTION_DEP.h>
#include <libsbp/ssr/MSG_SSR_STEC_CORRECTION_DEP_A.h>
#include <libsbp/ssr/MSG_SSR_TILE_DEFINITION.h>
#include <libsbp/ssr/MSG_SSR_TILE_DEFINITION_DEP_A.h>
#include <libsbp/ssr/MSG_SSR_TILE_DEFINITION_DEP_B.h>
#include <libsbp/ssr/OrbitClockBound.h>
#include <libsbp/ssr/OrbitClockBoundDegradation.h>
#include <libsbp/ssr/PhaseBiasesContent.h>
#include <libsbp/ssr/STECHeader.h>
#include <libsbp/ssr/STECHeaderDepA.h>
#include <libsbp/ssr/STECResidual.h>
#include <libsbp/ssr/STECResidualNoStd.h>
#include <libsbp/ssr/STECSatElement.h>
#include <libsbp/ssr/STECSatElementIntegrity.h>
#include <libsbp/ssr/SatelliteAPC.h>
#include <libsbp/ssr/TroposphericDelayCorrection.h>
#include <libsbp/ssr/TroposphericDelayCorrectionNoStd.h>

#endif /* LIBSBP_SSR_MESSAGES_H */
