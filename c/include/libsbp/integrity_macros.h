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
 * Automatically generated from yaml/swiftnav/sbp/integrity.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_INTEGRITY_MACROS_H
#define LIBSBP_INTEGRITY_MACROS_H

/**
 * Encoded length of sbp_integrity_ssr_header_t (V4 API) and
 * integrity_ssr_header_t (legacy API)
 */
#define SBP_INTEGRITY_SSR_HEADER_ENCODED_LEN 14u

#define SBP_MSG_SSR_FLAG_HIGH_LEVEL 0x0BB9
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GPS_SATELLITES_MASK (0x7u)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GPS_SATELLITES_SHIFT (0u)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GPS_SATELLITES_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_SSR_FLAG_HIGH_LEVEL_USE_GPS_SATELLITES_SHIFT) & \
        SBP_SSR_FLAG_HIGH_LEVEL_USE_GPS_SATELLITES_MASK))
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GPS_SATELLITES_SET(flags, val)           \
  do {                                                                       \
    (flags) = (u8)(                                                          \
        (flags & (~(SBP_SSR_FLAG_HIGH_LEVEL_USE_GPS_SATELLITES_MASK          \
                    << SBP_SSR_FLAG_HIGH_LEVEL_USE_GPS_SATELLITES_SHIFT))) | \
        (((val) & (SBP_SSR_FLAG_HIGH_LEVEL_USE_GPS_SATELLITES_MASK))         \
         << (SBP_SSR_FLAG_HIGH_LEVEL_USE_GPS_SATELLITES_SHIFT)));            \
  } while (0)

#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GPS_SATELLITES_NOMINAL (0)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GPS_SATELLITES_WARNING (1)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GPS_SATELLITES_ALERT (2)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GPS_SATELLITES_NOT_MONITORED (3)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GAL_SATELLITES_MASK (0x7u)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GAL_SATELLITES_SHIFT (0u)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GAL_SATELLITES_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_SSR_FLAG_HIGH_LEVEL_USE_GAL_SATELLITES_SHIFT) & \
        SBP_SSR_FLAG_HIGH_LEVEL_USE_GAL_SATELLITES_MASK))
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GAL_SATELLITES_SET(flags, val)           \
  do {                                                                       \
    (flags) = (u8)(                                                          \
        (flags & (~(SBP_SSR_FLAG_HIGH_LEVEL_USE_GAL_SATELLITES_MASK          \
                    << SBP_SSR_FLAG_HIGH_LEVEL_USE_GAL_SATELLITES_SHIFT))) | \
        (((val) & (SBP_SSR_FLAG_HIGH_LEVEL_USE_GAL_SATELLITES_MASK))         \
         << (SBP_SSR_FLAG_HIGH_LEVEL_USE_GAL_SATELLITES_SHIFT)));            \
  } while (0)

#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GAL_SATELLITES_NOMINAL (0)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GAL_SATELLITES_WARNING (1)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GAL_SATELLITES_ALERT (2)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_GAL_SATELLITES_NOT_MONITORED (3)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_BDS_SATELLITES_MASK (0x7u)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_BDS_SATELLITES_SHIFT (0u)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_BDS_SATELLITES_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_SSR_FLAG_HIGH_LEVEL_USE_BDS_SATELLITES_SHIFT) & \
        SBP_SSR_FLAG_HIGH_LEVEL_USE_BDS_SATELLITES_MASK))
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_BDS_SATELLITES_SET(flags, val)           \
  do {                                                                       \
    (flags) = (u8)(                                                          \
        (flags & (~(SBP_SSR_FLAG_HIGH_LEVEL_USE_BDS_SATELLITES_MASK          \
                    << SBP_SSR_FLAG_HIGH_LEVEL_USE_BDS_SATELLITES_SHIFT))) | \
        (((val) & (SBP_SSR_FLAG_HIGH_LEVEL_USE_BDS_SATELLITES_MASK))         \
         << (SBP_SSR_FLAG_HIGH_LEVEL_USE_BDS_SATELLITES_SHIFT)));            \
  } while (0)

