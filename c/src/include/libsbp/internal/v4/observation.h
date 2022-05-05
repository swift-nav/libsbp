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
 * Automatically generated from yaml/swiftnav/sbp/observation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_INTERNAL_V4_OBSERVATION_H
#define LIBSBP_INTERNAL_V4_OBSERVATION_H

#include <stdbool.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/gnss.h>
#include <libsbp/v4/observation.h>

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
bool sbp_observation_header_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_observation_header_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_observation_header_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_observation_header_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_doppler_encode_internal(sbp_encode_ctx_t *ctx,
                                 const sbp_doppler_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_doppler_decode_internal(sbp_decode_ctx_t *ctx, sbp_doppler_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_packed_obs_content_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_packed_obs_content_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_packed_obs_content_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_packed_osr_content_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_packed_osr_content_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_packed_osr_content_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_packed_osr_content_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_obs_encode_internal(sbp_encode_ctx_t *ctx,
                                 const sbp_msg_obs_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_obs_decode_internal(sbp_decode_ctx_t *ctx, sbp_msg_obs_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_base_pos_llh_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_base_pos_llh_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_base_pos_llh_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_base_pos_llh_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_base_pos_ecef_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_base_pos_ecef_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_base_pos_ecef_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_base_pos_ecef_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_ephemeris_common_content_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_ephemeris_common_content_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_ephemeris_common_content_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_ephemeris_common_content_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_ephemeris_common_content_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_ephemeris_common_content_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_ephemeris_common_content_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_ephemeris_common_content_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_ephemeris_common_content_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_ephemeris_common_content_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_ephemeris_common_content_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_ephemeris_common_content_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_gps_dep_e_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_gps_dep_e_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_gps_dep_e_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_gps_dep_e_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_gps_dep_f_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_gps_dep_f_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_gps_dep_f_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_gps_dep_f_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_gps_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_ephemeris_gps_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_gps_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_ephemeris_gps_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_qzss_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_qzss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_qzss_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_ephemeris_qzss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_bds_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_ephemeris_bds_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_bds_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_ephemeris_bds_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_gal_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_gal_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_gal_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_gal_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_gal_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_ephemeris_gal_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_gal_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_ephemeris_gal_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_sbas_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_sbas_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_sbas_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_sbas_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_glo_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_glo_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_sbas_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_sbas_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_sbas_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_sbas_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_sbas_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_sbas_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_sbas_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_ephemeris_sbas_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_glo_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_glo_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_glo_dep_c_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_c_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_glo_dep_c_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_c_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_glo_dep_d_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_d_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_glo_dep_d_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_d_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_glo_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_ephemeris_glo_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_glo_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_ephemeris_glo_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_dep_d_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_dep_d_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_dep_d_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_ephemeris_dep_d_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_ephemeris_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_dep_b_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_ephemeris_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_dep_c_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_dep_c_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_ephemeris_dep_c_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_ephemeris_dep_c_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_observation_header_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_observation_header_dep_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_observation_header_dep_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_observation_header_dep_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_carrier_phase_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_carrier_phase_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_carrier_phase_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_carrier_phase_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_packed_obs_content_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_packed_obs_content_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_packed_obs_content_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_packed_obs_content_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_packed_obs_content_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_packed_obs_content_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_packed_obs_content_dep_c_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_dep_c_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_packed_obs_content_dep_c_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_packed_obs_content_dep_c_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_obs_dep_a_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_obs_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_obs_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_msg_obs_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_obs_dep_b_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_obs_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_obs_dep_b_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_msg_obs_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_obs_dep_c_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_obs_dep_c_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_obs_dep_c_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_msg_obs_dep_c_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_iono_encode_internal(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_iono_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_iono_decode_internal(sbp_decode_ctx_t *ctx, sbp_msg_iono_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_sv_configuration_gps_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_sv_configuration_gps_dep_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_sv_configuration_gps_dep_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_sv_configuration_gps_dep_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_gnss_capb_encode_internal(sbp_encode_ctx_t *ctx,
                                   const sbp_gnss_capb_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_gnss_capb_decode_internal(sbp_decode_ctx_t *ctx, sbp_gnss_capb_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_gnss_capb_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_gnss_capb_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_gnss_capb_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_msg_gnss_capb_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_group_delay_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_group_delay_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_group_delay_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_group_delay_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_group_delay_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_group_delay_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_group_delay_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_group_delay_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_group_delay_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_group_delay_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_group_delay_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_group_delay_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_almanac_common_content_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_almanac_common_content_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_almanac_common_content_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_almanac_common_content_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_almanac_common_content_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_almanac_common_content_dep_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_almanac_common_content_dep_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_almanac_common_content_dep_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_almanac_gps_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_almanac_gps_dep_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_almanac_gps_dep_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_almanac_gps_dep_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_almanac_gps_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_almanac_gps_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_almanac_gps_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_almanac_gps_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_almanac_glo_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_almanac_glo_dep_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_almanac_glo_dep_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_almanac_glo_dep_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_almanac_glo_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_almanac_glo_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_almanac_glo_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_almanac_glo_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_glo_biases_encode_internal(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_glo_biases_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_glo_biases_decode_internal(sbp_decode_ctx_t *ctx,
                                        sbp_msg_glo_biases_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_sv_az_el_encode_internal(sbp_encode_ctx_t *ctx,
                                  const sbp_sv_az_el_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_sv_az_el_decode_internal(sbp_decode_ctx_t *ctx, sbp_sv_az_el_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_sv_az_el_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_sv_az_el_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_sv_az_el_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_sv_az_el_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_osr_encode_internal(sbp_encode_ctx_t *ctx,
                                 const sbp_msg_osr_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_osr_decode_internal(sbp_decode_ctx_t *ctx, sbp_msg_osr_t *msg);

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_INTERNAL_V4_OBSERVATION_H */
