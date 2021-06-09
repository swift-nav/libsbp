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

#ifndef LIBSBP_INTERNAL_NEW_OBSERVATION_H
#define LIBSBP_INTERNAL_NEW_OBSERVATION_H

#include <stdbool.h>

#include <libsbp/internal/new/common.h>
#include <libsbp/internal/new/gnss.h>
#include <libsbp/new/observation.h>

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
bool encode_sbp_observation_header_t(sbp_encode_ctx_t *ctx,
                                     const sbp_observation_header_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_observation_header_t(sbp_decode_ctx_t *ctx,
                                     sbp_observation_header_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_doppler_t(sbp_encode_ctx_t *ctx, const sbp_doppler_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_doppler_t(sbp_decode_ctx_t *ctx, sbp_doppler_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_packed_obs_content_t(sbp_encode_ctx_t *ctx,
                                     const sbp_packed_obs_content_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_packed_obs_content_t(sbp_decode_ctx_t *ctx,
                                     sbp_packed_obs_content_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_packed_osr_content_t(sbp_encode_ctx_t *ctx,
                                     const sbp_packed_osr_content_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_packed_osr_content_t(sbp_decode_ctx_t *ctx,
                                     sbp_packed_osr_content_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_obs_t(sbp_encode_ctx_t *ctx, const sbp_msg_obs_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_obs_t(sbp_decode_ctx_t *ctx, sbp_msg_obs_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_base_pos_llh_t(sbp_encode_ctx_t *ctx,
                                   const sbp_msg_base_pos_llh_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_base_pos_llh_t(sbp_decode_ctx_t *ctx,
                                   sbp_msg_base_pos_llh_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_base_pos_ecef_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_base_pos_ecef_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_base_pos_ecef_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_base_pos_ecef_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_ephemeris_common_content_t(
    sbp_encode_ctx_t *ctx, const sbp_ephemeris_common_content_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_ephemeris_common_content_t(sbp_decode_ctx_t *ctx,
                                           sbp_ephemeris_common_content_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_ephemeris_common_content_dep_b_t(
    sbp_encode_ctx_t *ctx, const sbp_ephemeris_common_content_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_ephemeris_common_content_dep_b_t(
    sbp_decode_ctx_t *ctx, sbp_ephemeris_common_content_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_ephemeris_common_content_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_ephemeris_common_content_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_ephemeris_common_content_dep_a_t(
    sbp_decode_ctx_t *ctx, sbp_ephemeris_common_content_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_gps_dep_e_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_gps_dep_e_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_gps_dep_e_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_ephemeris_gps_dep_e_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_gps_dep_f_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_gps_dep_f_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_gps_dep_f_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_ephemeris_gps_dep_f_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_gps_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_ephemeris_gps_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_gps_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_ephemeris_gps_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_qzss_t(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_ephemeris_qzss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_qzss_t(sbp_decode_ctx_t *ctx,
                                     sbp_msg_ephemeris_qzss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_bds_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_ephemeris_bds_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_bds_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_ephemeris_bds_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_gal_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_gal_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_gal_dep_a_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_ephemeris_gal_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_gal_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_ephemeris_gal_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_gal_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_ephemeris_gal_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_sbas_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_sbas_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_sbas_dep_a_t(sbp_decode_ctx_t *ctx,
                                           sbp_msg_ephemeris_sbas_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_glo_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_glo_dep_a_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_ephemeris_glo_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_sbas_dep_b_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_sbas_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_sbas_dep_b_t(sbp_decode_ctx_t *ctx,
                                           sbp_msg_ephemeris_sbas_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_sbas_t(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_ephemeris_sbas_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_sbas_t(sbp_decode_ctx_t *ctx,
                                     sbp_msg_ephemeris_sbas_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_glo_dep_b_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_glo_dep_b_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_ephemeris_glo_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_glo_dep_c_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_c_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_glo_dep_c_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_ephemeris_glo_dep_c_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_glo_dep_d_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_d_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_glo_dep_d_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_ephemeris_glo_dep_d_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_glo_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_ephemeris_glo_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_glo_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_ephemeris_glo_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_dep_d_t(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_ephemeris_dep_d_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_dep_d_t(sbp_decode_ctx_t *ctx,
                                      sbp_msg_ephemeris_dep_d_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_dep_a_t(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_ephemeris_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_dep_a_t(sbp_decode_ctx_t *ctx,
                                      sbp_msg_ephemeris_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_dep_b_t(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_ephemeris_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_dep_b_t(sbp_decode_ctx_t *ctx,
                                      sbp_msg_ephemeris_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ephemeris_dep_c_t(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_ephemeris_dep_c_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ephemeris_dep_c_t(sbp_decode_ctx_t *ctx,
                                      sbp_msg_ephemeris_dep_c_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_observation_header_dep_t(
    sbp_encode_ctx_t *ctx, const sbp_observation_header_dep_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_observation_header_dep_t(sbp_decode_ctx_t *ctx,
                                         sbp_observation_header_dep_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_carrier_phase_dep_a_t(sbp_encode_ctx_t *ctx,
                                      const sbp_carrier_phase_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_carrier_phase_dep_a_t(sbp_decode_ctx_t *ctx,
                                      sbp_carrier_phase_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_packed_obs_content_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_packed_obs_content_dep_a_t(sbp_decode_ctx_t *ctx,
                                           sbp_packed_obs_content_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_packed_obs_content_dep_b_t(
    sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_packed_obs_content_dep_b_t(sbp_decode_ctx_t *ctx,
                                           sbp_packed_obs_content_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_packed_obs_content_dep_c_t(
    sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_dep_c_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_packed_obs_content_dep_c_t(sbp_decode_ctx_t *ctx,
                                           sbp_packed_obs_content_dep_c_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_obs_dep_a_t(sbp_encode_ctx_t *ctx,
                                const sbp_msg_obs_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_obs_dep_a_t(sbp_decode_ctx_t *ctx,
                                sbp_msg_obs_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_obs_dep_b_t(sbp_encode_ctx_t *ctx,
                                const sbp_msg_obs_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_obs_dep_b_t(sbp_decode_ctx_t *ctx,
                                sbp_msg_obs_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_obs_dep_c_t(sbp_encode_ctx_t *ctx,
                                const sbp_msg_obs_dep_c_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_obs_dep_c_t(sbp_decode_ctx_t *ctx,
                                sbp_msg_obs_dep_c_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_iono_t(sbp_encode_ctx_t *ctx, const sbp_msg_iono_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_iono_t(sbp_decode_ctx_t *ctx, sbp_msg_iono_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_sv_configuration_gps_dep_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_sv_configuration_gps_dep_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_sv_configuration_gps_dep_t(
    sbp_decode_ctx_t *ctx, sbp_msg_sv_configuration_gps_dep_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_gnss_capb_t(sbp_encode_ctx_t *ctx, const sbp_gnss_capb_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_gnss_capb_t(sbp_decode_ctx_t *ctx, sbp_gnss_capb_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_gnss_capb_t(sbp_encode_ctx_t *ctx,
                                const sbp_msg_gnss_capb_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_gnss_capb_t(sbp_decode_ctx_t *ctx,
                                sbp_msg_gnss_capb_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_group_delay_dep_a_t(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_group_delay_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_group_delay_dep_a_t(sbp_decode_ctx_t *ctx,
                                        sbp_msg_group_delay_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_group_delay_dep_b_t(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_group_delay_dep_b_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_group_delay_dep_b_t(sbp_decode_ctx_t *ctx,
                                        sbp_msg_group_delay_dep_b_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_group_delay_t(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_group_delay_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_group_delay_t(sbp_decode_ctx_t *ctx,
                                  sbp_msg_group_delay_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_almanac_common_content_t(
    sbp_encode_ctx_t *ctx, const sbp_almanac_common_content_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_almanac_common_content_t(sbp_decode_ctx_t *ctx,
                                         sbp_almanac_common_content_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_almanac_common_content_dep_t(
    sbp_encode_ctx_t *ctx, const sbp_almanac_common_content_dep_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_almanac_common_content_dep_t(
    sbp_decode_ctx_t *ctx, sbp_almanac_common_content_dep_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_almanac_gps_dep_t(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_almanac_gps_dep_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_almanac_gps_dep_t(sbp_decode_ctx_t *ctx,
                                      sbp_msg_almanac_gps_dep_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_almanac_gps_t(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_almanac_gps_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_almanac_gps_t(sbp_decode_ctx_t *ctx,
                                  sbp_msg_almanac_gps_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_almanac_glo_dep_t(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_almanac_glo_dep_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_almanac_glo_dep_t(sbp_decode_ctx_t *ctx,
                                      sbp_msg_almanac_glo_dep_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_almanac_glo_t(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_almanac_glo_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_almanac_glo_t(sbp_decode_ctx_t *ctx,
                                  sbp_msg_almanac_glo_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_glo_biases_t(sbp_encode_ctx_t *ctx,
                                 const sbp_msg_glo_biases_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_glo_biases_t(sbp_decode_ctx_t *ctx,
                                 sbp_msg_glo_biases_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_sv_az_el_t(sbp_encode_ctx_t *ctx, const sbp_sv_az_el_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_sv_az_el_t(sbp_decode_ctx_t *ctx, sbp_sv_az_el_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_sv_az_el_t(sbp_encode_ctx_t *ctx,
                               const sbp_msg_sv_az_el_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_sv_az_el_t(sbp_decode_ctx_t *ctx, sbp_msg_sv_az_el_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_osr_t(sbp_encode_ctx_t *ctx, const sbp_msg_osr_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_osr_t(sbp_decode_ctx_t *ctx, sbp_msg_osr_t *msg);

#ifdef __cplusplus
}
#endif

#endif
