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
 * Automatically generated from yaml/swiftnav/sbp/telemetry.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup telemetry Telemetry
 *
 * Telemetry messages reported by Starling engine. The messages include
 * various byproducts of state estimation and other logic across Starling and
 * are aimed at efficient issue diagnostics.
 * \{ */

#ifndef LIBSBP_LEGACY_TELEMETRY_MESSAGES_H
#define LIBSBP_LEGACY_TELEMETRY_MESSAGES_H

#include <libsbp/common.h>

#include <libsbp/legacy/gnss.h>
#include <libsbp/telemetry_macros.h>

SBP_PACK_START

typedef struct SBP_ATTR_PACKED {
  u8 az;                    /**< Azimuth angle (range 0..179) [deg * 2] */
  s8 el;                    /**< Elevation angle (range -90..90) [deg] */
  u8 availability_flags;    /**< Observation availability at filter update */
  s16 pseudorange_residual; /**< Pseudorange observation residual [1 dm] */
  s16 phase_residual;       /**< Carrier-phase or carrier-phase-derived
                                 observation residual [5 mm] */
  u8 outlier_flags;         /**< Reports if observation is marked as an
                                 outlier and is excluded from the update */
  u8 ephemeris_flags;       /**< Ephemeris metadata */
  u8 correction_flags;      /**< Reserved */
  sbp_gnss_signal_t sid;    /**< GNSS signal identifier (16
                                 bit) */
} telemetry_sv_t;

/** Per-signal telemetry
 *
 * This message includes telemetry pertinent to satellite signals available to
 * Starling.
 */

typedef struct SBP_ATTR_PACKED {
  u16 wn;          /**< GPS week number [weeks] */
  u32 tow;         /**< GPS Time of Week [ms] */
  u8 n_obs;        /**< Total number of observations. First nibble is the
                        size of the sequence (n), second nibble is the
                        zero-indexed counter (ith packet of n) */
  u8 origin_flags; /**< Flags to identify the filter type from which the
                        telemetry is reported from */
  telemetry_sv_t sv_tel[0]; /**< Array of per-signal telemetry entries */
} msg_tel_sv_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_TELEMETRY_MESSAGES_H */