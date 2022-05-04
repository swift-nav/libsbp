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

#define SBP_MSG_SSR_FLAG_HIGH_LEVEL 0x0BB9
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_flag_high_level_t::stub (V4 API) or
 * msg_ssr_flag_high_level_t::stub (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_SSR_FLAG_HIGH_LEVEL_STUB_MAX 255u

/**
 * Encoded length of sbp_msg_ssr_flag_high_level_t (V4 API) and
 * msg_ssr_flag_high_level_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ssr_flag_high_level_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_FLAG_HIGH_LEVEL_ENCODED_OVERHEAD 0u

#define SBP_MSG_SSR_FLAG_SATELLITES 0x0BBD
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_flag_satellites_t::stub (V4 API) or
 * msg_ssr_flag_satellites_t::stub (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_SSR_FLAG_SATELLITES_STUB_MAX 255u

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
#define SBP_MSG_SSR_FLAG_SATELLITES_ENCODED_OVERHEAD 0u

#define SBP_MSG_SSR_FLAG_TROPO_GRID_POINTS 0x0BC3
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_flag_tropo_grid_points_t::stub (V4 API) or
 * msg_ssr_flag_tropo_grid_points_t::stub (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SSR_FLAG_TROPO_GRID_POINTS_STUB_MAX 255u

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
#define SBP_MSG_SSR_FLAG_TROPO_GRID_POINTS_ENCODED_OVERHEAD 0u

#define SBP_MSG_SSR_FLAG_IONO_GRID_POINTS 0x0BC7
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_flag_iono_grid_points_t::stub (V4 API) or
 * msg_ssr_flag_iono_grid_points_t::stub (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SSR_FLAG_IONO_GRID_POINTS_STUB_MAX 255u

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
#define SBP_MSG_SSR_FLAG_IONO_GRID_POINTS_ENCODED_OVERHEAD 0u

#define SBP_MSG_SSR_FLAG_IONO_TILE_SAT_LOS 0x0BCD
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_flag_iono_tile_sat_los_t::stub (V4 API) or
 * msg_ssr_flag_iono_tile_sat_los_t::stub (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SSR_FLAG_IONO_TILE_SAT_LOS_STUB_MAX 255u

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
#define SBP_MSG_SSR_FLAG_IONO_TILE_SAT_LOS_ENCODED_OVERHEAD 0u

#define SBP_MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS 0x0BD1
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_flag_iono_grid_point_sat_los_t::stub (V4 API) or
 * msg_ssr_flag_iono_grid_point_sat_los_t::stub (legacy API) before the maximum
 * SBP message size is exceeded
 */
#define SBP_MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS_STUB_MAX 255u

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
#define SBP_MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS_ENCODED_OVERHEAD 0u

#endif /* LIBSBP_INTEGRITY_MACROS_H */
