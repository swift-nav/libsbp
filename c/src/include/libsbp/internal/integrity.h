/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/integrity.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_INTERNAL_INTEGRITY_H
#define LIBSBP_INTERNAL_INTEGRITY_H

#include <stdbool.h>

#include <libsbp/integrity.h>
#include <libsbp/internal/common.h>
#include <libsbp/internal/gnss.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_integrity_ssr_header_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_integrity_ssr_header_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_integrity_ssr_header_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_integrity_ssr_header_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_flag_high_level_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_flag_high_level_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_flag_high_level_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_flag_high_level_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_flag_satellites_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_flag_satellites_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_flag_satellites_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_flag_satellites_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_flag_tropo_grid_points_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_flag_tropo_grid_points_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_flag_tropo_grid_points_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_flag_tropo_grid_points_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_flag_iono_grid_points_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_flag_iono_grid_points_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_flag_iono_grid_points_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_flag_iono_grid_points_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_flag_iono_tile_sat_los_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_flag_iono_tile_sat_los_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_flag_iono_tile_sat_los_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_flag_iono_tile_sat_los_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_flag_iono_grid_point_sat_los_encode_internal(
    sbp_encode_ctx_t *ctx,
    const sbp_msg_ssr_flag_iono_grid_point_sat_los_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_flag_iono_grid_point_sat_los_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_flag_iono_grid_point_sat_los_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_acknowledge_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_acknowledge_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_acknowledge_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_acknowledge_t *msg);

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_INTERNAL_INTEGRITY_H */