#define SBP_SSR_FLAG_HIGH_LEVEL_USE_BDS_SATELLITES_NOMINAL (0)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_BDS_SATELLITES_WARNING (1)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_BDS_SATELLITES_ALERT (2)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_BDS_SATELLITES_NOT_MONITORED (3)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_flag_high_level_t::reserved (V4 API) or
 * msg_ssr_flag_high_level_t::reserved (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SSR_FLAG_HIGH_LEVEL_RESERVED_MAX 6u

#define SBP_SSR_FLAG_HIGH_LEVEL_USE_TROPO_GRID_POINTS_MASK (0x7u)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_TROPO_GRID_POINTS_SHIFT (0u)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_TROPO_GRID_POINTS_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_SSR_FLAG_HIGH_LEVEL_USE_TROPO_GRID_POINTS_SHIFT) & \
        SBP_SSR_FLAG_HIGH_LEVEL_USE_TROPO_GRID_POINTS_MASK))
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_TROPO_GRID_POINTS_SET(flags, val)        \
  do {                                                                       \
    (flags) =                                                                \
        (u8)((flags &                                                        \
              (~(SBP_SSR_FLAG_HIGH_LEVEL_USE_TROPO_GRID_POINTS_MASK          \
                 << SBP_SSR_FLAG_HIGH_LEVEL_USE_TROPO_GRID_POINTS_SHIFT))) | \
             (((val) & (SBP_SSR_FLAG_HIGH_LEVEL_USE_TROPO_GRID_POINTS_MASK)) \
              << (SBP_SSR_FLAG_HIGH_LEVEL_USE_TROPO_GRID_POINTS_SHIFT)));    \
  } while (0)

#define SBP_SSR_FLAG_HIGH_LEVEL_USE_TROPO_GRID_POINTS_NOMINAL (0)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_TROPO_GRID_POINTS_WARNING (1)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_TROPO_GRID_POINTS_ALERT (2)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_TROPO_GRID_POINTS_NOT_MONITORED (3)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINTS_MASK (0x7u)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINTS_SHIFT (0u)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINTS_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINTS_SHIFT) & \
        SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINTS_MASK))
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINTS_SET(flags, val)           \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags & (~(SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINTS_MASK          \
                    << SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINTS_SHIFT))) | \
        (((val) & (SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINTS_MASK))         \
         << (SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINTS_SHIFT)));            \
  } while (0)

#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINTS_NOMINAL (0)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINTS_WARNING (1)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINTS_ALERT (2)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINTS_NOT_MONITORED (3)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_TILE_SATELLITE_LOS_MASK (0x7u)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_TILE_SATELLITE_LOS_SHIFT (0u)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_TILE_SATELLITE_LOS_GET(flags)    \
  ((u8)((u8)((flags) >>                                                   \
             SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_TILE_SATELLITE_LOS_SHIFT) & \
        SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_TILE_SATELLITE_LOS_MASK))
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_TILE_SATELLITE_LOS_SET(flags, val)   \
  do {                                                                        \
    (flags) = (u8)(                                                           \
        (flags &                                                              \
         (~(SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_TILE_SATELLITE_LOS_MASK          \
            << SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_TILE_SATELLITE_LOS_SHIFT))) | \
        (((val) & (SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_TILE_SATELLITE_LOS_MASK)) \
         << (SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_TILE_SATELLITE_LOS_SHIFT)));    \
  } while (0)

#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_TILE_SATELLITE_LOS_NOMINAL (0)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_TILE_SATELLITE_LOS_WARNING (1)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_TILE_SATELLITE_LOS_ALERT (2)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_TILE_SATELLITE_LOS_NOT_MONITORED (3)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINT_SATELLITE_LOS_MASK (0x7u)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINT_SATELLITE_LOS_SHIFT (0u)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINT_SATELLITE_LOS_GET(flags)  \
  ((u8)(                                                                      \
      (u8)((flags) >>                                                         \
           SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINT_SATELLITE_LOS_SHIFT) & \
      SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINT_SATELLITE_LOS_MASK))
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINT_SATELLITE_LOS_SET(flags,        \
                                                                      val)          \
  do {                                                                              \
    (flags) = (u8)(                                                                 \
        (flags &                                                                    \
         (~(SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINT_SATELLITE_LOS_MASK          \
            << SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINT_SATELLITE_LOS_SHIFT))) | \
        (((val) &                                                                   \
          (SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINT_SATELLITE_LOS_MASK))         \
         << (SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINT_SATELLITE_LOS_SHIFT)));    \
  } while (0)

