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

/** \defgroup integrity Integrity
 *
 * Integrity flag messages
 * \{ */

#ifndef LIBSBP_LEGACY_INTEGRITY_MESSAGES_H
#define LIBSBP_LEGACY_INTEGRITY_MESSAGES_H

#include <libsbp/common.h>

#include <libsbp/integrity_macros.h>
#include <libsbp/legacy/gnss.h>

SBP_PACK_START

typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t obs_time; /**< GNSS reference time of the observation
                                used to generate the flag. */
  u8 num_msgs;             /**< Number of messages in the dataset */
  u8 seq_num;              /**< Position of this message in the dataset */
  u8 ssr_sol_id;           /**< SSR Solution ID. */
  u16 tile_set_id; /**< Unique identifier of the set this tile belongs to. */
  u16 tile_id;     /**< Unique identifier of this tile in the tile set. */
  u8 chain_id;     /**< Chain and type of flag. */
} integrity_ssr_header_t;

/** High level integrity flags
 *
 * Integrity monitoring flags for multiple aggregated elements. An element
 * could be a satellite, SSR grid point, or SSR tile. A group of aggregated
 * elements being monitored for integrity could refer to:
 *
 * - Satellites in a particular {GPS, GAL, BDS} constellation.
 *
 * - Satellites in the line-of-sight of a particular SSR tile.
 *
 * - Satellites in the line-of-sight of a particular SSR grid point.
 *
 * The integrity usage for a group of aggregated elements varies according to
 * the integrity flag of the satellites comprising that group.
 *
 * SSR_INTEGRITY_USAGE_NOMINAL: All satellites received passed the integrity
 * check and have flag INTEGRITY_FLAG_OK.
 *
 * SSR_INTEGRITY_USAGE_WARNING: A limited number of elements in the group
 * failed the integrity check. Refer to more granular integrity messages for
 * details on the specific failing elements.
 *
 * SSR_INTEGRITY_USAGE_ALERT: Most elements in the group failed the integrity
 * check, do not use for positioning.
 *
 * SSR_INTEGRITY_USAGE_NOT_MONITORED: Unable to verify the integrity flag of
 * elements in the group.
 */

typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t obs_time;        /**< GNSS reference time of
                                       the observation used to
                                       generate the flag. */
  gps_time_sec_t corr_time;       /**< GNSS reference time of
                                       the correction
                                       associated to the flag. */
  u8 ssr_sol_id;                  /**< SSR Solution ID. */
  u16 tile_set_id;                /**< Unique identifier of the set this
                                       tile belongs to. */
  u16 tile_id;                    /**< Unique identifier of this tile in
                                       the tile set. */
  u8 chain_id;                    /**< Chain and type of flag. */
  u8 use_gps_sat;                 /**< Use GPS satellites. */
  u8 use_gal_sat;                 /**< Use GAL satellites. */
  u8 use_bds_sat;                 /**< Use BDS satellites. */
  u8 reserved[6];                 /**< Reserved */
  u8 use_tropo_grid_points;       /**< Use tropo grid points. */
  u8 use_iono_grid_points;        /**< Use iono grid points. */
  u8 use_iono_tile_sat_los;       /**< Use iono tile satellite LoS. */
  u8 use_iono_grid_point_sat_los; /**< Use iono grid point satellite LoS. */
} msg_ssr_flag_high_level_t;

typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t obs_time; /**< GNSS reference time of the observation
                                used to generate the flag. */
  u8 num_msgs;             /**< Number of messages in the dataset */
  u8 seq_num;              /**< Position of this message in the dataset */
  u8 ssr_sol_id;           /**< SSR Solution ID. */
  u8 chain_id;             /**< Chain and type of flag. */
  u8 const_id;             /**< Constellation ID. */
  u8 n_faulty_sats;        /**< Number of faulty satellites. */
  u8 faulty_sats[0];       /**< List of faulty satellites. */
} msg_ssr_flag_satellites_t;

typedef struct SBP_ATTR_PACKED {
  integrity_ssr_header_t header; /**< Header of an integrity
                                      message. */
  u8 n_faulty_points;            /**< Number of faulty grid points. */
  u16 faulty_points[0];          /**< List of faulty grid points. */
} msg_ssr_flag_tropo_grid_points_t;

typedef struct SBP_ATTR_PACKED {
  integrity_ssr_header_t header; /**< Header of an integrity
                                      message. */
  u8 n_faulty_points;            /**< Number of faulty grid points. */
  u16 faulty_points[0];          /**< List of faulty grid points. */
} msg_ssr_flag_iono_grid_points_t;

typedef struct SBP_ATTR_PACKED {
  integrity_ssr_header_t header; /**< Header of an integrity message. */
  u8 n_faulty_los;               /**< Number of faulty LOS. */
  sv_id_t faulty_los[0];         /**< List of faulty LOS */
} msg_ssr_flag_iono_tile_sat_los_t;

typedef struct SBP_ATTR_PACKED {
  integrity_ssr_header_t header; /**< Header of an integrity
                                      message. */
  u16 grid_point_id;             /**< Index of the grid point. */
  u8 n_faulty_los;               /**< Number of faulty LOS. */
  sv_id_t faulty_los[0];         /**< List of faulty LOS */
} msg_ssr_flag_iono_grid_point_sat_los_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_INTEGRITY_MESSAGES_H */