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
 * Automatically generated from yaml/swiftnav/sbp/gnss.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_GNSS_MACROS_H
#define LIBSBP_GNSS_MACROS_H

#define SBP_GNSSSIGNAL__MASK (0xff)
#define SBP_GNSSSIGNAL__SHIFT (0u)
#define SBP_GNSSSIGNAL__GET(flags) \
  ((u8)(((flags) >> SBP_GNSSSIGNAL__SHIFT) & SBP_GNSSSIGNAL__MASK))
#define SBP_GNSSSIGNAL__SET(flags, val)                        \
  do {                                                         \
    (flags) = (u8)((flags) | (((val) & (SBP_GNSSSIGNAL__MASK)) \
                              << (SBP_GNSSSIGNAL__SHIFT)));    \
  } while (0)

#define SBP_GNSSSIGNAL_GPS_L1CA (0)
#define SBP_GNSSSIGNAL_GPS_L2CM (1)
#define SBP_GNSSSIGNAL_SBAS_L1CA (2)
#define SBP_GNSSSIGNAL_GLO_L1CA (3)
#define SBP_GNSSSIGNAL_GLO_L2CA (4)
#define SBP_GNSSSIGNAL_GPS_L1P (5)
#define SBP_GNSSSIGNAL_GPS_L2P (6)
#define SBP_GNSSSIGNAL_BDS2_B1 (12)
#define SBP_GNSSSIGNAL_BDS2_B2 (13)
#define SBP_GNSSSIGNAL_GAL_E1B (14)
#define SBP_GNSSSIGNAL_GAL_E7I (20)
#define SBP_GNSSSIGNAL_BDS3_B2A (47)
/**
 * Encoded length of sbp_v4_gnss_signal_t (V4 API) and
 * sbp_gnss_signal_t (legacy API)
 */
#define SBP_V4_GNSS_SIGNAL_ENCODED_LEN 2u

/**
 * Encoded length of sbp_sv_id_t (V4 API) and
 * sv_id_t (legacy API)
 */
#define SBP_SV_ID_ENCODED_LEN 2u

#define SBP_GNSSSIGNALDEP__MASK (0xff)
#define SBP_GNSSSIGNALDEP__SHIFT (0u)
#define SBP_GNSSSIGNALDEP__GET(flags) \
  ((u8)(((flags) >> SBP_GNSSSIGNALDEP__SHIFT) & SBP_GNSSSIGNALDEP__MASK))
#define SBP_GNSSSIGNALDEP__SET(flags, val)                        \
  do {                                                            \
    (flags) = (u8)((flags) | (((val) & (SBP_GNSSSIGNALDEP__MASK)) \
                              << (SBP_GNSSSIGNALDEP__SHIFT)));    \
  } while (0)

#define SBP_GNSSSIGNALDEP_GPS_L1CA (0)
#define SBP_GNSSSIGNALDEP_GPS_L2CM (1)
#define SBP_GNSSSIGNALDEP_SBAS_L1CA (2)
#define SBP_GNSSSIGNALDEP_GLO_L1CA (3)
#define SBP_GNSSSIGNALDEP_GLO_L2CA (4)
#define SBP_GNSSSIGNALDEP_GPS_L1P (5)
#define SBP_GNSSSIGNALDEP_GPS_L2P (6)
/**
 * Encoded length of sbp_gnss_signal_dep_t (V4 API) and
 * gnss_signal_dep_t (legacy API)
 */
#define SBP_GNSS_SIGNAL_DEP_ENCODED_LEN 4u

/**
 * Encoded length of sbp_gps_time_dep_t (V4 API) and
 * gps_time_dep_t (legacy API)
 */
#define SBP_GPS_TIME_DEP_ENCODED_LEN 6u

/**
 * Encoded length of sbp_gps_time_sec_t (V4 API) and
 * gps_time_sec_t (legacy API)
 */
#define SBP_GPS_TIME_SEC_ENCODED_LEN 6u

/**
 * Encoded length of sbp_v4_gps_time_t (V4 API) and
 * sbp_gps_time_t (legacy API)
 */
#define SBP_V4_GPS_TIME_ENCODED_LEN 10u

/**
 * Encoded length of sbp_carrier_phase_t (V4 API) and
 * carrier_phase_t (legacy API)
 */
#define SBP_CARRIER_PHASE_ENCODED_LEN 5u

#endif /* LIBSBP_GNSS_MACROS_H */