#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINT_SATELLITE_LOS_NOMINAL (0)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINT_SATELLITE_LOS_WARNING (1)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINT_SATELLITE_LOS_ALERT (2)
#define SBP_SSR_FLAG_HIGH_LEVEL_USE_IONO_GRID_POINT_SATELLITE_LOS_NOT_MONITORED \
  (3)
/**
 * Encoded length of sbp_msg_ssr_flag_high_level_t (V4 API) and
 * msg_ssr_flag_high_level_t (legacy API)
 */
#define SBP_MSG_SSR_FLAG_HIGH_LEVEL_ENCODED_LEN 31u

#define SBP_MSG_SSR_FLAG_SATELLITES 0x0BBD
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_flag_satellites_t::faulty_sats (V4 API) or
 * msg_ssr_flag_satellites_t::faulty_sats (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SSR_FLAG_SATELLITES_FAULTY_SATS_MAX 243u

/**
 * Encoded length of sbp_msg_ssr_flag_satellites_t (V4 API) and
 * msg_ssr_flag_satellites_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ssr_flag_satellites_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_FLAG_SATELLITES_ENCODED_OVERHEAD 12u

#define SBP_MSG_SSR_FLAG_TROPO_GRID_POINTS 0x0BC3
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_flag_tropo_grid_points_t::faulty_points (V4 API) or
 * msg_ssr_flag_tropo_grid_points_t::faulty_points (legacy API) before the
 * maximum SBP message size is exceeded
 */
#define SBP_MSG_SSR_FLAG_TROPO_GRID_POINTS_FAULTY_POINTS_MAX 120u

/**
 * Encoded length of sbp_msg_ssr_flag_tropo_grid_points_t (V4 API) and
 * msg_ssr_flag_tropo_grid_points_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ssr_flag_tropo_grid_points_encoded_len to determine the actual size
 * of an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_FLAG_TROPO_GRID_POINTS_ENCODED_OVERHEAD 15u

#define SBP_MSG_SSR_FLAG_IONO_GRID_POINTS 0x0BC7
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_flag_iono_grid_points_t::faulty_points (V4 API) or
 * msg_ssr_flag_iono_grid_points_t::faulty_points (legacy API) before the
 * maximum SBP message size is exceeded
 */
#define SBP_MSG_SSR_FLAG_IONO_GRID_POINTS_FAULTY_POINTS_MAX 120u

/**
 * Encoded length of sbp_msg_ssr_flag_iono_grid_points_t (V4 API) and
 * msg_ssr_flag_iono_grid_points_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ssr_flag_iono_grid_points_encoded_len to determine the actual size
 * of an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_FLAG_IONO_GRID_POINTS_ENCODED_OVERHEAD 15u

#define SBP_MSG_SSR_FLAG_IONO_TILE_SAT_LOS 0x0BCD
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_flag_iono_tile_sat_los_t::faulty_los (V4 API) or
 * msg_ssr_flag_iono_tile_sat_los_t::faulty_los (legacy API) before the maximum
 * SBP message size is exceeded
 */
#define SBP_MSG_SSR_FLAG_IONO_TILE_SAT_LOS_FAULTY_LOS_MAX 120u

/**
 * Encoded length of sbp_msg_ssr_flag_iono_tile_sat_los_t (V4 API) and
 * msg_ssr_flag_iono_tile_sat_los_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ssr_flag_iono_tile_sat_los_encoded_len to determine the actual size
 * of an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_FLAG_IONO_TILE_SAT_LOS_ENCODED_OVERHEAD 15u

#define SBP_MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS 0x0BD1
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_flag_iono_grid_point_sat_los_t::faulty_los (V4 API) or
 * msg_ssr_flag_iono_grid_point_sat_los_t::faulty_los (legacy API) before the
 * maximum SBP message size is exceeded
 */
#define SBP_MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS_FAULTY_LOS_MAX 119u

/**
 * Encoded length of sbp_msg_ssr_flag_iono_grid_point_sat_los_t (V4 API) and
 * msg_ssr_flag_iono_grid_point_sat_los_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ssr_flag_iono_grid_point_sat_los_encoded_len to determine the actual
 * size of an instance of this message. Users of the legacy API are required to
 * track the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS_ENCODED_OVERHEAD 17u

#define SBP_MSG_ACKNOWLEDGE 0x0BD2
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_MASK (0xffu)
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_SHIFT (0u)
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_ACKNOWLEDGE_RESPONSE_CODE_SHIFT) & \
        SBP_ACKNOWLEDGE_RESPONSE_CODE_MASK))
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_SET(flags, val)                      \
  do {                                                                     \
    (flags) = (u8)((flags & (~(SBP_ACKNOWLEDGE_RESPONSE_CODE_MASK          \
                               << SBP_ACKNOWLEDGE_RESPONSE_CODE_SHIFT))) | \
                   (((val) & (SBP_ACKNOWLEDGE_RESPONSE_CODE_MASK))         \
                    << (SBP_ACKNOWLEDGE_RESPONSE_CODE_SHIFT)));            \
  } while (0)

#define SBP_ACKNOWLEDGE_RESPONSE_CODE_OK (0)
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_OUT_OF_COVERAGE (1)
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_FORBIDDEN (2)
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_INVALID_REQUEST (3)
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_INVALID_AREA_ID (4)
#define SBP_ACKNOWLEDGE_CORRECTIONS_CERTIFICATE_MASK (0x1u)
#define SBP_ACKNOWLEDGE_CORRECTIONS_CERTIFICATE_SHIFT (0u)
#define SBP_ACKNOWLEDGE_CORRECTIONS_CERTIFICATE_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_ACKNOWLEDGE_CORRECTIONS_CERTIFICATE_SHIFT) & \
         SBP_ACKNOWLEDGE_CORRECTIONS_CERTIFICATE_MASK))
#define SBP_ACKNOWLEDGE_CORRECTIONS_CERTIFICATE_SET(flags, val)           \
  do {                                                                    \
    (flags) = (u16)(                                                      \
        (flags & (~(SBP_ACKNOWLEDGE_CORRECTIONS_CERTIFICATE_MASK          \
                    << SBP_ACKNOWLEDGE_CORRECTIONS_CERTIFICATE_SHIFT))) | \
        (((val) & (SBP_ACKNOWLEDGE_CORRECTIONS_CERTIFICATE_MASK))         \
         << (SBP_ACKNOWLEDGE_CORRECTIONS_CERTIFICATE_SHIFT)));            \
  } while (0)

#define SBP_ACKNOWLEDGE_CORRECTIONS_CERTIFICATE_NOT_REQUESTED (0)
#define SBP_ACKNOWLEDGE_CORRECTIONS_CERTIFICATE_REQUESTED (1)
#define SBP_ACKNOWLEDGE_LOW_RATE_MESSAGES_MASK (0x1u)
#define SBP_ACKNOWLEDGE_LOW_RATE_MESSAGES_SHIFT (1u)
#define SBP_ACKNOWLEDGE_LOW_RATE_MESSAGES_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_ACKNOWLEDGE_LOW_RATE_MESSAGES_SHIFT) & \
         SBP_ACKNOWLEDGE_LOW_RATE_MESSAGES_MASK))
#define SBP_ACKNOWLEDGE_LOW_RATE_MESSAGES_SET(flags, val)                 \
  do {                                                                    \
    (flags) =                                                             \
        (u16)((flags & (~(SBP_ACKNOWLEDGE_LOW_RATE_MESSAGES_MASK          \
                          << SBP_ACKNOWLEDGE_LOW_RATE_MESSAGES_SHIFT))) | \
              (((val) & (SBP_ACKNOWLEDGE_LOW_RATE_MESSAGES_MASK))         \
               << (SBP_ACKNOWLEDGE_LOW_RATE_MESSAGES_SHIFT)));            \
  } while (0)

#define SBP_ACKNOWLEDGE_LOW_RATE_MESSAGES_NOT_REQUESTED (0)
#define SBP_ACKNOWLEDGE_LOW_RATE_MESSAGES_REQUESTED (1)
#define SBP_ACKNOWLEDGE_EPHEMERIS_MASK (0x1u)
#define SBP_ACKNOWLEDGE_EPHEMERIS_SHIFT (2u)
#define SBP_ACKNOWLEDGE_EPHEMERIS_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_ACKNOWLEDGE_EPHEMERIS_SHIFT) & \
         SBP_ACKNOWLEDGE_EPHEMERIS_MASK))
#define SBP_ACKNOWLEDGE_EPHEMERIS_SET(flags, val)                       \
  do {                                                                  \
    (flags) = (u16)((flags & (~(SBP_ACKNOWLEDGE_EPHEMERIS_MASK          \
                                << SBP_ACKNOWLEDGE_EPHEMERIS_SHIFT))) | \
                    (((val) & (SBP_ACKNOWLEDGE_EPHEMERIS_MASK))         \
                     << (SBP_ACKNOWLEDGE_EPHEMERIS_SHIFT)));            \
  } while (0)

#define SBP_ACKNOWLEDGE_EPHEMERIS_NOT_REQUESTED (0)
#define SBP_ACKNOWLEDGE_EPHEMERIS_REQUESTED (1)
#define SBP_ACKNOWLEDGE_SATELLITE_CLOCK_MASK (0x1u)
#define SBP_ACKNOWLEDGE_SATELLITE_CLOCK_SHIFT (3u)
#define SBP_ACKNOWLEDGE_SATELLITE_CLOCK_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_ACKNOWLEDGE_SATELLITE_CLOCK_SHIFT) & \
         SBP_ACKNOWLEDGE_SATELLITE_CLOCK_MASK))
#define SBP_ACKNOWLEDGE_SATELLITE_CLOCK_SET(flags, val)                       \
  do {                                                                        \
    (flags) = (u16)((flags & (~(SBP_ACKNOWLEDGE_SATELLITE_CLOCK_MASK          \
                                << SBP_ACKNOWLEDGE_SATELLITE_CLOCK_SHIFT))) | \
                    (((val) & (SBP_ACKNOWLEDGE_SATELLITE_CLOCK_MASK))         \
                     << (SBP_ACKNOWLEDGE_SATELLITE_CLOCK_SHIFT)));            \
  } while (0)

#define SBP_ACKNOWLEDGE_SATELLITE_CLOCK_NOT_REQUESTED (0)
#define SBP_ACKNOWLEDGE_SATELLITE_CLOCK_REQUESTED (1)
#define SBP_ACKNOWLEDGE_SATELLITE_ORBIT_MASK (0x1u)
#define SBP_ACKNOWLEDGE_SATELLITE_ORBIT_SHIFT (4u)
#define SBP_ACKNOWLEDGE_SATELLITE_ORBIT_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_ACKNOWLEDGE_SATELLITE_ORBIT_SHIFT) & \
         SBP_ACKNOWLEDGE_SATELLITE_ORBIT_MASK))
#define SBP_ACKNOWLEDGE_SATELLITE_ORBIT_SET(flags, val)                       \
  do {                                                                        \
    (flags) = (u16)((flags & (~(SBP_ACKNOWLEDGE_SATELLITE_ORBIT_MASK          \
                                << SBP_ACKNOWLEDGE_SATELLITE_ORBIT_SHIFT))) | \
                    (((val) & (SBP_ACKNOWLEDGE_SATELLITE_ORBIT_MASK))         \
                     << (SBP_ACKNOWLEDGE_SATELLITE_ORBIT_SHIFT)));            \
  } while (0)

#define SBP_ACKNOWLEDGE_SATELLITE_ORBIT_NOT_REQUESTED (0)
#define SBP_ACKNOWLEDGE_SATELLITE_ORBIT_REQUESTED (1)
#define SBP_ACKNOWLEDGE_SATELLITE_CODE_BIAS_MASK (0x1u)
#define SBP_ACKNOWLEDGE_SATELLITE_CODE_BIAS_SHIFT (5u)
#define SBP_ACKNOWLEDGE_SATELLITE_CODE_BIAS_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_ACKNOWLEDGE_SATELLITE_CODE_BIAS_SHIFT) & \
         SBP_ACKNOWLEDGE_SATELLITE_CODE_BIAS_MASK))
#define SBP_ACKNOWLEDGE_SATELLITE_CODE_BIAS_SET(flags, val)                 \
  do {                                                                      \
    (flags) =                                                               \
        (u16)((flags & (~(SBP_ACKNOWLEDGE_SATELLITE_CODE_BIAS_MASK          \
                          << SBP_ACKNOWLEDGE_SATELLITE_CODE_BIAS_SHIFT))) | \
              (((val) & (SBP_ACKNOWLEDGE_SATELLITE_CODE_BIAS_MASK))         \
               << (SBP_ACKNOWLEDGE_SATELLITE_CODE_BIAS_SHIFT)));            \
  } while (0)

#define SBP_ACKNOWLEDGE_SATELLITE_CODE_BIAS_NOT_REQUESTED (0)
#define SBP_ACKNOWLEDGE_SATELLITE_CODE_BIAS_REQUESTED (1)
#define SBP_ACKNOWLEDGE_SATELLITE_PHASE_BIAS_MASK (0x1u)
#define SBP_ACKNOWLEDGE_SATELLITE_PHASE_BIAS_SHIFT (6u)
#define SBP_ACKNOWLEDGE_SATELLITE_PHASE_BIAS_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_ACKNOWLEDGE_SATELLITE_PHASE_BIAS_SHIFT) & \
         SBP_ACKNOWLEDGE_SATELLITE_PHASE_BIAS_MASK))
#define SBP_ACKNOWLEDGE_SATELLITE_PHASE_BIAS_SET(flags, val)                 \
  do {                                                                       \
    (flags) =                                                                \
        (u16)((flags & (~(SBP_ACKNOWLEDGE_SATELLITE_PHASE_BIAS_MASK          \
                          << SBP_ACKNOWLEDGE_SATELLITE_PHASE_BIAS_SHIFT))) | \
              (((val) & (SBP_ACKNOWLEDGE_SATELLITE_PHASE_BIAS_MASK))         \
               << (SBP_ACKNOWLEDGE_SATELLITE_PHASE_BIAS_SHIFT)));            \
  } while (0)

#define SBP_ACKNOWLEDGE_SATELLITE_PHASE_BIAS_NOT_REQUESTED (0)
#define SBP_ACKNOWLEDGE_SATELLITE_PHASE_BIAS_REQUESTED (1)
#define SBP_ACKNOWLEDGE_ATMOSPHERICS_MASK (0x1u)
#define SBP_ACKNOWLEDGE_ATMOSPHERICS_SHIFT (7u)
#define SBP_ACKNOWLEDGE_ATMOSPHERICS_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_ACKNOWLEDGE_ATMOSPHERICS_SHIFT) & \
         SBP_ACKNOWLEDGE_ATMOSPHERICS_MASK))
#define SBP_ACKNOWLEDGE_ATMOSPHERICS_SET(flags, val)                       \
  do {                                                                     \
    (flags) = (u16)((flags & (~(SBP_ACKNOWLEDGE_ATMOSPHERICS_MASK          \
                                << SBP_ACKNOWLEDGE_ATMOSPHERICS_SHIFT))) | \
                    (((val) & (SBP_ACKNOWLEDGE_ATMOSPHERICS_MASK))         \
                     << (SBP_ACKNOWLEDGE_ATMOSPHERICS_SHIFT)));            \
  } while (0)

#define SBP_ACKNOWLEDGE_ATMOSPHERICS_NOT_REQUESTED (0)
#define SBP_ACKNOWLEDGE_ATMOSPHERICS_REQUESTED (1)
#define SBP_ACKNOWLEDGE_INTEGRITY_MASK (0x1u)
#define SBP_ACKNOWLEDGE_INTEGRITY_SHIFT (8u)
#define SBP_ACKNOWLEDGE_INTEGRITY_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_ACKNOWLEDGE_INTEGRITY_SHIFT) & \
         SBP_ACKNOWLEDGE_INTEGRITY_MASK))
#define SBP_ACKNOWLEDGE_INTEGRITY_SET(flags, val)                       \
  do {                                                                  \
    (flags) = (u16)((flags & (~(SBP_ACKNOWLEDGE_INTEGRITY_MASK          \
                                << SBP_ACKNOWLEDGE_INTEGRITY_SHIFT))) | \
                    (((val) & (SBP_ACKNOWLEDGE_INTEGRITY_MASK))         \
                     << (SBP_ACKNOWLEDGE_INTEGRITY_SHIFT)));            \
  } while (0)

#define SBP_ACKNOWLEDGE_INTEGRITY_NOT_REQUESTED (0)
#define SBP_ACKNOWLEDGE_INTEGRITY_REQUESTED (1)
#define SBP_ACKNOWLEDGE_INTERMEDIATE_CERTIFICATE_MASK (0x1u)
#define SBP_ACKNOWLEDGE_INTERMEDIATE_CERTIFICATE_SHIFT (9u)
#define SBP_ACKNOWLEDGE_INTERMEDIATE_CERTIFICATE_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_ACKNOWLEDGE_INTERMEDIATE_CERTIFICATE_SHIFT) & \
         SBP_ACKNOWLEDGE_INTERMEDIATE_CERTIFICATE_MASK))
#define SBP_ACKNOWLEDGE_INTERMEDIATE_CERTIFICATE_SET(flags, val)           \
  do {                                                                     \
    (flags) = (u16)(                                                       \
        (flags & (~(SBP_ACKNOWLEDGE_INTERMEDIATE_CERTIFICATE_MASK          \
                    << SBP_ACKNOWLEDGE_INTERMEDIATE_CERTIFICATE_SHIFT))) | \
        (((val) & (SBP_ACKNOWLEDGE_INTERMEDIATE_CERTIFICATE_MASK))         \
         << (SBP_ACKNOWLEDGE_INTERMEDIATE_CERTIFICATE_SHIFT)));            \
  } while (0)

#define SBP_ACKNOWLEDGE_INTERMEDIATE_CERTIFICATE_NOT_REQUESTED (0)
#define SBP_ACKNOWLEDGE_INTERMEDIATE_CERTIFICATE_REQUESTED (1)
#define SBP_ACKNOWLEDGE_CERTIFICATE_CHAIN_MASK (0x1u)
#define SBP_ACKNOWLEDGE_CERTIFICATE_CHAIN_SHIFT (10u)
#define SBP_ACKNOWLEDGE_CERTIFICATE_CHAIN_GET(flags)                 \
  ((u16)((u16)((flags) >> SBP_ACKNOWLEDGE_CERTIFICATE_CHAIN_SHIFT) & \
         SBP_ACKNOWLEDGE_CERTIFICATE_CHAIN_MASK))
#define SBP_ACKNOWLEDGE_CERTIFICATE_CHAIN_SET(flags, val)                 \
  do {                                                                    \
    (flags) =                                                             \
        (u16)((flags & (~(SBP_ACKNOWLEDGE_CERTIFICATE_CHAIN_MASK          \
                          << SBP_ACKNOWLEDGE_CERTIFICATE_CHAIN_SHIFT))) | \
              (((val) & (SBP_ACKNOWLEDGE_CERTIFICATE_CHAIN_MASK))         \
               << (SBP_ACKNOWLEDGE_CERTIFICATE_CHAIN_SHIFT)));            \
  } while (0)

#define SBP_ACKNOWLEDGE_CERTIFICATE_CHAIN_NOT_REQUESTED (0)
#define SBP_ACKNOWLEDGE_CERTIFICATE_CHAIN_REQUESTED (1)
/**
 * Encoded length of sbp_msg_acknowledge_t (V4 API) and
 * msg_acknowledge_t (legacy API)
 */
#define SBP_MSG_ACKNOWLEDGE_ENCODED_LEN 11u

#endif /* LIBSBP_INTEGRITY_MACROS_H */
