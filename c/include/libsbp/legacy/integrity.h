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
  u8 stub[0];
} msg_ssr_flag_high_level_t;

typedef struct SBP_ATTR_PACKED {
  u8 stub[0];
} msg_ssr_flag_satellites_t;

typedef struct SBP_ATTR_PACKED {
  u8 stub[0];
} msg_ssr_flag_tropo_grid_points_t;

typedef struct SBP_ATTR_PACKED {
  u8 stub[0];
} msg_ssr_flag_iono_grid_points_t;

typedef struct SBP_ATTR_PACKED {
  u8 stub[0];
} msg_ssr_flag_iono_tile_sat_los_t;

typedef struct SBP_ATTR_PACKED {
  u8 stub[0];
} msg_ssr_flag_iono_grid_point_sat_los_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_INTEGRITY_MESSAGES_H */