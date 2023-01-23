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

#ifndef LIBSBP_TELEMETRY_MACROS_H
#define LIBSBP_TELEMETRY_MACROS_H

#define SBP_TELEMETRYSV_MEASUREDDOPPLER_AVAILABILITY_MASK (0x1u)
#define SBP_TELEMETRYSV_MEASUREDDOPPLER_AVAILABILITY_SHIFT (3u)
#define SBP_TELEMETRYSV_MEASUREDDOPPLER_AVAILABILITY_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_TELEMETRYSV_MEASUREDDOPPLER_AVAILABILITY_SHIFT) & \
        SBP_TELEMETRYSV_MEASUREDDOPPLER_AVAILABILITY_MASK))
#define SBP_TELEMETRYSV_MEASUREDDOPPLER_AVAILABILITY_SET(flags, val)           \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags & (~(SBP_TELEMETRYSV_MEASUREDDOPPLER_AVAILABILITY_MASK          \
                    << SBP_TELEMETRYSV_MEASUREDDOPPLER_AVAILABILITY_SHIFT))) | \
        (((val) & (SBP_TELEMETRYSV_MEASUREDDOPPLER_AVAILABILITY_MASK))         \
         << (SBP_TELEMETRYSV_MEASUREDDOPPLER_AVAILABILITY_SHIFT)));            \
  } while (0)

#define SBP_TELEMETRYSV_MEASUREDDOPPLER_AVAILABILITY_MEASURED_DOPPLER_UNAVAILABLE \
  (0)
#define SBP_TELEMETRYSV_MEASUREDDOPPLER_AVAILABILITY_MEASURED_DOPPLER_AVAILABLE \
  (1)
#define SBP_TELEMETRYSV_COMPUTEDDOPPLER_AVAILABILITY_MASK (0x1u)
#define SBP_TELEMETRYSV_COMPUTEDDOPPLER_AVAILABILITY_SHIFT (2u)
#define SBP_TELEMETRYSV_COMPUTEDDOPPLER_AVAILABILITY_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_TELEMETRYSV_COMPUTEDDOPPLER_AVAILABILITY_SHIFT) & \
        SBP_TELEMETRYSV_COMPUTEDDOPPLER_AVAILABILITY_MASK))
#define SBP_TELEMETRYSV_COMPUTEDDOPPLER_AVAILABILITY_SET(flags, val)           \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags & (~(SBP_TELEMETRYSV_COMPUTEDDOPPLER_AVAILABILITY_MASK          \
                    << SBP_TELEMETRYSV_COMPUTEDDOPPLER_AVAILABILITY_SHIFT))) | \
        (((val) & (SBP_TELEMETRYSV_COMPUTEDDOPPLER_AVAILABILITY_MASK))         \
         << (SBP_TELEMETRYSV_COMPUTEDDOPPLER_AVAILABILITY_SHIFT)));            \
  } while (0)

#define SBP_TELEMETRYSV_COMPUTEDDOPPLER_AVAILABILITY_COMPUTED_DOPPLER_UNAVAILABLE \
  (0)
#define SBP_TELEMETRYSV_COMPUTEDDOPPLER_AVAILABILITY_COMPUTED_DOPPLER_AVAILABLE \
  (1)
#define SBP_TELEMETRYSV_CARRIERPHASE_AVAILABILITY_MASK (0x1u)
#define SBP_TELEMETRYSV_CARRIERPHASE_AVAILABILITY_SHIFT (1u)
#define SBP_TELEMETRYSV_CARRIERPHASE_AVAILABILITY_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_TELEMETRYSV_CARRIERPHASE_AVAILABILITY_SHIFT) & \
        SBP_TELEMETRYSV_CARRIERPHASE_AVAILABILITY_MASK))
