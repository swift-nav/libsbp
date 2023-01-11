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

#define SBP_TELEMETRYSVHEADER__MASK (0xffu)
#define SBP_TELEMETRYSVHEADER__SHIFT (0u)
#define SBP_TELEMETRYSVHEADER__GET(flags)               \
  ((u8)((u8)((flags) >> SBP_TELEMETRYSVHEADER__SHIFT) & \
        SBP_TELEMETRYSVHEADER__MASK))
#define SBP_TELEMETRYSVHEADER__SET(flags, val)                      \
  do {                                                              \
    (flags) = (u8)((flags & (~(SBP_TELEMETRYSVHEADER__MASK          \
                               << SBP_TELEMETRYSVHEADER__SHIFT))) | \
                   (((val) & (SBP_TELEMETRYSVHEADER__MASK))         \
                    << (SBP_TELEMETRYSVHEADER__SHIFT)));            \
  } while (0)

#define SBP_TELEMETRYSVHEADER_STANDALONE (0)
#define SBP_TELEMETRYSVHEADER_DIFFERENTIAL (1)
/**
 * Encoded length of sbp_telemetry_sv_header_t (V4 API) and
 * telemetry_sv_header_t (legacy API)
 */
#define SBP_TELEMETRY_SV_HEADER_ENCODED_LEN 8u

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
#define SBP_TELEMETRYSV_PSEUDORANGE_OUTLIER_MAJOR_PSEUDORANGE_OUTLIER_DETECTED \
  (2)
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
#define SBP_TELEMETRYSV_REASON_FOR_EPHEMERIS_INVALIDITY_MASK (0x7u)
#define SBP_TELEMETRYSV_REASON_FOR_EPHEMERIS_INVALIDITY_SHIFT (0u)
#define SBP_TELEMETRYSV_REASON_FOR_EPHEMERIS_INVALIDITY_GET(flags)             \
  ((u8)(                                                                       \
      (u8)((flags) >> SBP_TELEMETRYSV_REASON_FOR_EPHEMERIS_INVALIDITY_SHIFT) & \
      SBP_TELEMETRYSV_REASON_FOR_EPHEMERIS_INVALIDITY_MASK))
#define SBP_TELEMETRYSV_REASON_FOR_EPHEMERIS_INVALIDITY_SET(flags, val)        \
  do {                                                                         \
    (flags) =                                                                  \
        (u8)((flags &                                                          \
              (~(SBP_TELEMETRYSV_REASON_FOR_EPHEMERIS_INVALIDITY_MASK          \
                 << SBP_TELEMETRYSV_REASON_FOR_EPHEMERIS_INVALIDITY_SHIFT))) | \
             (((val) & (SBP_TELEMETRYSV_REASON_FOR_EPHEMERIS_INVALIDITY_MASK)) \
              << (SBP_TELEMETRYSV_REASON_FOR_EPHEMERIS_INVALIDITY_SHIFT)));    \
  } while (0)

#define SBP_TELEMETRYSV_REASON_FOR_EPHEMERIS_INVALIDITY_VALID (0)
#define SBP_TELEMETRYSV_REASON_FOR_EPHEMERIS_INVALIDITY_INVALID (1)
/**
 * Encoded length of sbp_telemetry_sv_t (V4 API) and
 * telemetry_sv_t (legacy API)
 */
#define SBP_TELEMETRY_SV_ENCODED_LEN 11u

#define SBP_MSG_TEL_SV 0x0120
/**
 * The maximum number of items that can be stored in sbp_msg_tel_sv_t::sv_tel
 * (V4 API) or msg_tel_sv_t::sv_tel (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_TEL_SV_SV_TEL_MAX 22u

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
