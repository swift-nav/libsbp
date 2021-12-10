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

#ifndef LIBSBP_INTERNAL_V4_NAVIGATION_H
#define LIBSBP_INTERNAL_V4_NAVIGATION_H

#include <stdbool.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/v4/navigation.h>

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
bool sbp_msg_gps_time_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_gps_time_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_gps_time_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_gps_time_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_gps_time_gnss_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_gps_time_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_gps_time_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_gps_time_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_utc_time_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_utc_time_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_utc_time_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_utc_time_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_utc_time_gnss_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_utc_time_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_utc_time_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_utc_time_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_dops_encode_internal(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_dops_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_dops_decode_internal(sbp_decode_ctx_t *ctx, sbp_msg_dops_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_ecef_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_pos_ecef_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_ecef_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_pos_ecef_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_ecef_cov_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_pos_ecef_cov_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_ecef_cov_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_pos_ecef_cov_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_llh_encode_internal(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_pos_llh_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_llh_decode_internal(sbp_decode_ctx_t *ctx,
                                     sbp_msg_pos_llh_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_llh_cov_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_pos_llh_cov_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_llh_cov_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_pos_llh_cov_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_estimated_horizontal_error_ellipse_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_estimated_horizontal_error_ellipse_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_estimated_horizontal_error_ellipse_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_estimated_horizontal_error_ellipse_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_llh_acc_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_pos_llh_acc_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_llh_acc_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_pos_llh_acc_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_baseline_ecef_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_baseline_ecef_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_baseline_ecef_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_baseline_ecef_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_baseline_ned_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_baseline_ned_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_baseline_ned_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_baseline_ned_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ecef_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_vel_ecef_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ecef_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_vel_ecef_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ecef_cov_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_vel_ecef_cov_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ecef_cov_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_vel_ecef_cov_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ned_encode_internal(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_vel_ned_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ned_decode_internal(sbp_decode_ctx_t *ctx,
                                     sbp_msg_vel_ned_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ned_cov_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_vel_ned_cov_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ned_cov_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_vel_ned_cov_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_ecef_gnss_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_pos_ecef_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_ecef_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_pos_ecef_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_ecef_cov_gnss_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_pos_ecef_cov_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_ecef_cov_gnss_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_pos_ecef_cov_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_llh_gnss_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_pos_llh_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_llh_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_pos_llh_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_llh_cov_gnss_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_pos_llh_cov_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_llh_cov_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_msg_pos_llh_cov_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ecef_gnss_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_vel_ecef_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ecef_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_vel_ecef_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ecef_cov_gnss_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_vel_ecef_cov_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ecef_cov_gnss_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_vel_ecef_cov_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ned_gnss_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_vel_ned_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ned_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_vel_ned_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ned_cov_gnss_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_vel_ned_cov_gnss_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ned_cov_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_msg_vel_ned_cov_gnss_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_body_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_vel_body_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_body_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_vel_body_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_cog_encode_internal(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_vel_cog_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_cog_decode_internal(sbp_decode_ctx_t *ctx,
                                     sbp_msg_vel_cog_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_age_corrections_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_age_corrections_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_age_corrections_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_age_corrections_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_gps_time_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_gps_time_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_gps_time_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_gps_time_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_dops_dep_a_encode_internal(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_dops_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_dops_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                        sbp_msg_dops_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_ecef_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_pos_ecef_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_ecef_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_pos_ecef_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_llh_dep_a_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_pos_llh_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_pos_llh_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_pos_llh_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_baseline_ecef_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_baseline_ecef_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_baseline_ecef_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_baseline_ecef_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_baseline_ned_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_baseline_ned_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_baseline_ned_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_baseline_ned_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ecef_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_vel_ecef_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ecef_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_vel_ecef_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ned_dep_a_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_vel_ned_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_vel_ned_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_vel_ned_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_baseline_heading_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_baseline_heading_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_baseline_heading_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_baseline_heading_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_protection_level_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_protection_level_dep_a_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_protection_level_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_protection_level_dep_a_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_protection_level_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_protection_level_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool sbp_msg_protection_level_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_msg_protection_level_t *msg);

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_INTERNAL_V4_NAVIGATION_H */