#define SBP_TELEMETRYSV_CARRIERPHASE_AVAILABILITY_SET(flags, val)           \
  do {                                                                      \
    (flags) = (u8)(                                                         \
        (flags & (~(SBP_TELEMETRYSV_CARRIERPHASE_AVAILABILITY_MASK          \
                    << SBP_TELEMETRYSV_CARRIERPHASE_AVAILABILITY_SHIFT))) | \
        (((val) & (SBP_TELEMETRYSV_CARRIERPHASE_AVAILABILITY_MASK))         \
         << (SBP_TELEMETRYSV_CARRIERPHASE_AVAILABILITY_SHIFT)));            \
  } while (0)

#define SBP_TELEMETRYSV_CARRIERPHASE_AVAILABILITY_CARRIER_PHASE_UNAVAILABLE (0)
#define SBP_TELEMETRYSV_CARRIERPHASE_AVAILABILITY_CARRIER_PHASE_AVAILABLE (1)
#define SBP_TELEMETRYSV_PSEUDORANGE_AVAILABILITY_MASK (0x1u)
#define SBP_TELEMETRYSV_PSEUDORANGE_AVAILABILITY_SHIFT (0u)
#define SBP_TELEMETRYSV_PSEUDORANGE_AVAILABILITY_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_TELEMETRYSV_PSEUDORANGE_AVAILABILITY_SHIFT) & \
        SBP_TELEMETRYSV_PSEUDORANGE_AVAILABILITY_MASK))
#define SBP_TELEMETRYSV_PSEUDORANGE_AVAILABILITY_SET(flags, val)           \
  do {                                                                     \
    (flags) = (u8)(                                                        \
        (flags & (~(SBP_TELEMETRYSV_PSEUDORANGE_AVAILABILITY_MASK          \
                    << SBP_TELEMETRYSV_PSEUDORANGE_AVAILABILITY_SHIFT))) | \
        (((val) & (SBP_TELEMETRYSV_PSEUDORANGE_AVAILABILITY_MASK))         \
         << (SBP_TELEMETRYSV_PSEUDORANGE_AVAILABILITY_SHIFT)));            \
  } while (0)

#define SBP_TELEMETRYSV_PSEUDORANGE_AVAILABILITY_PSEUDORANGE_UNAVAILABLE (0)
#define SBP_TELEMETRYSV_PSEUDORANGE_AVAILABILITY_PSEUDORANGE_AVAILABLE (1)
#define SBP_TELEMETRYSV_MEASUREDDOPPLER_OUTLIER_MASK (0x1u)
#define SBP_TELEMETRYSV_MEASUREDDOPPLER_OUTLIER_SHIFT (4u)
#define SBP_TELEMETRYSV_MEASUREDDOPPLER_OUTLIER_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_TELEMETRYSV_MEASUREDDOPPLER_OUTLIER_SHIFT) & \
        SBP_TELEMETRYSV_MEASUREDDOPPLER_OUTLIER_MASK))
#define SBP_TELEMETRYSV_MEASUREDDOPPLER_OUTLIER_SET(flags, val)                \
  do {                                                                         \
    (flags) =                                                                  \
        (u8)((flags & (~(SBP_TELEMETRYSV_MEASUREDDOPPLER_OUTLIER_MASK          \
                         << SBP_TELEMETRYSV_MEASUREDDOPPLER_OUTLIER_SHIFT))) | \
             (((val) & (SBP_TELEMETRYSV_MEASUREDDOPPLER_OUTLIER_MASK))         \
              << (SBP_TELEMETRYSV_MEASUREDDOPPLER_OUTLIER_SHIFT)));            \
  } while (0)

#define SBP_TELEMETRYSV_MEASUREDDOPPLER_OUTLIER_MEASURED_DOPPLER_ACCEPTED (0)
#define SBP_TELEMETRYSV_MEASUREDDOPPLER_OUTLIER_MEASURED_DOPPLER_MARKED_AS_OUTLIER \
  (1)
