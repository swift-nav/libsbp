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
 * Automatically generated from yaml/swiftnav/sbp/navigation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_INTERNAL_NEW_NAVIGATION_H
#define LIBSBP_INTERNAL_NEW_NAVIGATION_H

#include <stdbool.h>

#include <libsbp/internal/new/common.h>
#include <libsbp/new/navigation.h>

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
bool encode_sbp_msg_gps_time_t(sbp_encode_ctx_t *ctx,
                               const sbp_msg_gps_time_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_gps_time_t(sbp_decode_ctx_t *ctx, sbp_msg_gps_time_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_gps_time_gnss_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_gps_time_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_gps_time_gnss_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_gps_time_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_utc_time_t(sbp_encode_ctx_t *ctx,
                               const sbp_msg_utc_time_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_utc_time_t(sbp_decode_ctx_t *ctx, sbp_msg_utc_time_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_utc_time_gnss_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_utc_time_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_utc_time_gnss_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_utc_time_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_dops_t(sbp_encode_ctx_t *ctx, const sbp_msg_dops_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_dops_t(sbp_decode_ctx_t *ctx, sbp_msg_dops_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_pos_ecef_t(sbp_encode_ctx_t *ctx,
                               const sbp_msg_pos_ecef_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_pos_ecef_t(sbp_decode_ctx_t *ctx, sbp_msg_pos_ecef_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_pos_ecef_cov_t(sbp_encode_ctx_t *ctx,
                                   const sbp_msg_pos_ecef_cov_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_pos_ecef_cov_t(sbp_decode_ctx_t *ctx,
                                   sbp_msg_pos_ecef_cov_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_pos_llh_t(sbp_encode_ctx_t *ctx,
                              const sbp_msg_pos_llh_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_pos_llh_t(sbp_decode_ctx_t *ctx, sbp_msg_pos_llh_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_pos_llh_cov_t(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_pos_llh_cov_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_pos_llh_cov_t(sbp_decode_ctx_t *ctx,
                                  sbp_msg_pos_llh_cov_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_baseline_ecef_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_baseline_ecef_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_baseline_ecef_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_baseline_ecef_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_baseline_ned_t(sbp_encode_ctx_t *ctx,
                                   const sbp_msg_baseline_ned_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_baseline_ned_t(sbp_decode_ctx_t *ctx,
                                   sbp_msg_baseline_ned_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_vel_ecef_t(sbp_encode_ctx_t *ctx,
                               const sbp_msg_vel_ecef_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_vel_ecef_t(sbp_decode_ctx_t *ctx, sbp_msg_vel_ecef_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_vel_ecef_cov_t(sbp_encode_ctx_t *ctx,
                                   const sbp_msg_vel_ecef_cov_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_vel_ecef_cov_t(sbp_decode_ctx_t *ctx,
                                   sbp_msg_vel_ecef_cov_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_vel_ned_t(sbp_encode_ctx_t *ctx,
                              const sbp_msg_vel_ned_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_vel_ned_t(sbp_decode_ctx_t *ctx, sbp_msg_vel_ned_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_vel_ned_cov_t(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_vel_ned_cov_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_vel_ned_cov_t(sbp_decode_ctx_t *ctx,
                                  sbp_msg_vel_ned_cov_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_pos_ecef_gnss_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_pos_ecef_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_pos_ecef_gnss_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_pos_ecef_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_pos_ecef_cov_gnss_t(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_pos_ecef_cov_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_pos_ecef_cov_gnss_t(sbp_decode_ctx_t *ctx,
                                        sbp_msg_pos_ecef_cov_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_pos_llh_gnss_t(sbp_encode_ctx_t *ctx,
                                   const sbp_msg_pos_llh_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_pos_llh_gnss_t(sbp_decode_ctx_t *ctx,
                                   sbp_msg_pos_llh_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_pos_llh_cov_gnss_t(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_pos_llh_cov_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_pos_llh_cov_gnss_t(sbp_decode_ctx_t *ctx,
                                       sbp_msg_pos_llh_cov_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_vel_ecef_gnss_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_vel_ecef_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_vel_ecef_gnss_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_vel_ecef_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_vel_ecef_cov_gnss_t(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_vel_ecef_cov_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_vel_ecef_cov_gnss_t(sbp_decode_ctx_t *ctx,
                                        sbp_msg_vel_ecef_cov_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_vel_ned_gnss_t(sbp_encode_ctx_t *ctx,
                                   const sbp_msg_vel_ned_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_vel_ned_gnss_t(sbp_decode_ctx_t *ctx,
                                   sbp_msg_vel_ned_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_vel_ned_cov_gnss_t(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_vel_ned_cov_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_vel_ned_cov_gnss_t(sbp_decode_ctx_t *ctx,
                                       sbp_msg_vel_ned_cov_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_vel_body_t(sbp_encode_ctx_t *ctx,
                               const sbp_msg_vel_body_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_vel_body_t(sbp_decode_ctx_t *ctx, sbp_msg_vel_body_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_age_corrections_t(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_age_corrections_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_age_corrections_t(sbp_decode_ctx_t *ctx,
                                      sbp_msg_age_corrections_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_gps_time_dep_a_t(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_gps_time_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_gps_time_dep_a_t(sbp_decode_ctx_t *ctx,
                                     sbp_msg_gps_time_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_dops_dep_a_t(sbp_encode_ctx_t *ctx,
                                 const sbp_msg_dops_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_dops_dep_a_t(sbp_decode_ctx_t *ctx,
                                 sbp_msg_dops_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_pos_ecef_dep_a_t(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_pos_ecef_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_pos_ecef_dep_a_t(sbp_decode_ctx_t *ctx,
                                     sbp_msg_pos_ecef_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_pos_llh_dep_a_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_pos_llh_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_pos_llh_dep_a_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_pos_llh_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_baseline_ecef_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_baseline_ecef_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_baseline_ecef_dep_a_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_baseline_ecef_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_baseline_ned_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_baseline_ned_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_baseline_ned_dep_a_t(sbp_decode_ctx_t *ctx,
                                         sbp_msg_baseline_ned_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_vel_ecef_dep_a_t(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_vel_ecef_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_vel_ecef_dep_a_t(sbp_decode_ctx_t *ctx,
                                     sbp_msg_vel_ecef_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_vel_ned_dep_a_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_vel_ned_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_vel_ned_dep_a_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_vel_ned_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_baseline_heading_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_baseline_heading_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_baseline_heading_dep_a_t(
    sbp_decode_ctx_t *ctx, sbp_msg_baseline_heading_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_protection_level_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_protection_level_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_protection_level_dep_a_t(
    sbp_decode_ctx_t *ctx, sbp_msg_protection_level_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_protection_level_t(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_protection_level_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_protection_level_t(sbp_decode_ctx_t *ctx,
                                       sbp_msg_protection_level_t *msg);

#ifdef __cplusplus
}
#endif

#endif
