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

#ifndef LIBSBP_INTERNAL_V4_SSR_H
#define LIBSBP_INTERNAL_V4_SSR_H

#include <stdbool.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/gnss.h>
#include <libsbp/v4/ssr.h>

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
bool sbp_code_biases_content_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_code_biases_content_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_code_biases_content_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_code_biases_content_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_phase_biases_content_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_phase_biases_content_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_phase_biases_content_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_phase_biases_content_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_stec_header_encode_internal(sbp_encode_ctx_t *ctx,
                                     const sbp_stec_header_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_stec_header_decode_internal(sbp_decode_ctx_t *ctx,
                                     sbp_stec_header_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_gridded_correction_header_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_gridded_correction_header_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_gridded_correction_header_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_gridded_correction_header_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_stec_sat_element_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_stec_sat_element_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_stec_sat_element_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_stec_sat_element_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_tropospheric_delay_correction_no_std_encode_internal(
    sbp_encode_ctx_t *ctx,
    const sbp_tropospheric_delay_correction_no_std_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_tropospheric_delay_correction_no_std_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_tropospheric_delay_correction_no_std_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_tropospheric_delay_correction_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_tropospheric_delay_correction_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_tropospheric_delay_correction_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_tropospheric_delay_correction_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_stec_residual_no_std_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_stec_residual_no_std_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_stec_residual_no_std_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_stec_residual_no_std_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_stec_residual_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_stec_residual_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_stec_residual_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_stec_residual_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_orbit_clock_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_orbit_clock_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_orbit_clock_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_ssr_orbit_clock_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_code_biases_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_code_biases_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_code_biases_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_ssr_code_biases_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_phase_biases_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_phase_biases_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_phase_biases_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_msg_ssr_phase_biases_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_stec_correction_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_stec_correction_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_stec_correction_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_stec_correction_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_gridded_correction_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_gridded_correction_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_gridded_correction_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_gridded_correction_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_tile_definition_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_tile_definition_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_tile_definition_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_tile_definition_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_satellite_apc_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_satellite_apc_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_satellite_apc_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_satellite_apc_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_satellite_apc_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_satellite_apc_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_satellite_apc_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_satellite_apc_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_orbit_clock_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_orbit_clock_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_orbit_clock_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_orbit_clock_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_stec_header_dep_a_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_stec_header_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_stec_header_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_stec_header_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_gridded_correction_header_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_gridded_correction_header_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_gridded_correction_header_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_gridded_correction_header_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_grid_definition_header_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_grid_definition_header_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_grid_definition_header_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_grid_definition_header_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_stec_correction_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_stec_correction_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_stec_correction_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_stec_correction_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_gridded_correction_no_std_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx,
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_gridded_correction_no_std_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_gridded_correction_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_gridded_correction_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_gridded_correction_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_gridded_correction_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_grid_definition_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_grid_definition_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ssr_grid_definition_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_grid_definition_dep_a_t *msg);

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_INTERNAL_V4_SSR_H */