#define SBP_TELEMETRYSV_COMPUTEDDOPPLER_OUTLIER_MASK (0x1u)
#define SBP_TELEMETRYSV_COMPUTEDDOPPLER_OUTLIER_SHIFT (3u)
#define SBP_TELEMETRYSV_COMPUTEDDOPPLER_OUTLIER_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_TELEMETRYSV_COMPUTEDDOPPLER_OUTLIER_SHIFT) & \
        SBP_TELEMETRYSV_COMPUTEDDOPPLER_OUTLIER_MASK))
#define SBP_TELEMETRYSV_COMPUTEDDOPPLER_OUTLIER_SET(flags, val)                \
  do {                                                                         \
    (flags) =                                                                  \
        (u8)((flags & (~(SBP_TELEMETRYSV_COMPUTEDDOPPLER_OUTLIER_MASK          \
                         << SBP_TELEMETRYSV_COMPUTEDDOPPLER_OUTLIER_SHIFT))) | \
             (((val) & (SBP_TELEMETRYSV_COMPUTEDDOPPLER_OUTLIER_MASK))         \
              << (SBP_TELEMETRYSV_COMPUTEDDOPPLER_OUTLIER_SHIFT)));            \
  } while (0)

#define SBP_TELEMETRYSV_COMPUTEDDOPPLER_OUTLIER_COMPUTED_DOPPLER_ACCEPTED (0)
#define SBP_TELEMETRYSV_COMPUTEDDOPPLER_OUTLIER_COMPUTED_DOPPLER_MARKED_AS_OUTLIER \
  (1)
#define SBP_TELEMETRYSV_CARRIERPHASE_OUTLIER_MASK (0x1u)
#define SBP_TELEMETRYSV_CARRIERPHASE_OUTLIER_SHIFT (2u)
#define SBP_TELEMETRYSV_CARRIERPHASE_OUTLIER_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_TELEMETRYSV_CARRIERPHASE_OUTLIER_SHIFT) & \
        SBP_TELEMETRYSV_CARRIERPHASE_OUTLIER_MASK))
#define SBP_TELEMETRYSV_CARRIERPHASE_OUTLIER_SET(flags, val)                \
  do {                                                                      \
    (flags) =                                                               \
        (u8)((flags & (~(SBP_TELEMETRYSV_CARRIERPHASE_OUTLIER_MASK          \
                         << SBP_TELEMETRYSV_CARRIERPHASE_OUTLIER_SHIFT))) | \
             (((val) & (SBP_TELEMETRYSV_CARRIERPHASE_OUTLIER_MASK))         \
              << (SBP_TELEMETRYSV_CARRIERPHASE_OUTLIER_SHIFT)));            \
  } while (0)

#define SBP_TELEMETRYSV_CARRIERPHASE_OUTLIER_CARRIER_PHASE_ACCEPTED (0)
#define SBP_TELEMETRYSV_CARRIERPHASE_OUTLIER_CARRIER_PHASE_MARKED_AS_OUTLIER (1)
#define SBP_TELEMETRYSV_PSEUDORANGE_OUTLIER_MASK (0x3u)
#define SBP_TELEMETRYSV_PSEUDORANGE_OUTLIER_SHIFT (0u)
#define SBP_TELEMETRYSV_PSEUDORANGE_OUTLIER_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_TELEMETRYSV_PSEUDORANGE_OUTLIER_SHIFT) & \
        SBP_TELEMETRYSV_PSEUDORANGE_OUTLIER_MASK))
#define SBP_TELEMETRYSV_PSEUDORANGE_OUTLIER_SET(flags, val)                \
  do {                                                                     \
    (flags) =                                                              \
        (u8)((flags & (~(SBP_TELEMETRYSV_PSEUDORANGE_OUTLIER_MASK          \
                         << SBP_TELEMETRYSV_PSEUDORANGE_OUTLIER_SHIFT))) | \
             (((val) & (SBP_TELEMETRYSV_PSEUDORANGE_OUTLIER_MASK))         \
              << (SBP_TELEMETRYSV_PSEUDORANGE_OUTLIER_SHIFT)));            \
  } while (0)

