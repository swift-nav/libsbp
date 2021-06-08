/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
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
 * Automatically generated from yaml/swiftnav/sbp/gnss.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_UNPACKED_GNSS_PRIVATE_H
#define LIBSBP_UNPACKED_GNSS_PRIVATE_H

#include <stdbool.h>

#include <libsbp/internal/new/common.h>
#include <libsbp/new/gnss.h>

#ifdef __cplusplus
extern "C" {
#endif

bool encode_sbp_sbp_gnss_signal_t(sbp_encode_ctx_t *ctx,
                                  const sbp_sbp_gnss_signal_t *msg);
bool decode_sbp_sbp_gnss_signal_t(sbp_decode_ctx_t *ctx,
                                  sbp_sbp_gnss_signal_t *msg);

bool encode_sbp_sv_id_t(sbp_encode_ctx_t *ctx, const sbp_sv_id_t *msg);
bool decode_sbp_sv_id_t(sbp_decode_ctx_t *ctx, sbp_sv_id_t *msg);

bool encode_sbp_gnss_signal_dep_t(sbp_encode_ctx_t *ctx,
                                  const sbp_gnss_signal_dep_t *msg);
bool decode_sbp_gnss_signal_dep_t(sbp_decode_ctx_t *ctx,
                                  sbp_gnss_signal_dep_t *msg);

bool encode_sbp_gps_time_dep_t(sbp_encode_ctx_t *ctx,
                               const sbp_gps_time_dep_t *msg);
bool decode_sbp_gps_time_dep_t(sbp_decode_ctx_t *ctx, sbp_gps_time_dep_t *msg);

bool encode_sbp_gps_time_sec_t(sbp_encode_ctx_t *ctx,
                               const sbp_gps_time_sec_t *msg);
bool decode_sbp_gps_time_sec_t(sbp_decode_ctx_t *ctx, sbp_gps_time_sec_t *msg);

bool encode_sbp_sbp_gps_time_t(sbp_encode_ctx_t *ctx,
                               const sbp_sbp_gps_time_t *msg);
bool decode_sbp_sbp_gps_time_t(sbp_decode_ctx_t *ctx, sbp_sbp_gps_time_t *msg);

bool encode_sbp_carrier_phase_t(sbp_encode_ctx_t *ctx,
                                const sbp_carrier_phase_t *msg);
bool decode_sbp_carrier_phase_t(sbp_decode_ctx_t *ctx,
                                sbp_carrier_phase_t *msg);

#ifdef __cplusplus
}
#endif

#endif
