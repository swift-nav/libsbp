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
 * Automatically generated from yaml/swiftnav/sbp/system.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_INTERNAL_NEW_SYSTEM_H
#define LIBSBP_INTERNAL_NEW_SYSTEM_H

#include <stdbool.h>

#include <libsbp/internal/new/common.h>
#include <libsbp/new/system.h>

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
bool encode_sbp_msg_startup_t(sbp_encode_ctx_t *ctx,
                              const sbp_msg_startup_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_startup_t(sbp_decode_ctx_t *ctx, sbp_msg_startup_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_dgnss_status_t(sbp_encode_ctx_t *ctx,
                                   const sbp_msg_dgnss_status_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_dgnss_status_t(sbp_decode_ctx_t *ctx,
                                   sbp_msg_dgnss_status_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_heartbeat_t(sbp_encode_ctx_t *ctx,
                                const sbp_msg_heartbeat_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_heartbeat_t(sbp_decode_ctx_t *ctx,
                                sbp_msg_heartbeat_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_sub_system_report_t(sbp_encode_ctx_t *ctx,
                                    const sbp_sub_system_report_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_sub_system_report_t(sbp_decode_ctx_t *ctx,
                                    sbp_sub_system_report_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_status_report_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_status_report_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_status_report_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_status_report_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ins_status_t(sbp_encode_ctx_t *ctx,
                                 const sbp_msg_ins_status_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ins_status_t(sbp_decode_ctx_t *ctx,
                                 sbp_msg_ins_status_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_csac_telemetry_t(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_csac_telemetry_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_csac_telemetry_t(sbp_decode_ctx_t *ctx,
                                     sbp_msg_csac_telemetry_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_csac_telemetry_labels_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_csac_telemetry_labels_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_csac_telemetry_labels_t(
    sbp_decode_ctx_t *ctx, sbp_msg_csac_telemetry_labels_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_ins_updates_t(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_ins_updates_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_ins_updates_t(sbp_decode_ctx_t *ctx,
                                  sbp_msg_ins_updates_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_gnss_time_offset_t(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_gnss_time_offset_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_gnss_time_offset_t(sbp_decode_ctx_t *ctx,
                                       sbp_msg_gnss_time_offset_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_pps_time_t(sbp_encode_ctx_t *ctx,
                               const sbp_msg_pps_time_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_pps_time_t(sbp_decode_ctx_t *ctx, sbp_msg_pps_time_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_group_meta_t(sbp_encode_ctx_t *ctx,
                                 const sbp_msg_group_meta_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_group_meta_t(sbp_decode_ctx_t *ctx,
                                 sbp_msg_group_meta_t *msg);

#ifdef __cplusplus
}
#endif

#endif