#define SBP_TELEMETRYSV_PSEUDORANGE_OUTLIER_PSEUDORANGE_ACCEPTED (0)
#define SBP_TELEMETRYSV_PSEUDORANGE_OUTLIER_PSEUDORANGE_MARKED_AS_OUTLIER (1)
#define SBP_TELEMETRYSV_PSEUDORANGE_OUTLIER_PSEUDORANGE_MARKED_AS_MAJOR_OUTLIER \
  (2)
#define SBP_TELEMETRYSV_EPHEMERIS_AVAILABLE_MASK (0x1u)
#define SBP_TELEMETRYSV_EPHEMERIS_AVAILABLE_SHIFT (0u)
#define SBP_TELEMETRYSV_EPHEMERIS_AVAILABLE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_TELEMETRYSV_EPHEMERIS_AVAILABLE_SHIFT) & \
        SBP_TELEMETRYSV_EPHEMERIS_AVAILABLE_MASK))
#define SBP_TELEMETRYSV_EPHEMERIS_AVAILABLE_SET(flags, val)                \
  do {                                                                     \
    (flags) =                                                              \
        (u8)((flags & (~(SBP_TELEMETRYSV_EPHEMERIS_AVAILABLE_MASK          \
                         << SBP_TELEMETRYSV_EPHEMERIS_AVAILABLE_SHIFT))) | \
             (((val) & (SBP_TELEMETRYSV_EPHEMERIS_AVAILABLE_MASK))         \
              << (SBP_TELEMETRYSV_EPHEMERIS_AVAILABLE_SHIFT)));            \
  } while (0)

#define SBP_TELEMETRYSV_EPHEMERIS_AVAILABLE_VALID_EPHEMERIS_AVAILABLE (0)
#define SBP_TELEMETRYSV_EPHEMERIS_AVAILABLE_NO_VALID_EPHEMERIS_AVAILABLE (1)
/**
 * Encoded length of sbp_telemetry_sv_t (V4 API) and
 * telemetry_sv_t (legacy API)
 */
#define SBP_TELEMETRY_SV_ENCODED_LEN 12u

#define SBP_MSG_TEL_SV 0x0120
#define SBP_TEL_SV_FILTER_TYPE_MASK (0xffu)
#define SBP_TEL_SV_FILTER_TYPE_SHIFT (0u)
#define SBP_TEL_SV_FILTER_TYPE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_TEL_SV_FILTER_TYPE_SHIFT) & \
        SBP_TEL_SV_FILTER_TYPE_MASK))
#define SBP_TEL_SV_FILTER_TYPE_SET(flags, val)                      \
  do {                                                              \
    (flags) = (u8)((flags & (~(SBP_TEL_SV_FILTER_TYPE_MASK          \
                               << SBP_TEL_SV_FILTER_TYPE_SHIFT))) | \
                   (((val) & (SBP_TEL_SV_FILTER_TYPE_MASK))         \
                    << (SBP_TEL_SV_FILTER_TYPE_SHIFT)));            \
  } while (0)

#define SBP_TEL_SV_FILTER_TYPE_STANDALONE (0)
#define SBP_TEL_SV_FILTER_TYPE_DIFFERENTIAL (1)
/**
 * The maximum number of items that can be stored in sbp_msg_tel_sv_t::sv_tel
 * (V4 API) or msg_tel_sv_t::sv_tel (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_TEL_SV_SV_TEL_MAX 20u

/**
 * Encoded length of sbp_msg_tel_sv_t (V4 API) and
 * msg_tel_sv_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_tel_sv_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_TEL_SV_ENCODED_OVERHEAD 8u

#endif /* LIBSBP_TELEMETRY_MACROS_H */
